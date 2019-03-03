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
typedef pair<ld, ld> pdd;

/** -----GLOBAL VARIABLES----- **/
i64 R, x1, y1, x2, y2;

/** -----EXTENSIVE FUNCTIONS----- **/
pdd makeVctr(i64 x1, i64 y1, i64 x2, i64 y2) {
	pii res = mp(x2-x1, y2-y1);
	if (res.fi != 0 || res.se != 0) {
		i64 GCD = gcd(res.fi, res.se);
		res.fi /= GCD; res.se /= GCD;
	}
	ld a = res.fi, b = res.se;
	return mp(a, b);
}

pdd negative(pdd z) {
	return mp(-z.fi, -z.se);
}

pdd findPoint(pdd st_pts, pdd vctr, ld dist) {
	if (x1 == x2 && y1 == y2) vctr = mp(1.0, 1.0);
	ld vctrLen = sqrt(vctr.fi * vctr.fi + vctr.se * vctr.se);
	ld mul = dist / vctrLen;
	return mp(st_pts.fi + vctr.fi*mul, st_pts.se + vctr.se*mul);
}

pdd midPoint(pdd pt1, pdd pt2) {
	return mp((pt1.fi+pt2.fi)/2, (pt1.se+pt2.se)/2);
}

ld segDist(pdd pt1, pdd pt2) {
	return (sqrt((pt2.fi-pt1.fi)*(pt2.fi-pt1.fi) + (pt2.se-pt1.se)*(pt2.se-pt1.se)));
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> R >> x1 >> y1 >> x2 >> y2;
}

void ProSolve() {
	i64 sqrDist = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	ld r = R, X1 = x1, Y1 = y1, X2 = x2, Y2 = y2;
	if (sqrDist >= R * R) {
		cout << fixed << setprecision(12) << X1 << " " << Y1 << " " << r; return;
	}
	pdd vctr1 = makeVctr(x1, y1, x2, y2);
	pdd vctr2 = negative(vctr1);
	pdd point = findPoint(mp(X1, Y1), vctr2, r);
	pdd wifiPos = midPoint(point, mp(X2, Y2));
	ld wifiR = segDist(point, mp(X2, Y2)) / 2;
	cout << fixed << setprecision(12) << wifiPos.fi << " " << wifiPos.se << " " << wifiR;
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
			cout << "\n\nTime elapsed: " << chrono::duration<double>(DIFF).count() << " seconds.";
			#endif
	return 0;
}