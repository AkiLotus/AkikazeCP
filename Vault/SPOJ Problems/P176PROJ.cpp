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
i64 n, m; vi a, l, r, prod;
vi prime(1, 2); i64 primeCnt;
vector<vi> p;

/** -----EXTENSIVE FUNCTIONS----- **/
i64 modPow(i64 a, i64 b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	i64 tmp = modPow(a, b/2);
	if (b % 2 == 0) return ((tmp * tmp) % MOD);
	return ((((tmp * tmp) % MOD) * a) % MOD);
}

bool isPrime(i64 z) {
	for (i64 i=2; i<=sqrt(z); i++) {
		if (z % i == 0) return false;
	}
	return true;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n; a.resize(n);
	for (i64 i=0; i<n; i++) cin >> a[i];
	cin >> m; l.resize(m); r.resize(m);
	for (i64 i=0; i<m; i++) cin >> l[i] >> r[i];
}

void ProSolve() {
	for (i64 i=3; i<1000; i+=2) {
		if (isPrime(i)) prime.pub(i);
	}
	primeCnt = prime.size(); p.resize(n+1, vi(primeCnt, 0));
	for (i64 i=1; i<=n; i++) {
		for (i64 j=0; j<primeCnt; j++) {
			while (a[i-1] % prime[j] == 0) {
				a[i-1] /= prime[j]; p[i][j]++;
			}
		}
		cout << "a[" << i-1 << "] = " << a[i-1] << endl;
	}
	for (i64 i=1; i<=n; i++) {
		for (i64 j=0; j<primeCnt; j++) {
			p[i][j] += p[i-1][j];
		}
	}
	prod.resize(n+1, 1);
	for (i64 i=1; i<=n; i++) prod[i] = (prod[i-1] * max(a[i-1] - 1, 1LL)) % MOD;
//	for (i64 i=0; i<=n; i++) {
//		for (i64 j=0; j<primeCnt; j++) {
//			cout << p[i][j] << " ";
//		}
//		cout << endl << endl;
//	}
//	cout << "  "; for (i64 i=0; i<n; i++) cout << a[i] << " "; cout << endl;
//	for (i64 i=0; i<=n; i++) cout << prod[i] << " "; cout << endl;
	for (i64 i=0; i<m; i++) {
		i64 phi = 1;
		for (i64 j=0; j<primeCnt; j++) {
			i64 expo = p[r[i]][j] - p[l[i]-1][j];
			cout << "expo of " << prime[j] << " = " << p[r[i]][j] - p[l[i]-1][j] << "\n";
			if (expo == 0) continue;
			phi = (phi * ((modPow(prime[j], expo-1) * (prime[j] - 1)) % MOD)) % MOD;
			//cout << "phi = " << phi << endl;
		}
		phi = (((phi * prod[r[i]]) % MOD) * modPow(prod[l[i]-1], MOD-2)) % MOD;
		cout << phi << endl;
	}
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