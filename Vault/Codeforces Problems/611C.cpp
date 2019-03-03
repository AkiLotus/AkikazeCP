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
i64 h, w, q; vvi dp1, dp2;
vector<vector<char>> inp;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> h >> w; dp1.resize(h, vi(w, 0)); dp2.resize(h, vi(w, 0));
	inp.resize(h, vector<char>(w));
	for (i64 i=0; i<h; i++) {
		for (i64 j=0; j<w; j++) cin >> inp[i][j];
	}
	for (i64 i=0; i<h; i++) {
		for (i64 j=1; j<w; j++) {
			if (i > 0) dp1[i][j] = dp1[i-1][j] + dp1[i][j-1] - dp1[i-1][j-1];
			else dp1[i][j] = dp1[i][j-1];
			if (inp[i][j-1] == '.' && inp[i][j] == '.') dp1[i][j]++;
		}
	}
	for (i64 i=1; i<h; i++) {
		for (i64 j=0; j<w; j++) {
			if (j > 0) dp2[i][j] = dp2[i-1][j] + dp2[i][j-1] - dp2[i-1][j-1];
			else dp2[i][j] = dp2[i-1][j];
			if (inp[i-1][j] == '.' && inp[i][j] == '.') dp2[i][j]++;
		}
	}
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	cin >> q;
	while (q--) {
		i64 r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
		r1--; c1--; r2--; c2--;
		i64 ans = dp1[r2][c2] + dp2[r2][c2];
		if (r1 > 0) ans -= dp1[r1-1][c2];
		ans -= dp1[r2][c1];
		if (r1 > 0) ans += dp1[r1-1][c1];
		ans -= dp2[r1][c2];
		if (c1 > 0) ans -= dp2[r2][c1-1];
		if (c1 > 0) ans += dp2[r1][c1-1];
		cout << ans << endl;
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
