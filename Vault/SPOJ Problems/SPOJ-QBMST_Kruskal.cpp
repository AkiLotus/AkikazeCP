/**
	Template by proptit_4t41
	Applied for C++11/C++14
	Add -std=c++14 to your IDE.
**/

/**
	// code written by a random fan of momocashew
	// world.execute(me);
**/

/**
	To make it compatible to C++98,
	remove all tuple typedefs, unordered
	sets/maps/multisets/multimaps, and add
	a space between two '<'/'>'s when declaring
	multi-dimensional vectors (to avoid ambiguity).
**/

#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define endl '\n'
#define i64 long long
#define u64 unsigned long long
#define ld long double
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mmap multimap
#define mset multiset
#define umap unordered_map
#define uset unordered_set
#define ummap unordered_multimap
#define umset unordered_multiset
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define REcheck cout << "RE here?\n"
#define tracker1(i) cout << "working at " << i << endl;
#define tracker2(i,j) cout << "working at " << i << "-" << j << endl;
#define tracker3(i,j,k) cout << "working at " << i << "-" << j << "-" << k << endl;
const long double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
const long long MOD = 1000000007LL;
const long long INF = 1e9;
const long long LINF = 1e18;
const long double EPS = 1e-9;
const long double GOLD = ((1+sqrt(5))/2);
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/// MAIN SOLUTION STARTS HERE

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
//int T, cas = 0; // for multi-testcase problems
i64 n, m, ans = 0; vector<pip> edge;
vector<i64> chosen, parent, siz;

/** -----EXTENSIVE FUNCTIONS----- **/
i64 DSUfind(i64 z) {
	while (parent[z] != z) z = parent[z];
	return parent[z];
}

void DSUmerge(i64 a, i64 b) {
	i64 x = DSUfind(a), y = DSUfind(b);
	if (x == y) return;
	if (siz[x] < siz[y]) {
		parent[x] = y;
		siz[y] += siz[x];
	}
	else {
		parent[y] = x;
		siz[x] += siz[y];
	}
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> n >> m; edge.resize(m, mp(0LL, mp(0LL, 0LL)));
	chosen.resize(m, false);
	parent.resize(n+1); siz.resize(n+1, 1LL);
	for (i64 i=1; i<=n; i++) parent[i] = i;
	for (i64 i=0; i<m; i++) {
		i64 a, b, c; cin >> a >> b >> c;
		edge[i] = mp(c, mp(a,b));
	}
	sort(edge.begin(), edge.end());
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	for (i64 i=0; i<m; i++) {
		pip tmp = edge[i];
		i64 x = tmp.se.fi, y = tmp.se.se;
		if (DSUfind(x) != DSUfind(y)) {
			DSUmerge(x, y); ans += tmp.fi;
		}
	}
	cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
