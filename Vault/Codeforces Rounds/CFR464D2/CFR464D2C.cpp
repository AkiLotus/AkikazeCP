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
i64 n, s, f; vi a, sum;
i64 opt = -LINF, ans = LINF;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n; a.resize(n, 0); sum = a;
	for (i64 i=0; i<n; i++) {
		cin >> a[i];
		if (i == 0) sum[i] = a[i];
		else sum[i] = sum[i-1] + a[i];
	}
	cin >> s >> f;
}

void ProSolve() {
	i64 st = (s - 1), fi = (f - 2);
	i64 tmp = sum[fi];
	if (st > 0) tmp -= sum[st-1];
	for (i64 i=0; i<n; i++) {
		//tracker1(i);
		//cout << st << " " << fi << endl;
		//cout << "tmp = " << tmp << endl;
		if (tmp >= opt) {
			i64 z2 = n + 1 - i;
			while (z2 > n) z2 -= n;
			//cout << "z2 = " << z2 << endl;
			if (tmp > opt) {
				opt = tmp; ans = z2;
			}
			else ans = min(ans, z2);
			//cout << "opt = " << opt << endl;
			//cout << "ans = " << ans << endl;
		}
		tmp -= a[st]; tmp += a[(fi+1)%n];
		st = (st + 1) % n; fi = (fi + 1) % n;
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