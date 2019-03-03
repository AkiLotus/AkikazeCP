/**
	Template by Akikaze (秋風) - formerly proptit_4t41.
	Code written by a random fan of momocashew and Chiho.
	
	H△G x Mili - November 27th, 2013
	Mag Mell (Mili) - Sep 17th, 2014
	H△G x Mili Vol.2 - May 9th, 2015
	Miracle Milk (Mili) - Oct 12th, 2016
	青色フィルム (H△G) - February 14th, 2018
	Millennium Mother (Mili) - April 25th, 2018
**/

/** -----PRAGMA----- **/
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define endl '\n'
#define i64 long long
#define ld long double
#define pub push_back
#define mp make_pair
#define fi first
#define se second
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/


/** -----GLOBAL VARIABLES----- **/
i64 n, m; vector<vector<pip>> adj;
vb vis; vector<ppi> edges; vi dp;

/** -----EXTENSIVE FUNCTIONS----- **/
void DFS(i64 z, i64 cnt, i64 st) {
	vis[z] = true;
	i64 x = edges[z].fi.se;
	i64 weight = edges[z].se;
	i64 i = lower_bound(adj[x].begin(), adj[x].end(), mp(z+1, mp(0LL, 0LL))) - adj[x].begin();
	bool flag = false;
	for (; i<adj[x].size(); i++) {
		i64 X = adj[x][i].fi;
		if (vis[X]) {dp[z] = max(dp[z], dp[X]+1); continue;}
		i64 Weight = adj[x][i].se.se;
		if (Weight > weight) {
			DFS(X, cnt+1, st);
			dp[z] = max(dp[z], dp[X] + 1);
		}
	}
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m; adj.resize(n+1); vis.resize(m, false);
	edges.resize(m); dp.resize(m, 1);
	for (i64 i=0; i<m; i++) {
		i64 a, b, w; cin >> a >> b >> w;
		adj[a].pub(mp(i, mp(b, w)));
		edges[i] = mp(mp(a, b), w);
	}
}

void ProSolve() {
	for (i64 i=0; i<m; i++) {
		if (!vis[i]) {DFS(i, 1, i);}
	}
	//cout << dp << endl;
	cout << *max_element(dp.begin(), dp.end());
}

/** -----MAIN FUNCTION----- **/
int main() {
			#ifdef Akikaze
			//freopen("FILE.INP", "r", stdin);
			//freopen("FILE.OUT", "w", stdout);
			#endif
	VarInput();
			#ifdef Akikaze
			auto TIME1 = chrono::steady_clock::now();
			#endif
	ProSolve();
			#ifdef Akikaze
			auto TIME2 = chrono::steady_clock::now();
			auto DIFF = TIME2 - TIME1;
			cout << "\n\nTime elapsed: " << fixed << setprecision(18) << chrono::duration<double>(DIFF).count() << " seconds.";
			#endif
	return 0;
}