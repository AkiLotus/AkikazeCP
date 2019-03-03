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
string s; i64 n;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> s; n = s.size();
}

void ProSolve() {
	if (n % 2 == 1) {
		n++; for (i64 i=0; i<n/2; i++) cout << "4";
		for (i64 i=0; i<n/2; i++) cout << "7"; return;
	}
	string mx = "", mn = "";
	for (i64 i=0; i<n/2; i++) {mx += "4"; mn += "4";} mx += "4";
	for (i64 i=0; i<n/2; i++) {mx += "7"; mn += "7";} mx += "7";
	i64 ptr1 = 0, ptr2 = n/2;
	while (ptr1 < n) {
		if (s[ptr1] < mn[ptr1]) {cout << mn; return;}
		if (s[ptr1] > mn[ptr1]) {
			if (ptr2 == n) {cout << mx; return;}
			swap(mn[min(ptr1, ptr2-1)], mn[ptr2]); ptr2++;
			if (s[min(ptr1, ptr2-2)] < mn[min(ptr1, ptr2-2)]) {cout << mn; return;}
			else ptr1 = min(ptr1, ptr2-2);
		}
		ptr1++;
	}
	if (s <= mn) cout << mn;
	else cout << mx;
	
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