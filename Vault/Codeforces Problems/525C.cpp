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
i64 n, cnt = 0, area = 1, ans = 0; vi cc(1000007, 0);

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n;
	while (n--) {
		i64 x; cin >> x;
		cc[x]++;
	}
}

void ProSolve() {
	for (i64 i=1000006; i>0; i--) {
		if (cc[i] >= 4) {
			if (cnt == 1) {
				cc[i] -= 2;
				area *= i; ans += area;
				area = 1; cnt = 0;
			}
			ans += i * i * ((i64)cc[i] / 4);
			cc[i] %= 4;
		}
		if (cc[i] == 2) {
			area *= i; cnt++;
		}
		else if (cc[i] == 3) {
			area *= i; cnt++;
			if (cc[i-1] > 0) cc[i-1]++;
		}
		else if (cc[i] == 1) {
			if (cc[i-1] > 0) cc[i-1]++;
		}
		if (cnt == 2) {
			cnt = 0; ans += area;
			area = 1;
		}
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