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
string str; i64 n;
vector<i64> power10(1000007, 1);
vector<i64> sum(1000007, 0);

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> str; n = str.size();
	for (i64 i=1; i<1000007; i++) {
		power10[i] = (power10[i-1] * 10) % MOD;
	}
	sum[0] = str[0] - '0';
	for (i64 i=1; i<n; i++) {
		sum[i] = (sum[i-1] * 10 + (str[i] - '0')) % MOD;
	}
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	for (i64 i=n/3; i<=n/2; i++) {
		for (i64 j=-1; j<1; j++) {
			i64 x = i+j, z = i, y = n - x - z;
			if (x == 0 || y == 0 || z == 0) continue;
			i64 tmp1 = sum[x-1], tmp2 = sum[x+y-1] - (sum[x-1] * power10[y]) % MOD, tmp3 = sum[n-1] - (sum[n-z-1] * power10[z]) % MOD;
			while (tmp2 < 0) tmp2 += MOD; while (tmp3 < 0) tmp3 += MOD;
			if ((x == 1 || (x != 1 && str[0] != '0')) && (y == 1 || (str[x] != '0' && y != 1)) && (z == 1 || (str[x+y] != '0' && z != 1))) {
				if ((tmp1 + tmp2) % MOD == tmp3) {
					for (i64 i=0; i<x; i++) cout << str[i]; cout << "+";
					for (i64 i=x; i<x+y; i++) cout << str[i]; cout << "=";
					for (i64 i=x+y; i<n; i++) cout << str[i]; return;
				}
			}
			tmp1 = sum[y-1], tmp2 = sum[x+y-1] - (sum[y-1] * power10[x]) % MOD, tmp3 = sum[n-1] - (sum[n-z-1] * power10[z]) % MOD;
			while (tmp2 < 0) tmp2 += MOD; while (tmp3 < 0) tmp3 += MOD;
			if ((y == 1 || (y != 1 && str[0] != '0')) && (x == 1 || (str[y] != '0' && x != 1)) && (z == 1 || (str[x+y] != '0' && z != 1))) {
				if ((tmp1 + tmp2) % MOD == tmp3) {
					for (i64 i=0; i<y; i++) cout << str[i]; cout << "+";
					for (i64 i=y; i<x+y; i++) cout << str[i]; cout << "=";
					for (i64 i=x+y; i<n; i++) cout << str[i]; return;
				}
			}
		}
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
