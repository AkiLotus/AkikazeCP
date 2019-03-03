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
i64 a, b, p, x, ans = 0; vi expa;
map<i64, i64> M;

/** -----EXTENSIVE FUNCTIONS----- **/
i64 modPow(i64 m, i64 n, i64 mod) {
	if (n == 0) return 1;
	if (n == 1) return (m % mod);
	i64 tmp = modPow(m, n/2, mod);
	if (n % 2 == 0) return ((tmp * tmp) % mod);
	return ((((tmp * tmp) % mod) * m) % mod);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> a >> b >> p >> x;
}

void ProSolve() {
	i64 len = x / p;
	for (i64 i=1; i<p; i++) {
		i64 required = ((b * modPow(modPow(a, i, p), p-2, p)) % p);
		required = (i - required) % p; while (required < 0) required += p;
		//cout << "required = " << required << endl;
		i64 mn = required * (p - 1) + i; while (mn > p * (p + 1)) mn -= p * (p - 1);
		i64 mx = ((i64)x / (p*(p-1))) * (p*(p-1)) + mn; while (mx > x) mx -= p * (p - 1);
		//cout << mn << " " << mx << endl;
		ans += max((mx-mn)/(p*(p-1))+1, 0LL);
	}
	cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}