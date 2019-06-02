/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: CFGR3C.cpp
// Time created: Sat Jun 01 2019 14:20

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

char infile[] = "FILE.IN";
char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int n; vector<int> p;
vector<pair<int, int>> Result;
/************************************************/

/************** [FUNCTIONS] **************/
void performSwap(int i, int j) {
	if (i > j) swap(i, j);
	if (j - i >= n / 2) {Result.push_back({i, j}); return;}
	if (j < n / 2) {
		Result.push_back({j, n-1});
		Result.push_back({i, n-1});
		Result.push_back({j, n-1});
		return;
	}
	if (i >= n / 2) {
		Result.push_back({0, i});
		Result.push_back({0, j});
		Result.push_back({0, i});
		return;
	}
	Result.push_back({i, n-1});
	Result.push_back({0, j});
	Result.push_back({0, n-1});
	Result.push_back({0, j});
	Result.push_back({i, n-1});
}

void DFS(int z, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &List) {
	vis[z] = true; List.push_back(z);
	for (auto t: adj[z]) {
		if (!vis[t]) DFS(t, vis, adj, List);
	}
}

void Input() {
	cin >> n; p.resize(n);
	for (auto &z: p) {cin >> z; z--;}
}

void Solve() {
	vector<vector<int>> adj(n);
	for (int i=0; i<n; i++) {
		if (p[i] == i) continue;
		adj[i].push_back(p[i]);
	}
	vector<bool> vis(n, false);
	for (int i=0; i<n; i++) {
		if (vis[i]) continue;
		vector<int> List; DFS(i, vis, adj, List);
		if (List.size() == 1) continue;
		for (int x=List.size()-1; x>0; x--) {
			int y = (x + 1) % List.size();
			performSwap(List[x], List[y]);
		}
	}
	cout << Result.size() << endl;
	for (auto P: Result) cout << (P.first + 1) << " " << (P.second + 1) << endl;
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	#ifdef Akikaze
		cout << "Source code by #Team4T-Akikaze.\n";
		cout << "Input: " << ((OImode) ? infile : "stdin");
		cout << " | Output: " << ((OImode) ? outfile : "stdout") << endl << endl;
		cout << "MultiTest-Mode: " << ((MultiTest) ? "ON\n" : "OFF\n");
		cout << "Interactive-Mode: " << ((Interactive) ? "ON\n\n" : "OFF\n\n");
	#else
		if (OImode) {
			freopen(infile, "r", stdin);
			freopen(outfile, "w", stdout);
		}
	#endif
	
	ios_base::sync_with_stdio(false);
	if (!Interactive) cin.tie(NULL);
	
	int T = 1; if (MultiTest) cin >> T;
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/