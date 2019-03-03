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
i64 p, q, ans = -1; vb isPrime(10000001, true);
vi priCnt(10000001, 0), palCnt(10000001, 0);

/** -----EXTENSIVE FUNCTIONS----- **/
bool isPalin(i64 z) {
	i64 res = 0, ser = z;
	while (z > 0) {
		res = res * 10 + z % 10;
		z /= 10;
	}
	return (res == ser);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	isPrime[0] = false; isPrime[1] = false;
	for (i64 i=2; i<10000001; i++) {
		if (isPrime[i]) {
			for (i64 j=2; j<=10000000/i; j++) isPrime[i*j] = false;
		}
	}
	cin >> p >> q;
}

void ProSolve() {
	for (i64 i=1; i<10000001; i++) {
		priCnt[i] = priCnt[i-1]; palCnt[i] = palCnt[i-1];
		if (isPrime[i]) priCnt[i]++;
		if (isPalin(i)) palCnt[i]++;
		if (priCnt[i] * q <= palCnt[i] * p) ans = i;
	}
	if (ans == -1) cout << "Palindromic tree is better than splay tree";
	else cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}