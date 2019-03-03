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
pii x, y;

/** -----EXTENSIVE FUNCTIONS----- **/
bool higher(pii x, pii y) {
	i64 lcm = x.se * y.se / __gcd(x.se, y.se);
	x.fi *= (lcm / x.se); x.se = lcm;
	y.fi *= (lcm / y.se); y.se = lcm;
	return (x.fi > y.fi);
}

pii subtract(pii x, pii y) {
	i64 lcm = x.se * y.se / __gcd(x.se, y.se);
	x.fi *= (lcm / x.se); x.se = lcm;
	y.fi *= (lcm / y.se); y.se = lcm;
	pii ans = mp(x.fi-y.fi, lcm);
	i64 gcd = __gcd(ans.fi, ans.se);
	ans.fi /= gcd; ans.se /= gcd;
	return ans;
}

pii divide(pii x, pii y) {
	pii ans = mp(x.fi*y.se, x.se*y.fi);
	i64 gcd = __gcd(ans.fi, ans.se);
	ans.fi /= gcd; ans.se /= gcd;
	return ans;
}

pii invert(pii x) {
	return mp(x.se, x.fi);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> x.fi >> x.se >> y.fi >> y.se;
	if (__gcd(x.fi,x.se) > 1) {
		i64 z = __gcd(x.fi,x.se);
		x.fi /= z; x.se /= z;
	}
	if (__gcd(y.fi,y.se) > 1) {
		i64 z = __gcd(y.fi,y.se);
		y.fi /= z; y.se /= z;
	}
}

void ProSolve() {
	pii ans = mp(0, 1);
	if (higher(x, y)) ans = divide(subtract(x,y), x);
	else if (higher(y, x)) ans = divide(subtract(invert(x),invert(y)), invert(x));
	cout << ans.fi << "/" << ans.se;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}