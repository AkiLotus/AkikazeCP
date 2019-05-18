/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: TREETRIP.cpp
// Time created: Sun May 12 2019 06:52

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
int n, a, b; vector<vector<pair<int, int>>> adj;
vector<vector<i64>> dp;
/************************************************/

/************** [FUNCTIONS] **************/
void DFS(int z, int last) {
	int children = 0; i64 totalMinCost = 0;
	priority_queue<i64, vector<i64>, greater<i64>> Edge_MinHeap;

	for (auto Token: adj[z]) {
		int t = Token.first, d = Token.second;
		if (t == last) continue;
		children++; DFS(t, z);
		Edge_MinHeap.push(dp[1][t] + 1LL * d * a - b - min(dp[0][t], dp[1][t]));
		totalMinCost += min(dp[0][t], dp[1][t]);
	}
	
	dp[1][z] = totalMinCost + 1LL * b * children;

	for (auto Token: adj[z]) {
		int t = Token.first, d = Token.second;
		if (t == last) continue;
		dp[1][z] = min(dp[1][z], (totalMinCost - min(dp[0][t], dp[1][t]) + dp[1][t] + 1LL * a * d) + 1LL * b * (children - 1));
	}
	
	if (children > 1) {
		dp[0][z] = totalMinCost + 1LL * b * children;
		dp[0][z] += Edge_MinHeap.top(); Edge_MinHeap.pop();
		dp[0][z] += Edge_MinHeap.top(); Edge_MinHeap.pop();
	}
}

void Input() {
	cin >> n >> a >> b; adj.resize(n);
	dp.resize(2, vector<i64>(n, LLONG_MAX));
	for (int i=1; i<n; i++) {
		int u, v, w; cin >> u >> v >> w; u--; v--;
		adj[u].push_back({v, w}); adj[v].push_back({u, w});
	}
}

void Solve() {
	if (n == 2) {cout << min(1LL * b, 1LL * a * adj[0][0].second) * 2 << endl; return;}
	DFS(0, -1);
	cout << min(dp[0][0], dp[1][0]) + b << endl;
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