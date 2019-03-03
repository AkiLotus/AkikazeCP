/**
	Template by proptit_4t41
	Applied for C++11/C++14 (Add -std=c++14 to your IDE.)
	To make it compatible to C++98, remove all tuple typedefs,
	unordered sets/maps/multisets/multimaps, and add a space
	between two '<'/'>'s when declaring multi-dimensional vectors.
**/

/**
	Code written by a random fan of momocashew and Chiho
	ProPTIT_Akikaze (あきかぜ - 秋風)
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
i64 n; vp e; vi c; vvi adj; vb visited;

/** -----EXTENSIVE FUNCTIONS----- **/
bool DFS(i64 z, i64 col) {
	visited[z] = true;
	for (i64 i=0; i<adj[z].size(); i++) {
		if (visited[adj[z][i]]) continue;
		if (c[adj[z][i]] != col) return false;
		if (!DFS(adj[z][i], col)) return false;
	}
	return true;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> n;
	e.resize(n-1); c.resize(n+1);
	adj.resize(n+1, vi(0)); visited.resize(n+1, false);
	for (i64 i=0; i<n-1; i++) {
		cin >> e[i].fi >> e[i].se;
		adj[e[i].fi].pub(e[i].se);
		adj[e[i].se].pub(e[i].fi);
	}
	for (i64 i=1; i<=n; i++) cin >> c[i];
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	for (i64 i=0; i<n-1; i++) {
		if (c[e[i].fi] == c[e[i].se]) continue;
		bool valid = true;
		for (i64 x=1; x<=n; x++) visited[x] = false; visited[e[i].fi] = true;
		for (i64 j=0; j<adj[e[i].fi].size(); j++) {
			//cout << "DFS(" << adj[e[i].fi][j] << ", " << c[adj[e[i].fi][j]] << ") = " << DFS(adj[e[i].fi][j], c[adj[e[i].fi][j]]) << endl;
			if (!DFS(adj[e[i].fi][j], c[adj[e[i].fi][j]])) {
				valid = false; break;
			}
		}
		if (valid) {
			cout << "YES\n" << e[i].fi; return;
		}
		valid = true;
		for (i64 x=1; x<=n; x++) visited[x] = false; visited[e[i].se] = true;
		for (i64 j=0; j<adj[e[i].se].size(); j++) {
			//cout << "DFS(" << adj[e[i].se][j] << ", " << c[adj[e[i].se][j]] << ") = " << DFS(adj[e[i].se][j], c[adj[e[i].se][j]]) << endl;
			if (!DFS(adj[e[i].se][j], c[adj[e[i].se][j]])) {
				valid = false; break;
			}
		}
		if (valid) {
			cout << "YES\n" << e[i].se; return;
		}
		cout << "NO"; return;
	}
	cout << "YES\n1";
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
