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
i64 n, m, h; vi u; map<pii, i64> Map;
vector<vi> adj, SCClist;
i64 SCCcnt = 0, Time = 0;
vi Lowest, Enum; stack<i64> S;

/** -----EXTENSIVE FUNCTIONS----- **/
void traverse(i64 z) {
	Lowest[z] = ++Time; Enum[z] = Time; S.push(z);
	for (i64 i=0; i<adj[z].size(); i++) {
		if (Enum[adj[z][i]] != 0) Lowest[z] = min(Lowest[z], Lowest[adj[z][i]]);
		else {
			traverse(adj[z][i]);
			Lowest[z] = min(Lowest[z], Lowest[adj[z][i]]);
		}
	}
 
	if (Enum[z] == Lowest[z]) {
		i64 t; SCClist.pub(vi(0));
		do {
			t = S.top(); S.pop(); SCClist[SCCcnt].pub(t);
			Lowest[t] = LINF; Enum[t] = LINF;
		}
		while (z != t); SCCcnt++;
	}
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m >> h; u.resize(n); adj.resize(n, vi(0));
	for (i64 i=0; i<n; i++) cin >> u[i];
	while (m--) {
		i64 x, y; cin >> x >> y; x--; y--;
		if (Map[mp(x,y)]) continue;
		Map[mp(x,y)]++;
		if ((u[x] + 1) % h == u[y]) adj[x].pub(y);
		if ((u[y] + 1) % h == u[x]) adj[y].pub(x);
	}
}

void ProSolve() {
	Lowest.resize(n, 0); Enum = Lowest;
	for (i64 i=0; i<n; i++) {
		if (Lowest[i] == 0) traverse(i);
	}
	i64 lowestIndex = 0, lowest = SCClist[0].size();
	for (i64 i=1; i<SCCcnt; i++) {
		bool flag = true;
		for (i64 j=0; j<SCClist[i].size(); j++) {
			if (!adj[SCClist[i][j]].empty()) {
				flag = false; break;
			}
		}
		if (SCClist[i].size() < lowest && flag) {
			lowestIndex = i;
			lowest = SCClist[i].size();
		}
	}
	cout << lowest << endl;
	for (i64 i=0; i<SCClist[lowestIndex].size(); i++) cout << (SCClist[lowestIndex][i]+1) << " ";
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