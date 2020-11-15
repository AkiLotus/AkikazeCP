/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: K.cpp
// Time created: Sun Nov 15 2020 01:14

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
int MultiTest = 1;
int Interactive = 0;

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int n; vector<vector<pair<int, int>>> adj;
int least_different = INF;
/************************************************/

/************** [FUNCTIONS] **************/
pair<i64, i64> best_answer(int z, int last) {
	// cout << z << " " << last << endl;
	i64 local_best = 0;
	multiset<i64> locals;
	multiset<i64> root_spear;
	vector<pair<i64, i64>> best_children;
	for (auto token: adj[z]) {
		int t = token.first, length = token.second;
		// cout << "considering: " << t << " " << length << endl;
		if (last == t) continue;
		pair<i64, i64> best_child = best_answer(t, z);
		local_best = max(local_best, best_child.first);
		locals.
		root_spear.insert(best_child.second + length);
		best_children.push_back(best_child);
	}

	for (int i=0; i<adj[z].size(); i++) {
		int t = adj[z][i].first, length = adj[z][i].second;
		int child_spear = best_children[i].second + length;
	}

	while (root_spear.size() > 2) root_spear.erase(root_spear.begin());
	if (root_spear.size() == 2) {
		i64 tmp = *root_spear.begin();
		root_spear.erase(root_spear.begin());
		tmp += *root_spear.begin();
		local_best = max(local_best, tmp);
	}
	i64 best_spear = 0;
	if (root_spear.size() == 1) best_spear = *root_spear.begin();
	return make_pair(local_best, best_spear);
}

void Input() {
	cin >> n; adj.clear(); adj.resize(n);
	least_different = INF;
	if (n == 0) exit(0);
	for (int u=1; u<n; u++) {
		int v, w; cin >> v >> w; v--;
		adj[u].push_back(make_pair(v, w)); adj[v].push_back(make_pair(u, w));
	}
}

void Solve() {
	best_answer(0, -1);
	cout << least_different << endl;
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
	
	while(true) {Input(); Solve();}
	
	return 0;
}
/************************************/