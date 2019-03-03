/**
	Template by Akikaze (秋風) - formerly proptit_4t41.
	Code written by a random fan of momocashew and Chiho.
**/

#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define endl '\n'
#define i64 long long
#define ld long double
#define pub push_back
#define mp make_pair
#define fi first
#define se second
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/


/** -----GLOBAL VARIABLES----- **/
i64 n, c; vi a, treeMin(444444), treeSum(444444);

/** -----EXTENSIVE FUNCTIONS----- **/
void STbuild(i64 node, i64 st, i64 en) {
	if (st > en) return;
	if (st == en) {
		treeMin[node] = a[st];
		treeSum[node] = a[st];
		return;
	}
	STbuild(node*2, st, (st+en)/2);
	STbuild(node*2+1, (st+en)/2+1, en);
	treeMin[node] = min(treeMin[node*2], treeMin[node*2+1]);
	treeSum[node] = treeSum[node*2] + treeSum[node*2+1];
}

i64 getMin(i64 node, i64 st, i64 en, i64 L, i64 R) {
	if (st > en || en < L || R < st) return LINF;
	if (L <= st && en <= R) return treeMin[node];
	i64 p1 = getMin(node*2, st, (st+en)/2, L, R);
	i64 p2 = getMin(node*2+1, (st+en)/2+1, en, L, R);
	return (min(p1, p2));
}

i64 getSum(i64 node, i64 st, i64 en, i64 L, i64 R) {
	if (st > en || en < L || R < st) return 0;
	if (L <= st && en <= R) return treeSum[node];
	i64 p1 = getSum(node*2, st, (st+en)/2, L, R);
	i64 p2 = getSum(node*2+1, (st+en)/2+1, en, L, R);
	return (p1 + p2);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> c; a.resize(n+1);
	for (i64 i=1; i<=n; i++) cin >> a[i];
}

void ProSolve() {
	STbuild(1, 1, n); vi dp(n+1, LINF); dp[0] = 0;
//	for (i64 i=1; i<=n-c+1; i++) cout << getSum(1, 1, n, i, i+c-1) << " "; cout << endl;
//	for (i64 i=1; i<=n-c+1; i++) cout << getMin(1, 1, n, i, i+c-1) << " "; cout << endl;
	for (i64 i=1; i<=n; i++) {
		dp[i] = min(dp[i], dp[i-1] + a[i]);
		if (i >= c) dp[i] = min(dp[i], dp[i-c] + getSum(1, 1, n, i-c+1, i) - getMin(1, 1, n, i-c+1, i));
	}
//	cout << dp << endl;
	cout << dp[n];
}

/** -----MAIN FUNCTION----- **/
int main() {
			#ifdef Akikaze
			//freopen("FILE.INP", "r", stdin);
			//freopen("FILE.OUT", "w", stdout);
			#endif
	VarInput();
			#ifdef Akikaze
			auto TIME1 = chrono::steady_clock::now();
			#endif
	ProSolve();
			#ifdef Akikaze
			auto TIME2 = chrono::steady_clock::now();
			auto DIFF = TIME2 - TIME1;
			cout << "\n\nTime elapsed: " << fixed << setprecision(18) << chrono::duration<double>(DIFF).count() << " seconds.";
			#endif
	return 0;
}