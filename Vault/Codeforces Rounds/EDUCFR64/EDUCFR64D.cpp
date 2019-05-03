/********************************************************
*||  Code written by Akikaze                          ||*
*||  Duy-Bach Le, #Team4T's Chief Executor            ||*
*||  #Team4T Tertiary Flagship - Oblivion             ||*
*||                                                   ||*
*||  Written by a random fan of momocashew and Chiho  ||*
********************************************************/

/***********************************************
** File name: EDUCFR64D.cpp
** Time created: Wed May 01 2019 13:58
***********************************************/

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

void ConfigMonitor();
char infile[] = "FILE.IN";
char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int n; vector<vector<pair<int, int>>> Edge(2);
vector<vector<int>> adj;
vector<int> DSUpar, DSUsize;
/************************************************/

/************** [FUNCTIONS] **************/
int DSUfind(int x) {
	while (DSUpar[x] != -1) x = DSUpar[x];
	return x;
}

void DSUmerge(int x, int y) {
	x = DSUfind(x); y = DSUfind(y);
	if (x == y) return;
	if (DSUsize[x] < DSUsize[y]) swap(x, y);
	DSUsize[x] += DSUsize[y]; DSUpar[y] = x;
}

void DFS(int z, vector<bool> &vis, int &shiro, int &kuro) {
	shiro++; vis[z] = true;
	kuro += DSUsize[DSUfind(z)] - 1;
	for (auto t: adj[z]) {
		if (vis[t]) continue;
		DFS(t, vis, shiro, kuro);
	}
}

void Input() {
	cin >> n; adj.resize(n);
	DSUpar.resize(n, -1); DSUsize.resize(n, +1);
	for (int i=1; i<n; i++) {
		int u, v, t; cin >> u >> v >> t;
		u--; v--;
		Edge[t].push_back({u, v});
		if (t == 1) DSUmerge(u, v);
	}
}

void Solve() {
	for (auto Pair: Edge[0]) {
		int u = Pair.first, v = Pair.second;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	i64 ans = 0; vector<bool> vis(n, false);
	for (int i=0; i<n; i++) {
		if (vis[i]) continue;
		int shiro = 0, kuro = 0;
		DFS(i, vis, shiro, kuro);
		ans += (1LL * shiro * (shiro - 1));
		ans += (1LL * shiro * kuro);
	}
	cout << ans << endl;
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	ConfigMonitor();
	ios_base::sync_with_stdio(false);
	if (!Interactive) cin.tie(NULL);
	
	int T = 1; if (MultiTest) cin >> T;
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/

/************** [MASTER CONTROLS - PHASE 2] **************/
void ConfigMonitor() {
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
}
/*********************************************************/