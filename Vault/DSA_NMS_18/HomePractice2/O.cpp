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
string A, B, A1, B1, C1, A2, B2, C2;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> A >> B;
}

void ProSolve() {
	A1 = A; B1 = B; A2 = A; B2 = B;
	for (i64 i=0; i<A1.size(); i++) {
		if (A1[i] == '6') A1[i] = '5';
	}
	for (i64 i=0; i<B1.size(); i++) {
		if (B1[i] == '6') B1[i] = '5';
	}
	for (i64 i=0; i<A2.size(); i++) {
		if (A2[i] == '5') A2[i] = '6';
	}
	for (i64 i=0; i<B2.size(); i++) {
		if (B2[i] == '5') B2[i] = '6';
	}
	A1.insert(0, 1000-A1.size(), '0');
	B1.insert(0, 1000-B1.size(), '0');
	C1.insert(0, 1000-C1.size(), '0');
	A2.insert(0, 1000-A2.size(), '0');
	B2.insert(0, 1000-B2.size(), '0');
	C2.insert(0, 1000-C2.size(), '0');
	i64 carry1 = 0, carry2 = 0;
	for (i64 i=999; i>=0; i--) {
		i64 tmp1 = (A1[i] - '0') + (B1[i] - '0') + carry1;
		i64 tmp2 = (A2[i] - '0') + (B2[i] - '0') + carry2;
		C1[i] = char(48 + tmp1 % 10); C2[i] = char(48 + tmp2 % 10);
		carry1 = tmp1 / 10; carry2 = tmp2 / 10;
	}
	if (C1 > C2) swap(C1, C2);
	while (C1[0] == '0') C1.erase(0, 1);
	while (C2[0] == '0') C2.erase(0, 1);
	cout << C1 << " " << C2;
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