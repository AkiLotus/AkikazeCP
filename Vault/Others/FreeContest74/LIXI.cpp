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
i64 P, A, B, C, D;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> P >> A >> B >> C >> D;
}

void ProSolve() {
	if (P > A*1 + B*5 + C*10 + D*25) {cout << "Impossible"; return;}
	if (P == A*1 + B*5 + C*10 + D*25) {cout << A + B + C + D; return;}
	i64 exceed = (A*1 + B*5 + C*10 + D*25) - P, coinLeft =  A + B + C + D;
	i64 tmpD = min(D, exceed/25);
	if (tmpD % 2 == 0) {
		exceed -= 25*tmpD; coinLeft -= tmpD;
		i64 tmpC = min(C, exceed/10); exceed -= 10*tmpC; coinLeft -= tmpC;
		i64 tmpB = min(B, exceed/05); exceed -= 05*tmpB; coinLeft -= tmpB;
		i64 tmpA = min(A, exceed/01); exceed -= 01*tmpA; coinLeft -= tmpA;
		if (!exceed) cout << coinLeft; else cout << "Impossible";
	}
	else {
		i64 exceed1 = exceed, coinLeft1 = coinLeft;
		exceed -= 25*tmpD; coinLeft -= tmpD;
		i64 tmpC = min(C, exceed/10); exceed -= 10*tmpC; coinLeft -= tmpC;
		i64 tmpB = min(B, exceed/05); exceed -= 05*tmpB; coinLeft -= tmpB;
		i64 tmpA = min(A, exceed/01); exceed -= 01*tmpA; coinLeft -= tmpA;
		exceed1 -= 25*(tmpD-1); coinLeft1 -= (tmpD-1);
		tmpC = min(C, exceed/10); exceed1 -= 10*tmpC; coinLeft1 -= tmpC;
		tmpB = min(B, exceed/05); exceed1 -= 05*tmpB; coinLeft1 -= tmpB;
		tmpA = min(A, exceed/01); exceed1 -= 01*tmpA; coinLeft1 -= tmpA;
		if (!exceed && !exceed1) cout << max(coinLeft, coinLeft1);
		else if (!exceed) cout << coinLeft;
		else if (!exceed1) cout << coinLeft1;
		else cout << "Impossible";
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