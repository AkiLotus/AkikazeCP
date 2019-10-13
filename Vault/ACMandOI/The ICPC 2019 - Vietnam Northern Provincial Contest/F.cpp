/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: F.cpp
// Time created: Sun Oct 13 2019 01:46

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
struct edge {
	int u, v; i64 w;
	edge() {}
	edge(int u_, int v_, i64 w_) {u = u_; v = v_; w = w_;}
};

int n, m; vector<edge> E;
i64 dist[300][300][601];
i64 cost[300][300];
vector<vector<int>> adj;
/************************************************/

/************** [FUNCTIONS] **************/
bool edgesort(edge a, edge b) {
	return (a.w > b.w);
}

void Input() {
	for (int i=0; i<300; i++) {
		for (int j=0; j<300; j++) {
			cost[i][j] = LINF;
			for (int k=0; k<601; k++) {
				dist[i][j][k] = LINF;
			}
		}
	}
	cin >> n >> m; adj.resize(n);
	E.resize(m);
	for (auto &e: E) {
		int u, v; i64 c; cin >> u >> v >> c; u--; v--;
		e = edge(u, v, c);
	}
}

void Solve() {
	sort(E.begin(), E.end(), edgesort);
	for (auto e: E) {
		int u = e.u, v = e.v;
		i64 w = e.w;
		adj[u].push_back(v);
		adj[v].push_back(u);
		vector<pair<pair<int, int>, int>> Q;
		int Front = 0;
		Q.push_back({{min(u, v), max(u, v)}, 1});
		dist[min(u, v)][max(u, v)][1] = w;
		cost[min(u, v)][max(u, v)] = min(cost[min(u, v)][max(u, v)], w);
		while (Front < Q.size()) {
			pair<pair<int, int>, int> Token = Q[Front]; Front++;
			int x1 = Token.first.first, x2 = Token.first.second, k = Token.second;
			if (k == 2*n) continue;
			for (auto y2: adj[x2]) {
				i64 tmp = dist[min(x1, y2)][max(x1, y2)][k+1];
				dist[min(x1, y2)][max(x1, y2)][k+1] = w;
				cost[min(x1, y2)][max(x1, y2)] = min(cost[min(x1, y2)][max(x1, y2)], w * (k + 1));
				if (w < tmp) Q.push_back({{min(x1, y2), max(x1, y2)}, k+1});
			}
			for (auto y1: adj[x1]) {
				i64 tmp = dist[min(y1, x2)][max(y1, x2)][k+1];
				dist[min(y1, x2)][max(y1, x2)][k+1] = w;
				cost[min(y1, x2)][max(y1, x2)] = min(cost[min(y1, x2)][max(y1, x2)], w * (k + 1));
				if (w < tmp) Q.push_back({{min(y1, x2), max(y1, x2)}, k+1});
			}
		}
	}
	bool surpassed = false;
	i64 S = 0;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			if (cost[i][j] == LINF) continue;
			if (!surpassed && S + cost[i][j] >= INF) surpassed = true;
			S += cost[i][j]; S %= INF;
		}
	}
	if (!surpassed) cout << S << endl;
	else {
		string SStr = to_string(S);
		int tmp = SStr.size();
		SStr.insert(0, 9 - tmp, '0');
		cout << SStr << endl;
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