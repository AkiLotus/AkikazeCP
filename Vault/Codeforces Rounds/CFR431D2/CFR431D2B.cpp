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
i64 n; map<pip, i64> Map;
vi a; vp others; pip sample;

/** -----EXTENSIVE FUNCTIONS----- **/

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> n; a.resize(n);
	for (i64 i=0; i<n; i++) {
		cin >> a[i]; a[i] -= a[0];
		if (i == 0) continue;
		i64 Q = a[i] / i, M = a[i] % i, D = i;
		i64 gcd = __gcd(M, D); M /= gcd; D /= gcd;
		pip z = mp(Q, mp(M, D));
		if (i == 1) {sample = z; continue;}
		if (z != sample) others.pub(mp(i, a[i]));
	}
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	if (others.size() < 3) {cout << "Yes"; return;}
	i64 Q = (others[1].se - others[0].se) / (others[1].fi - others[0].fi);
	i64 M = (others[1].se - others[0].se) % (others[1].fi - others[0].fi);
	i64 D =  others[1].fi - others[0].fi;
	i64 gcd = __gcd(M, D); M /= gcd; D /= gcd;
	for (i64 i=2; i<others.size(); i++) {
		REcheck;
		i64 q = (others[i].se - others[i-1].se) / (others[i].fi - others[i-1].fi);
		i64 m = (others[i].se - others[i-1].se) % (others[i].fi - others[i-1].fi);
		i64 d =  others[i].fi - others[i-1].fi; gcd = __gcd(m, d); m /= gcd; d /= gcd;
		if (Q != q || M != m || D != d) {cout << "No"; return;}
	}
	cout << "Yes";
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
