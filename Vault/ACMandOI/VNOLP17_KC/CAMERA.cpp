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
	Planned to achieve 100% of the tests.
    -------------------------- **/

/// MAIN SOLUTION STARTS HERE

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
//int T, cas = 0; // for multi-testcase problems
i64 n; vector<i64> h; string d;
vector<i64> maximumfromRight;
vector<i64> maximumfromLeft;
vector<i64> lastR, lastL;
vector<i64> dpR, dpL;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> n; h.resize(n);
	maximumfromRight.resize(n, -1); maximumfromRight[n-1] = n-1;
	maximumfromLeft.resize(n, -1); maximumfromLeft[0] = 0;
	dpR.resize(n, 1); dpL.resize(n, 1);
	lastR.resize(n, 1); lastL.resize(n, 1);
	lastR[n-1] = n-1; lastL[0] = 0;
	for (i64 i=0; i<n; i++) cin >> h[i];
	cin >> d;
	for (i64 i=n-2; i>=0; i--) {
		if (h[i] > h[maximumfromRight[i+1]]) {
			maximumfromRight[i] = i;
		}
		else maximumfromRight[i] = maximumfromRight[i+1];
		if (maximumfromRight[i] == i) dpR[i] = 1;
		else dpR[i] = dpR[lastR[maximumfromRight[i]]] + 1;
		lastR[maximumfromRight[i]] = i;
	}
	for (i64 i=1; i<n; i++) {
		if (h[i] > h[maximumfromLeft[i-1]]) {
			maximumfromLeft[i] = i;
		}
		else maximumfromLeft[i] = maximumfromLeft[i-1];
		if (maximumfromLeft[i] == i) dpL[i] = 1;
		else dpL[i] = dpL[lastL[maximumfromLeft[i]]] + 1;
		lastL[maximumfromLeft[i]] = i;
	}
	for (i64 i=0; i<n; i++) cout << maximumfromLeft[i] << " "; cout << endl;
	for (i64 i=0; i<n; i++) cout << maximumfromRight[i] << " "; cout << endl;
	for (i64 i=0; i<n; i++) cout << dpL[i] << " "; cout << endl;
	for (i64 i=0; i<n; i++) cout << dpR[i] << " "; cout << endl;
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	for (i64 i=0; i<n; i++) {
		i64 ans = 0;
		if ((d[i] == 'E' && i == n-1) || (d[i] == 'W' && i == 0)) cout << "0 ";
		else if (d[i] == 'E') cout << dpR[i+1] << " ";
		else cout << dpL[i-1] << " ";
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
