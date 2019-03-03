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


/** -----EXTENSIVE FUNCTIONS----- **/
i64 n; vi c, d;
i64 ans = -4*LINF, maxAns = 4*LINF;
bool ansAvail = false;

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n; c.resize(n); d = c;
	for (i64 i=0; i<n; i++) {
		cin >> c[i] >> d[i]; maxAns += c[i];
	}
}

void ProSolve() {
	#ifdef Akikaze
	auto TIME1 = chrono::steady_clock::now();
	#endif
	i64 lwr = -4*LINF, upr = 4*LINF;
	while (lwr < upr) {
		i64 mid = (lwr + upr);
		if ((lwr + upr) % 2 != 0) mid--;
		mid /= 2;
		//tracker3(lwr, upr, mid);
		i64 curr = mid;
		bool flag = true;
		bool div1violenced = false, div2violenced = false;
		for (i64 i=0; i<n; i++) {
			if (curr >= 1900 && d[i] == 2) {
				flag = false; div2violenced = true; break;
			}
			if (curr < 1900 && d[i] == 1) {
				flag = false; div1violenced = true; break;
			}
			curr += c[i];
		}
		if (flag) {
			lwr = mid + 1; ansAvail = true; ans = curr;
		}
		else {
			if (div1violenced) lwr = mid + 1;
			else if (div2violenced) upr = mid;
		}
	}
	i64 curr = lwr; bool flag = true;
	for (i64 i=0; i<n; i++) {
		if (curr >= 1900 && d[i] == 2) {flag = false; break;}
		if (curr < 1900 && d[i] == 1) {flag = false; break;}
		curr += c[i];
	}
	if (flag) {ans = curr; ansAvail = true;}
	if (!ansAvail) cout << "Impossible";
	else if (ans >= maxAns) cout << "Infinity";
	else cout << ans;
	#ifdef Akikaze
	auto TIME2 = chrono::steady_clock::now();
	auto DIFF = TIME2 - TIME1;
	cout << "\n\nTime elapsed: " << chrono::duration<double>(DIFF).count() << " seconds.";
	#endif
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}