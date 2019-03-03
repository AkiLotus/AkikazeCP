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
i64 N, M, K, T; vb vis;
vector<vector<pii>> adjInA, adjOutA, adjInB, adjOutB;

/** -----GLOBAL VARIABLES----- **/


/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> N >> M >> K >> T; K--;
	adjInA.resize(N, vector<pii>(0)); adjOutA = adjInA;
	adjInB = adjInA; adjOutB = adjInB;
	vis.resize(N, false);
	while (M--) {
		i64 u, v, a, b; cin >> u >> v >> a >> b; u--; v--;
		adjOutA[u].pub(mp(v, a)); adjInA[v].pub(mp(u, a));
		adjOutB[u].pub(mp(v, b)); adjInB[v].pub(mp(u, b));
	}
}

void ProSolve() {
	vi dist1(N, LINF), distK(N, LINF), distN(N, LINF);
	dist1[0] = 0; distK[K] = 0; distN[N-1] = 0;
	priority_queue<pii> heap; heap.push(mp(0LL, 0LL));
	while (!heap.empty()) {
		pii z = heap.top(); heap.pop();
		if (vis[z.se]) continue;
		vis[z.se] = true;
		for (i64 i=0; i<adjOutB[z.se].size(); i++) {
			pii x = adjOutB[z.se][i];
			if (dist1[z.se] + x.se < dist1[x.fi]) {
				dist1[x.fi] = dist1[z.se] + x.se;
				heap.push(mp(-dist1[x.fi], x.fi));
			}
		}
	}
	for (i64 i=0; i<N; i++) vis[i] = false; heap.push(mp(0LL, K));
	while (!heap.empty()) {
		pii z = heap.top(); heap.pop();
		if (vis[z.se]) continue;
		vis[z.se] = true;
		for (i64 i=0; i<adjInA[z.se].size(); i++) {
			pii x = adjInA[z.se][i];
			if (distK[z.se] + x.se < distK[x.fi]) {
				distK[x.fi] = distK[z.se] + x.se;
				heap.push(mp(-distK[x.fi], x.fi));
			}
		}
	}
	for (i64 i=0; i<N; i++) vis[i] = false; heap.push(mp(0LL, N-1));
	while (!heap.empty()) {
		pii z = heap.top(); heap.pop();
		if (vis[z.se]) continue;
		vis[z.se] = true;
		for (i64 i=0; i<adjInB[z.se].size(); i++) {
			pii x = adjInB[z.se][i];
			if (distN[z.se] + x.se < distN[x.fi]) {
				distN[x.fi] = distN[z.se] + x.se;
				heap.push(mp(-distN[x.se], x.fi));
			}
		}
	}
	i64 ans = LINF;
	for (i64 i=0; i<N; i++) {
		if (dist1[i] + distK[i] > T) continue;
		ans = min(ans, dist1[i] + distN[i]);
	}
	cout << ans;
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