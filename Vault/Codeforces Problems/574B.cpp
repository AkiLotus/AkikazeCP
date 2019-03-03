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
typedef pair<short, short> pss;

/** -----GLOBAL VARIABLES----- **/
//int T, cas = 0; // for multi-testcase problems
short n, m, tmp = 0, ans = 32767; vector<vector<short>> adj;
vector<pss> edge; map<pss, bool> M;

/** -----EXTENSIVE FUNCTIONS----- **/

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> n >> m; adj.resize(n+1, vector<short>(0));
	edge.resize(m+1);
	for (short i=1; i<=m; i++) {
		cin >> edge[i].fi >> edge[i].se;
		adj[edge[i].fi].pub(edge[i].se); adj[edge[i].se].pub(edge[i].fi);
		M[mp(edge[i].fi,edge[i].se)] = true;
		M[mp(edge[i].se,edge[i].fi)] = true;
	}
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	for (short i=1; i<=m; i++) {
		for (short j=i+1; j<=m; j++) {
			short a = edge[i].fi, b = edge[i].se;
			short c = edge[j].fi, d = edge[j].se;
			if (b == c && M[mp(a,d)]) {
				ans = min(ans, (short)((short)(adj[a].size()+adj[b].size()+adj[d].size())-6)); continue;
			}
			if (b == d && M[mp(a,c)]) {
				ans = min(ans, (short)((short)(adj[a].size()+adj[b].size()+adj[c].size())-6)); continue;
			}
			if (a == c && M[mp(b,d)]) {
				ans = min(ans, (short)((short)(adj[a].size()+adj[b].size()+adj[d].size())-6)); continue;
			}
			if (a == d && M[mp(b,c)]) {
				ans = min(ans, (short)((short)(adj[a].size()+adj[b].size()+adj[c].size())-6)); continue;
			}
		}
	}
	if (ans == 32767) cout << "-1";
	else cout << ans;
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
