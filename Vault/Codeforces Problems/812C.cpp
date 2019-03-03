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
i64 n, S; vector<pii> a;
i64 k = 0, T = 0;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n >> S; a.resize(n);
	for (i64 i=0; i<n; i++) {
		cin >> a[i].fi; a[i].se = i+1;
	}
}

void ProSolve() {
	i64 l = 0, r = n;
	while (l <= r) {
		i64 mid = (l + r) / 2;
		priority_queue<i64, vi, greater<i64>> heap;
		for (i64 i=0; i<n; i++) heap.push(a[i].fi+a[i].se*mid);
		i64 tmp = 0;
		for (i64 i=0; i<mid; i++) {
			tmp += heap.top(); heap.pop();
		}
		if (tmp == S) {
			k = mid; T = tmp; break;
		}
		else if (tmp < S) {
			k = mid; T = tmp;
			l = mid + 1;
		}
		else {
			if (l == r) break;
			r = mid;
		}
	}
	cout << k << " " << T;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}