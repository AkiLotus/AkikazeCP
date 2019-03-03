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
i64 n, m, ans = 0; vector<vector<pii> > adj, AdjMST;
vector<i64> chosen; priority_queue<pip> Q;
stack<i64> handle; vi cnt(400000, 0); vb vis;

/** -----EXTENSIVE FUNCTIONS----- **/
void DFS_MST(i64 z, i64 last, i64 weight) {
	vis[z] = true; handle.push(1LL);
	for (i64 i=0; i<AdjMST[z].size(); i++) {
		pii x = AdjMST[z][i];
		if (vis[x.fi]) continue;
		DFS_MST(x.fi, z, x.se);
	}
	i64 tmp = handle.top(); handle.pop();
	vis[z] = false; cnt[weight] += tmp * (n - tmp);
	//cout << "Increase " << weight << " by " << tmp * (n - tmp) << endl;
	if (last != -1 && !handle.empty()) handle.top() += tmp;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m; adj.resize(n+1, vector<pii>(0));
	chosen.resize(n+1, false); AdjMST.resize(n+1);
	Q.push(mp(-1LL, mp(-1LL, 1LL)));
	while (m--) {
		i64 a, b, c; cin >> a >> b >> c;
		adj[a].pub(mp(b,c)); adj[b].pub(mp(a,c));
	}
}

void ProSolve() {
	while (!Q.empty()) {
		i64 a = Q.top().se.fi, z = Q.top().se.se;
		i64 tmp = Q.top().fi; Q.pop();
		if (chosen[z]) continue;
		if (a != -1) {
			AdjMST[a].pub(mp(z, -tmp));
			AdjMST[z].pub(mp(a, -tmp));
		}
		chosen[z] = true;
		for (i64 i=0; i<adj[z].size(); i++) {
			pii zz = adj[z][i];
			if (chosen[zz.fi]) continue;
			Q.push(mp(-zz.se, mp(z, zz.fi)));
		}
	}
	//cout << AdjMST << endl;
	vis.resize(n+1, false); DFS_MST(1, -1, -1);
	for (i64 i=0; i<399999; i++) {
		cnt[i+1] += (cnt[i] / 2); cnt[i] %= 2;
	}
	//for (i64 i=0; i<10; i++) cout << cnt[i]; cout << endl;
	i64 flag = false;
	for (i64 i=399999; i>=0; i--) {
		if (cnt[i]) flag = true;
		if (flag) cout << cnt[i];
	}
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