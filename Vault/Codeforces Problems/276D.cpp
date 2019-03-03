/**
	Template by Akikaze (秋風) - formerly proptit_4t41.
	Applied for C++11/C++14 (Add -std=c++14 to your IDE.)
	Code written by a random fan of momocashew and Chiho.
**/

#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define endl '\n'
#define i64 long long
#define u64 unsigned long long
#define ld long double
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mmap multimap
#define mset multiset
#define mp make_pair
#define fi first
#define se second
#define dout(x,y) cout << fixed << setprecision(x) << y << endl;
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.14159265358979323846264338327950288419716939937510582097494459230, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
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

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
i64 l, r, x = 0, y = 0; vi a(64, 0), b(64, 0);

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> l >> r;
}

void ProSolve() {
	i64 tmpa = l, tmpb = r;
	while (tmpa > 0) {
		a[x] = tmpa % 2;
		tmpa /= 2; x++;
	}
	while (tmpb > 0) {
		b[y] = tmpb % 2;
		tmpb /= 2; y++;
	}
	for (i64 i=63; i>=0; i--) {
		if (a[i] != b[i]) {
			cout << ((2LL << i) - 1);
			return;
		}
	}
	cout << "0";
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}