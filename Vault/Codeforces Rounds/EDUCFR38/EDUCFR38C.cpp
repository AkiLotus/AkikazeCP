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
i64 T, x;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> T;
}

void ProSolve() {
	while (T--) {
		cin >> x;
		if (x == 0) {cout << "1 1\n"; continue;}
		bool flag = false;
		for (i64 i=1; i<=sqrt(x); i++) {
			if (x % i != 0) continue;
			if (x / i == i) break;
			i64 j = x / i;
			//cout << i << " " << j << endl;
			if ((j - i) % 2 == 0) {
				i64 diff = (j - i) / 2;
				i64 a = i + diff;
				i64 rem = a * a - x;
				i64 tmp = sqrt(rem);
				if (tmp * tmp != rem) continue;
				i64 l = 1, r = a;
				while (l < r) {
					i64 mid = (l + r) / 2;
					if (a / mid < tmp) r = mid;
					else if (a / mid > tmp) l = mid+1;
					else {
						l = mid; r = mid;
					}
				}
				if (a / l != tmp) continue;
				cout << a << " " << l << endl;
				flag = true; break;
			}
		}
		if (!flag) {cout << "-1\n";}
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}