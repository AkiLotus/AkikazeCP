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
i64 n, m, ans = 0, lastNEq = -1; vi s1, s2;

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
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m; s1.resize(n); s2 = s1;
	for (i64 i=0; i<n; i++) cin >> s1[i];
	for (i64 i=0; i<n; i++) cin >> s2[i];
}

void ProSolve() {
	for (i64 i=0; i<n; i++) {
		if (s1[i] != 0 && s2[i] != 0) {
			if (s1[i] == s2[i]) continue;
			if (s1[i] > s2[i]) ans = (ans + modPow(modPow(m, lastNEq+1), MOD-2)) % MOD;
			break;
		}
		if (s1[i] == 0 && s2[i] == 0) ans = (ans + (((m*(m-1)/2) % MOD) * modPow(modPow(m, lastNEq+3), MOD-2)) % MOD) % MOD;
		else if (s1[i] == 0) ans = (ans + (((m - s2[i]) % MOD) * modPow(modPow(m, lastNEq+2), MOD-2))) % MOD;
		else if (s2[i] == 0) ans = (ans + (((s1[i] - 1) % MOD) * modPow(modPow(m, lastNEq+2), MOD-2))) % MOD;
		lastNEq = i;
	}
	cout << ans;
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