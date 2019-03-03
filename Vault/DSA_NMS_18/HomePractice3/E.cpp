/**
    Template by Akikaze (秋風) - formerly proptit_4t41.
    Code written by a random fan of momocashew and Chiho.
     
    H△G x Mili - November 27th, 2013
    Mag Mell (Mili) - Sep 17th, 2014
    H△G x Mili Vol.2 - May 9th, 2015
    Miracle Milk (Mili) - Oct 12th, 2016
    青色フィルム (H△G) - February 14th, 2018
    Millennium Mother (Mili) - April 25th, 2018
**/
 
/** -----PRAGMA----- **/
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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
        u = a^2 + b^2
        v = a^2*b^2
 
        u = F2 - c^2
        u^2 - 2v = F4 - c^4
 
        => x = a || x = b, provided x^2 - ux + v = 0 (Viète's theorem).
    -------------------------- **/
 
/** -----CUSTOM TYPEDEFS/DEFINES----- **/
 typedef pair<ld, ld> pdd;
 
/** -----GLOBAL VARIABLES----- **/
i64 T, F2, F3, F4, L, R, a, b, c;
 
/** -----EXTENSIVE FUNCTIONS----- **/
i64 modPow(i64 a, i64 b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    i64 tmp = modPow(a, b/2);
    if (b % 2 == 0) return ((tmp * tmp) % MOD);
    return ((((tmp * tmp) % MOD) * a) % MOD);
}
 
vi solveQuadratic(i64 x, i64 y, i64 z) {
    vd res(2);
    i64 delta = y*y - 4*x*z;
    if (delta < 0) return vi(0);
    res[0] = ((ld)-y - sqrt((ld)delta)) / (2 * x);
    res[1] = ((ld)-y + sqrt((ld)delta)) / (2 * x);
    sort(res.begin(), res.end()); vi resInt(2);
    for (i64 i=0; i<2; i++) resInt[i] = round(res[i]);
    if (abs(round(res[0]) - res[0]) >= EPS || abs(round(res[1]) - res[1]) >= EPS) return vi(0);
    return resInt;
}

bool isSquare(i64 z) {
	i64 zazz = sqrt(z);
	return (zazz * zazz == z);
}
 
/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> T;
}
 
void ProSolve() {
    while (T--) {
        i64 F2, F3, F4, L, R; cin >> F2 >> F3 >> F4 >> L >> R;
        if (L > R) {cout << "0\n"; continue;}
        bool flag = false;
        for (c=min(15000LL, (i64)sqrt(F2)); c>2; c--) {
            i64 u = F2 - c*c, v = (u*u - (F4 - c*c*c*c)) / 2;
			vi zazz = solveQuadratic(1LL, -u, v);
			if (zazz.size() == 2) {
				a = zazz[0]; b = zazz[1];
				if (0 < a && a < b && b < c*c && isSquare(a) && isSquare(b)) {
					a = sqrt(a); b = sqrt(b);
					if (a*a+b*b+c*c == F2 && a*a*a+b*b*b+c*c*c == F3 && a*a*a*a+b*b*b*b+c*c*c*c == F4) {flag = true; break;}
				}
			}
        }
        //cout << "a = " << a << " | b = " << b << " | c = " << c << endl;
        i64 ans1 = ((((modPow(a, R-L+1) - 1) * modPow(a, L)) % MOD) * modPow(a-1, MOD-2)) % MOD;
        if (a == 1) ans1 = (R-L+1) % MOD; while (ans1 < 0) ans1 += MOD;
        //cout << "ans1 = " << ans1 << endl;
        i64 ans2 = ((((modPow(b, R-L+1) - 1) * modPow(b, L)) % MOD) * modPow(b-1, MOD-2)) % MOD;
        if (b == 1) ans2 = (R-L+1) % MOD; while (ans2 < 0) ans2 += MOD;
        //cout << "ans2 = " << ans2 << endl;
        i64 ans3 = ((((modPow(c, R-L+1) - 1) * modPow(c, L)) % MOD) * modPow(c-1, MOD-2)) % MOD;
        if (c == 1) ans3 = (R-L+1) % MOD; while (ans3 < 0) ans3 += MOD;
        //cout << "ans3 = " << ans3 << endl;
        cout << ((ans1 + ans2 + ans3) % MOD) << endl;
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