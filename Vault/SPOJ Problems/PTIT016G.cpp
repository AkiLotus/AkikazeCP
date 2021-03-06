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
i64 n, k, M; vi c;
vb isPrime(2000007, true);
vi cnt(2000007, 0);

/** -----EXTENSIVE FUNCTIONS----- **/
void EratosthenesSieve() {
	isPrime[0] = false; isPrime[1] = false;
	for (i64 i=2; i<2000007; i++) {
		if (isPrime[i]) {
			for (i64 j=2; j<=2000006/i; j++) {
				isPrime[i*j] = false;
			}
		}
	}
}

i64 modPow(i64 a, i64 b, i64 Mod) {
	if (b == 0) return (1 % Mod);
	if (b == 1) return (a % Mod);
	i64 tmp = modPow(a, b/2, Mod);
	if (b % 2 == 0) return ((tmp * tmp) % Mod);
	return ((((tmp * tmp) % Mod) * a) % Mod);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> k >> M; c.resize(k);
	for (i64 i=0; i<k; i++) cin >> c[i];
}

void ProSolve() {
	EratosthenesSieve();
	for (i64 i=0; i<k; i++) n -= c[i];
	if (n < 0) {cout << "0"; return;}
	if (n == 0) {cout << "1"; return;}
	if (k - 1 >= n) {
		for (i64 i=k; i<=n+k-1; i++) {
			i64 tmp = i;
			for (i64 j=2; j<=sqrt(tmp); j++) {
				while (tmp % j == 0) {
					tmp /= j; cnt[j]++;
				}
				if (isPrime[tmp]) break;
			}
			if (tmp != 0) cnt[tmp]++;
		}
		for (i64 i=1; i<=n; i++) {
			i64 tmp = i;
			for (i64 j=2; j<=sqrt(tmp); j++) {
				while (tmp % j == 0) {
					tmp /= j; cnt[j]--;
				}
			}
			if (tmp != 0) cnt[tmp]--;
		}
	}
	else {
		for (i64 i=n+1; i<=n+k-1; i++) {
			i64 tmp = i;
			for (i64 j=2; j<=sqrt(tmp); j++) {
				while (tmp % j == 0) {
					tmp /= j; cnt[j]++;
				}
				if (isPrime[tmp]) break;
			}
			if (tmp != 0) cnt[tmp]++;
		}
		for (i64 i=1; i<=k-1; i++) {
			i64 tmp = i;
			for (i64 j=2; j<=sqrt(tmp); j++) {
				while (tmp % j == 0) {
					tmp /= j; cnt[j]--;
				}
			}
			if (tmp != 0) cnt[tmp]--;
		}
	}
	i64 ans = 1;
	for (i64 i=2; i<2000007; i++) {
		ans = (ans * modPow(i, cnt[i], M)) % M;
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