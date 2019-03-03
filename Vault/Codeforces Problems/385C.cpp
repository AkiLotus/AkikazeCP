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
i64 n, m, l, r; vi x, cnt(10000001, 0), prime, cc, prefixsum;
vb isPrime(10000001, true);

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	for (i64 i=2; i<10000001; i++) {
		if (isPrime[i]) {
			prime.pub(i);
			for (i64 j=2; j<=10000000/i; j++) isPrime[i*j] = false;
		}
	}
	cin >> n; x.resize(n); cc.resize(prime.size(), 0); prefixsum = cc;
	for (i64 i=0; i<n; i++) {
		cin >> x[i]; cnt[x[i]]++;
	}
	for (i64 i=0; i<cc.size(); i++) {
		for (i64 j=1; j<=10000000/prime[i]; j++) cc[i] += cnt[prime[i]*j];
		if (i == 0) prefixsum[i] = cc[i];
		else prefixsum[i] = prefixsum[i-1] + cc[i];
	}
}

void ProSolve() {
	cin >> m;
	while (m--) {
		cin >> l >> r;
		i64 st = lower_bound(prime.begin(), prime.end(), l) - prime.begin() - 1;
		i64 en = upper_bound(prime.begin(), prime.end(), r) - prime.begin() - 1;
		if (st < 0) cout << prefixsum[en] << endl;
		else cout << prefixsum[en] - prefixsum[st] << endl;
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}