/**
	Template by proptit_4t41
	Applied for C++11/C++14 (Add -std=c++14 to your IDE.)
	To make it compatible to C++98, remove all tuple typedefs,
	unordered sets/maps/multisets/multimaps, and add a space
	between two '<'/'>'s when declaring multi-dimensional vectors.
**/

/**
	code written by a random fan of momocashew
	world.execute(me);
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
typedef vector<i64> vi;
typedef stack<i64> si;
typedef queue<i64> qi;
typedef vector<vector<i64>> vvi;
typedef vector<ld> vd;
typedef vector<vector<ld>> vvd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;
typedef vector<pii> vp;

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
i64 n, m, scc = 0, ans = 0, sol = 1;
vvi adj1, adj2; vi cost; vb visited;
vvi components; vi mincost; si s;

/** -----EXTENSIVE FUNCTIONS----- **/
void firstDFS(i64 z) {
	visited[z] = true;
	for (i64 i=0; i<adj1[z].size(); i++) {
		if (!visited[adj1[z][i]]) firstDFS(adj1[z][i]);
	}
	s.push(z);
}

void secondDFS(i64 z) {
	visited[z] = true; components[scc-1].pub(z);
	mincost[scc-1] = min(mincost[scc-1], cost[z]);
	for (i64 i=0; i<adj2[z].size(); i++) {
		if (!visited[adj2[z][i]]) secondDFS(adj2[z][i]);
	}
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> n; cost.resize(n+1);
	for (i64 i=1; i<=n; i++) cin >> cost[i];
	adj1.resize(n+1, vi(0)); adj2.resize(n+1, vi(0));
	visited.resize(n+1, false);
	cin >> m;
	while (m--) {
		i64 a, b; cin >> a >> b;
		adj1[a].pub(b); adj2[b].pub(a);
	}
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	for (i64 i=1; i<=n; i++) {
		if (!visited[i]) firstDFS(i);
	}
	for (i64 i=1; i<=n; i++) visited[i] = false;
	while (!s.empty()) {
		i64 z = s.top(); s.pop();
		if (!visited[z]) {
			components.pub(vi(0)); mincost.pub(LINF);
			scc++; secondDFS(z);
		}
	}
	for (i64 i=0; i<scc; i++) {
		//cout << mincost[i] << endl;
		ans += mincost[i]; i64 tmp = 0;
		for (i64 j=0; j<components[i].size(); j++) {
			if (cost[components[i][j]] == mincost[i]) tmp++;
		}
		sol = (sol * tmp) % MOD;
	}
	cout << ans << " " << sol;
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
