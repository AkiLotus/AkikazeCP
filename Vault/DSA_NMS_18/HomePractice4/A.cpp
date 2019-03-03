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

    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/


/** -----GLOBAL VARIABLES----- **/
i64 T; string p1, p2, removeBuffer;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> T; getline(cin, removeBuffer);
}

void ProSolve() {
	while (T--) {
		getline(cin, p1); getline(cin, p2);
		vector<pii> monomial;
		i64 coef = 0, pow = 0;
		bool flagCo = true, flagPow = false;
		for (i64 i=0; i<=p1.size(); i++) {
			if (i == p1.size() || (i < p1.size() && p1[i] == ' ' && flagPow)) {
				flagPow = false; flagCo = true;
				monomial.pub(mp(pow, coef));
				coef = 0; pow = 0;
			}
			else if (p1[i] >= '0' && p1[i] <= '9') {
				if (flagCo) coef = coef * 10 + (p1[i] - '0');
				if (flagPow) pow = pow * 10 + (p1[i] - '0');
			}
			else if (p1[i] == 'x') {
				flagCo = false; flagPow = true;
			}
		}
		for (i64 i=0; i<=p2.size(); i++) {
			if (i == p2.size() || (i < p2.size() && p2[i] == ' ' && flagPow)) {
				flagPow = false; flagCo = true;
				monomial.pub(mp(pow, coef));
				coef = 0; pow = 0;
			}
			else if (p2[i] >= '0' && p2[i] <= '9') {
				if (flagCo) coef = coef * 10 + (p2[i] - '0');
				if (flagPow) pow = pow * 10 + (p2[i] - '0');
			}
			else if (p2[i] == 'x') {
				flagCo = false; flagPow = true;
			}
		}
		sort(monomial.begin(), monomial.end());
		stack<pii> S;
		for (i64 i=0; i<monomial.size(); i++) {
			if (!S.empty() && S.top().fi == monomial[i].fi) {
				i64 tmp = S.top().se + monomial[i].se;
				S.pop(); S.push(mp(monomial[i].fi, tmp));
			}
			else S.push(monomial[i]);
		}
		while (!S.empty()) {
			pii mono = S.top(); S.pop();
			cout << mono.se << "*x^" << mono.fi;
			if (!S.empty()) cout << " + ";
		}
		cout << endl;
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