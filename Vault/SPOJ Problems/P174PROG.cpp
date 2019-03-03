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
i64 Q; map<pii, i64> w;

/** -----EXTENSIVE FUNCTIONS----- **/
void add(i64 u, i64 v, i64 x) {
	while (u != v) {
		if (u > v) {
			i64 tmp = u;
			u = v; v = tmp;
		}
		w[mp(v, v/2)] += x; w[mp(v/2, v)] += x;
		v /= 2;
	}
}

i64 get(i64 u, i64 v) {
	i64 res = 0;
	while (u != v) {
		if (u > v) {
			i64 tmp = u;
			u = v; v = tmp;
		}
		res += w[mp(v, v/2)];
		v /= 2;
	}
	return res;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> Q;
}

void ProSolve() {
	while (Q--) {
		i64 cmd, u, v;
		cin >> cmd >> u >> v;
		if (cmd == 1) {
			i64 x; cin >> x;
			add(u, v, x);
		}
		else {
			cout << get(u, v) << endl;
		}
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}