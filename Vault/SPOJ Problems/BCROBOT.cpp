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
const long long MOD = 2147483647LL;
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
i64 n; vector<vector<char>> Map; vvi dp;
vector<vector<bool>> visited;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> n; Map.resize(n, vector<char>(n, '.'));
	dp.resize(n, vi(n, 0)); visited.resize(n, vb(n, false));
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<n; j++) cin >> Map[i][j];
	}
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	queue<pii> Q; Q.push(mp(0LL, 0LL)); dp[0][0] = 1;
	while (!Q.empty()) {
		pii z = Q.front(); Q.pop();
		if (z.fi+1 < n && Map[z.fi+1][z.se] == '.') {
			if (dp[z.fi+1][z.se] == 0) Q.push(mp(z.fi+1, z.se));
			dp[z.fi+1][z.se] += dp[z.fi][z.se]; dp[z.fi+1][z.se] %= MOD;
		}
		if (z.se+1 < n && Map[z.fi][z.se+1] == '.') {
			if (dp[z.fi][z.se+1] == 0) Q.push(mp(z.fi, z.se+1));
			dp[z.fi][z.se+1] += dp[z.fi][z.se]; dp[z.fi][z.se+1] %= MOD;
		}
	}
	if (dp[n-1][n-1] > 0) {
		cout << dp[n-1][n-1]; return;
	}
	Q.push(mp(0LL, 0LL)); visited[0][0] = true;
	while (!Q.empty()) {
		pii z = Q.front(); Q.pop();
		if (z.fi+1 < n && Map[z.fi+1][z.se] == '.') {
			if (!visited[z.fi+1][z.se]) Q.push(mp(z.fi+1, z.se));
			visited[z.fi+1][z.se] = true;
		}
		if (z.se+1 < n && Map[z.fi][z.se+1] == '.') {
			if (!visited[z.fi][z.se+1]) Q.push(mp(z.fi, z.se+1));
			visited[z.fi][z.se+1] = true;
		}
		if (z.fi-1 >= 0 && Map[z.fi-1][z.se] == '.') {
			if (!visited[z.fi-1][z.se]) Q.push(mp(z.fi-1, z.se));
			visited[z.fi-1][z.se] = true;
		}
		if (z.se-1 >= 0 && Map[z.fi][z.se-1] == '.') {
			if (!visited[z.fi][z.se-1]) Q.push(mp(z.fi, z.se-1));
			visited[z.fi][z.se-1] = true;
		}
	}
	if (visited[n-1][n-1]) cout << "THE GAME IS A LIE";
	else cout << "INCONCEIVABLE";
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
