/**
	Template by proptit_4t41
	Applied for C++11/C++14 (Add -std=c++14 to your IDE.)
	To make it compatible to C++98, remove all tuple typedefs,
	unordered sets/maps/multisets/multimaps, and add a space
	between two '<'/'>'s when declaring multi-dimensional vectors.
**/

/**
	code written by a random fan of momocashew and Chiho
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
i64 n; vvi adj; vi dp, par; vb visited;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> n; adj.resize(n+1, vi(0));
	dp.resize(n+1, 0); par.resize(n+1, 0); visited.resize(n+1, false);
	for (i64 i=1; i<n; i++) {
		i64 a, b; cin >> a >> b;
		adj[a].pub(b); adj[b].pub(a);
	}
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	queue<i64> Q; Q.push(1); visited[1] = true;
	while (!Q.empty()) {
		i64 z = Q.front(); Q.pop();
		for (i64 i=0; i<adj[z].size(); i++) {
			if (!visited[adj[z][i]]) {
				dp[adj[z][i]] = dp[z] + 1; par[adj[z][i]] = z;
				Q.push(adj[z][i]); visited[adj[z][i]] = true;
			}
		}
	}
	vp z(n+1);
	for (i64 i=1; i<=n; i++) {
		z[i].fi = dp[i]; z[i].se = i;
	}
	sort(z.rbegin(), z.rend());
	i64 mx = z[0].fi + z[1].fi;
	i64 root = z[0].se;
	i64 steps = 0;
	while (steps < mx/2) {root = par[root]; steps++;}
	cout << "root = " << root << endl;
	for (i64 i=0; i<=n; i++) {
		par[i] = 0; dp[i] = 0;
		visited[i] = false;
	}
	Q.push(root); visited[root] = true;
	while (!Q.empty()) {
		i64 z = Q.front(); Q.pop();
		for (i64 i=0; i<adj[z].size(); i++) {
			if (!visited[adj[z][i]]) {
				dp[adj[z][i]] = dp[z] + 1; par[adj[z][i]] = z;
				Q.push(adj[z][i]); visited[adj[z][i]] = true;
			}
		}
	}
	mx = *max_element(dp.begin(), dp.end());
	i64 deepestLeaf = max_element(dp.begin(), dp.end()) - dp.begin();
	vector<ppi> ansCmd;
	i64 ans = 0;
	for (i64 i=1; i<=n; i++) {
		if (par[i] != 0 && adj[i].size() == 1 && i != deepestLeaf) {
			i64 tmptmp = dp[i];
			ans += mx * tmptmp;
			ans += dp[i] * (dp[i] + 1) / 2;
			i64 thisLeaf = i;
			while (thisLeaf != root) {
				ansCmd.pub(mp(mp(deepestLeaf, thisLeaf), thisLeaf));
				thisLeaf = par[thisLeaf];
			}
		}
	}
	ans += mx * (mx + 1) / 2;
	while (deepestLeaf != root) {
		ansCmd.pub(mp(mp(deepestLeaf, root), deepestLeaf));
		deepestLeaf = par[deepestLeaf];
	}
	cout << ans << endl;
	for (i64 i=0; i<ansCmd.size(); i++) {
		cout << ansCmd[i].fi.fi << " " << ansCmd[i].fi.se << " " << ansCmd[i].se << endl;
	}
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
