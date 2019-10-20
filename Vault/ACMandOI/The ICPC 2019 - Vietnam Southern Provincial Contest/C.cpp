/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: E.cpp
// Time created: Sun Oct 13 2019 02:40

/************** [OPTIMIZATION PROTOCOL] **************/
#pragma GCC optimize("Ofast")
/*****************************************************/

/************** [LIBRARY PROTOCOL] **************/
#include <bits/stdc++.h>
using namespace std;
/************************************************/

/************** [GNU OMISSIONS] **************/
#define y0 withindarkness
#define y1 apinklotusbloomed
#define yn carryingapurplesoul
#define j1 togetherformingtheTeam
/*********************************************/

/************** [LEGENDS/CONSTANTS] **************/
#define endl '\n'
#define i64 long long
#define ld long double
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116L;
const long double EPS = 0.000000001L, Gold = ((1.0L+sqrt(5.0L))/2.0L);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
/*************************************************/

/************** [MASTER CONTROLS - PHASE 1] **************/
int OImode = 0;
int MultiTest = 0;
int Interactive = 0;

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int n1, m1, n2, m2; vector<set<int>> adj1, adj2;
/************************************************/

/************** [FUNCTIONS] **************/
void DFS(int z, vector<set<int>> &adj, vector<bool> &vis, vector<int> &topo) {
	vis[z] = true;
	for (auto it=adj[z].begin(); it!=adj[z].end(); it++) {
		int t = *it;
		if (vis[t]) continue;
		DFS(t, adj, vis, topo);
	}
	topo.push_back(z);
}

vector<int> perform_toposort(int n, vector<set<int>> &adj) {
	vector<bool> vis(n, false);
	vector<int> topo;
	for (int i=0; i<n; i++) {
		if (!vis[i]) DFS(i, adj, vis, topo);
	}
	return topo;
}

vector<pair<char, int>> getState(int n, vector<set<int>> &adj, vector<int> &topology) {
	vector<pair<char, int>> state(n, make_pair('#', -1));
	for (auto z: topology) {
		int minN = INT_MAX, maxP = INT_MIN;
		for (auto it=adj[z].begin(); it!=adj[z].end(); it++) {
			int t = *it;
			if (state[t].first == 'N') minN = min(minN, state[t].second);
			if (state[t].first == 'P') maxP = max(maxP, state[t].second);
		}
		if (minN != INT_MAX) state[z] = make_pair('P', minN + 1);
		else if (maxP != INT_MIN) state[z] = make_pair('N', maxP + 1);
		else state[z] = make_pair('N', 0);
	}
	return state;
}

void Input() {
	cin >> n1 >> m1; adj1.resize(n1);
	while (m1--) {
		int u, v; cin >> u >> v; u--; v--;
		adj1[u].insert(v);
	}
	cin >> n2 >> m2; adj2.resize(n2);
	while (m2--) {
		int u, v; cin >> u >> v; u--; v--;
		adj2[u].insert(v);
	}
}

void Solve() {
	vector<int> topology_1 = perform_toposort(n1, adj1);
	vector<int> topology_2 = perform_toposort(n2, adj2);

	vector<pair<char, int>> state_1 = getState(n1, adj1, topology_1);
	vector<pair<char, int>> state_2 = getState(n2, adj2, topology_2);

	int T; cin >> T;
	while (T--) {
		int v1, v2; cin >> v1 >> v2; v1--; v2--;
		if (state_1[v1].first == 'P' && state_2[v2].first == 'P') cout << "first\n";
		else if (state_1[v1].first == 'P' && state_2[v2].first == 'N' && state_1[v1].second < state_2[v2].second) cout << "first\n";
		else if (state_1[v1].first == 'N' && state_2[v2].first == 'P' && state_1[v1].second > state_2[v2].second) cout << "first\n";
		else cout << "second\n";
	}
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	#ifndef Akikaze
		if (OImode) {
			assert(freopen(infile, "r", stdin));
			assert(freopen(outfile, "w", stdout));
		}
	#endif
	
	ios_base::sync_with_stdio(false);
	if (!Interactive) cin.tie(NULL);
	
	int T = 1; if (MultiTest) {cin >> T; cin.ignore();}
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/
