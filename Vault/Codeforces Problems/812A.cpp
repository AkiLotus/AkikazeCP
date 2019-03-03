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
vi l(5, 0), r(5, 0), s(5, 0), p(5, 0);

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	for (i64 i=1; i<=4; i++) {
		cin >> l[i] >> s[i] >> r[i] >> p[i];
	}
}

void ProSolve() {
	for (i64 i=1; i<=4; i++) {
		if (p[i] == 1 && (l[i] == 1 || r[i] == 1 || s[i] == 1)) {
			cout << "YES"; return;
		}
	}
	if (l[1] && p[4]) {cout << "YES"; return;}
	if (s[1] && p[3]) {cout << "YES"; return;}
	if (r[1] && p[2]) {cout << "YES"; return;}
	if (l[2] && p[1]) {cout << "YES"; return;}
	if (s[2] && p[4]) {cout << "YES"; return;}
	if (r[2] && p[3]) {cout << "YES"; return;}
	if (l[3] && p[2]) {cout << "YES"; return;}
	if (s[3] && p[1]) {cout << "YES"; return;}
	if (r[3] && p[4]) {cout << "YES"; return;}
	if (l[4] && p[3]) {cout << "YES"; return;}
	if (s[4] && p[2]) {cout << "YES"; return;}
	if (r[4] && p[1]) {cout << "YES"; return;}
	cout << "NO";
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}