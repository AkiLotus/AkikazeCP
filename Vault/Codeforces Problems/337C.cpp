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
const long long MOD = 1000000009LL, INF = 1e9, LINF = 1e18;
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
i64 n, m, k, x, y, q = 0, ans;

/** -----EXTENSIVE FUNCTIONS----- **/
i64 modPow(i64 a, i64 b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	i64 tmp = modPow(a, b/2);
	if (b % 2 == 0) return ((tmp * tmp) % MOD);
	return ((((tmp * tmp) % MOD) * a) % MOD);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n >> m >> k;
}

void ProSolve() {
	y = min(n - m, m);
	if ((m - y * (k - 1)) % k != 0) {q += (m-y*(k-1)) % k; y++;}
	else q = k-1;
	x = max(min((m - y * (k - 1) - q + (k - 1) + 1) / k, m/k), 0LL);
	//cout << "x,y,q = " << x << "," << y << "," << q << endl;
	if (x != 0) ans = (k * (modPow(2, x+1) - 2)) % MOD;
	else {
		cout << m; return;
	}
	while (ans < 0) ans += MOD;
	//cout << ans << endl;
	ans = (ans + y*(k-1)) % MOD;
	ans -= k-1; ans += q; while (ans < 0) ans += MOD;
	cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}