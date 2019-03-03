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
i64 Q; vi g(1000007, 0);
vector<vi> cnt(10, vi(1000007, 0));

/** -----EXTENSIVE FUNCTIONS----- **/
i64 foo(i64 z) {
	i64 res = 1;
	while (z > 0) {
		if (z % 10 != 0) res *= (z % 10);
		z /= 10;
	}
	return res;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	for (i64 i=0; i<10; i++) g[i] = i;
	for (i64 i=10; i<1000007; i++) {
		g[i] = g[foo(i)];
	}
	for (i64 i=1; i<1000007; i++) {
		for (i64 j=0; j<10; j++) {
			cnt[j][i] = cnt[j][i-1] + (g[i] == j);
		}
	}
}

void ProSolve() {
	cin >> Q;
	while (Q--) {
		i64 l, r, k; cin >> l >> r >> k;
		cout << (cnt[k][r] - cnt[k][l-1]) << endl;
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}