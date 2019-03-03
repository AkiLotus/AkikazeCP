/**
	Template by Akikaze (秋風) - formerly proptit_4t41.
	Code written by a random fan of momocashew and Chiho.
**/

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
i64 n, m; vector<set<i64>> adj;
vi cntAdj; vb separate;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m; adj.resize(n); cntAdj.resize(n, 0);
	while (m--) {
		i64 x, y; cin >> x >> y; x--; y--;
		cntAdj[x]++; cntAdj[y]++;
		adj[x].insert(y); adj[y].insert(x);
	}
}

void ProSolve() {
	set<pii> minHeap; separate.resize(n, true); i64 ans = 0;
	for (i64 i=0; i<n; i++) minHeap.insert(mp(cntAdj[i], i));
	while (!minHeap.empty()) {
		pii z = *minHeap.begin(); minHeap.erase(minHeap.begin());
		//tracker2(z.se, adj[z.se].size());
		if (adj[z.se].empty()) continue;
		separate[z.se] = false;
		i64 t = *adj[z.se].begin(); cntAdj[z.se]--; cntAdj[t]--;
		minHeap.erase(mp(cntAdj[z.se]+1, z.se));
		minHeap.erase(mp(cntAdj[t]+1, t)); minHeap.insert(mp(cntAdj[t], t));
		adj[z.se].erase(t); adj[t].erase(z.se);
	}
	for (i64 i=0; i<n; i++) ans += (separate[i]);
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