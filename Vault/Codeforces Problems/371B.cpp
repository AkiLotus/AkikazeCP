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
i64 a, b, ans = 0;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> a >> b;
}

void ProSolve() {
	i64 tmpa = a, tmpb = b, gcd = __gcd(a,b);
	while (tmpa % 2 == 0) tmpa /= 2;
	while (tmpa % 3 == 0) tmpa /= 3;
	while (tmpa % 5 == 0) tmpa /= 5;
	while (tmpb % 2 == 0) tmpb /= 2;
	while (tmpb % 3 == 0) tmpb /= 3;
	while (tmpb % 5 == 0) tmpb /= 5;
	if (tmpa != tmpb) {cout << "-1"; return;}
	i64 proa = a / gcd, prob = b / gcd;
	while (proa % 2 == 0) {proa /= 2; ans++;}
	while (proa % 3 == 0) {proa /= 3; ans++;}
	while (proa % 5 == 0) {proa /= 5; ans++;}
	while (prob % 2 == 0) {prob /= 2; ans++;}
	while (prob % 3 == 0) {prob /= 3; ans++;}
	while (prob % 5 == 0) {prob /= 5; ans++;}
	cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}