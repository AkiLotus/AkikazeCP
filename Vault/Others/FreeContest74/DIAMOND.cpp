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
i64 N, K, mans = 1, dans = INF; vector<pii> a;

/** -----EXTENSIVE FUNCTIONS----- **/
bool cmp(pii a, pii b) {
	ld ad = (ld)a.fi / a.se;
	ld bd = (ld)b.fi / b.se;
	return (ad > bd);
}

void Try_(i64 pos, i64 sa, i64 sb, i64 cnt) {
	if (pos == N-1) {
		if (sa == 0 || cnt != K) return;
		if ((ld)sa/sb > (ld)mans/dans) {
			i64 GCD = __gcd(sa, sb); sa /= GCD; sb /= GCD;
			mans = sa; dans = sb;
		}
		return;
	}
	if (cnt == K) {
		if ((ld)sa/sb > (ld)mans/dans) {
			i64 GCD = __gcd(sa, sb); sa /= GCD; sb /= GCD;
			mans = sa; dans = sb;
		}
		return;
	}
	Try_(pos+1, sa, sb, cnt);
	Try_(pos+1, sa+a[pos+1].fi, sb+a[pos+1].se, cnt+1);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> N >> K; a.resize(N);
	for (i64 i=0; i<N; i++) cin >> a[i].fi >> a[i].se;
}

void ProSolve() {
	if (N <= 30) {
		Try_(0, 0, 0, 0);
		Try_(0, a[0].fi, a[0].se, 1);
		cout << mans << " " << dans;
		return;
	}
	i64 m = 0, d = 0;
	sort(a.begin(), a.end(), cmp);
	for (i64 i=0; i<K; i++) {
		m += a[i].fi; d += a[i].se;
	}
	i64 GCD = __gcd(m, d);
	m /= GCD; d /= GCD;
	cout << m << " " << d;
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