/**
	Template by Akikaze
	Applied for C++11/C++14 (Add -std=c++14 to your IDE.)
	To make it compatible to C++98, remove all tuple typedefs,
	unordered sets/maps/multisets/multimaps, and add a space
	between two '<'/'>'s when declaring multi-dimensional vectors.
**/

/**
	Code written by a random fan of momocashew and Chiho
	Akikaze (あきかぜ - 秋風) - formerly proptit_4t41
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
i64 n, k; vi p; vi D0, D1, finalset;

/** -----EXTENSIVE FUNCTIONS----- **/
void recursive(i64 val, i64 st) {
	if (st % 2 == 0) D0.pub(val); else D1.pub(val);
	for (i64 i=st; i<n; i+=2) {
		ld p1 = log(val), p2 = log(p[i]), p3 = log(4*LINF);
		if (p1 + p2 - p3 > EPS) continue;
		if (val * p[i] <= LINF) recursive(val*p[i], i);
	}
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> n; p.resize(n);
	for (i64 i=0; i<n; i++) cin >> p[i];
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	recursive(1, 0); recursive(1, 1); sort(D0.begin(), D0.end()); sort(D1.begin(), D1.end());
	//cout << D0.size() << " " << D1.size() << endl;
	i64 st = 1, en = LINF, mid = (st+en)/2, ans = -1; bool flag = false; cin >> k;
	while (ans != k || !flag) {
		//tracker3(st,en,mid);
		i64 pt0 = 0, pt1 = D1.size()-1, cnt = 0;
		flag = false; ans = 0;
		while (pt0 < D0.size() && pt1 >= 0) {
			if (D1[pt1] > mid/D0[pt0]) {pt1--; continue;}
			if (D0[pt0] * D1[pt1] == mid) flag = true;
			ans += pt1+1; pt0++;
		}
		//cout << "ans = " << ans << endl;
		//cout << "flag = " << (flag ? "true\n" : "false\n");
		if (ans > k || (ans == k && !flag)) {
			en = mid; mid = (st + en) / 2;
		}
		else if (ans < k) {
			st = mid+1; mid = (st + en) / 2;
		}
	}
	cout << mid;
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