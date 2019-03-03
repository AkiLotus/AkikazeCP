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
i64 n, T; vector<pii> tap;

/** -----EXTENSIVE FUNCTIONS----- **/
bool prioritizeTemp(pii a, pii b) {
	return (abs(a.se) > abs(b.se));
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> T; tap.resize(n);
	for (i64 i=0; i<n; i++) cin >> tap[i].fi;
	for (i64 i=0; i<n; i++) {cin >> tap[i].se; tap[i].se -= T;}
}

void ProSolve() {
	i64 additional = 0;
	for (i64 i=0; i<n; i++) {
		if (tap[i].se == 0) additional += tap[i].fi;
	}
	ld negative = 0, positive = 0, ans = 0;
	for (i64 i=0; i<n; i++) ans += tap[i].fi;
	vector<pii> neg, pos;
	for (i64 i=0; i<n; i++) {
		if (tap[i].se < 0) {negative += ((ld)tap[i].fi * abs(tap[i].se)); neg.pub(tap[i]);}
		else if (tap[i].se > 0) {positive += ((ld)tap[i].fi * abs(tap[i].se)); pos.pub(tap[i]);}
	}
	if (negative < EPS || positive < EPS) {
		cout << fixed << setprecision(9) << additional; return;
	}
	if (negative - positive >= EPS) {
		sort(neg.begin(), neg.end(), prioritizeTemp);
		for (i64 i=0; i<neg.size(); i++) {
			if (negative - positive < EPS) break;
			ld tmp = min((negative - positive) / abs(neg[i].se), (ld)neg[i].fi);
			ans -= tmp; negative -= (tmp * abs(neg[i].se));
		}
	}
	else if (positive - negative >= EPS) {
		sort(pos.begin(), pos.end(), prioritizeTemp);
		for (i64 i=0; i<pos.size(); i++) {
			if (positive - negative < EPS) break;
			ld tmp = min((positive - negative) / abs(pos[i].se),  (ld)pos[i].fi);
			ans -= tmp; positive -= (tmp * abs(pos[i].se));
		}
	}
	cout << fixed << setprecision(9) << ans;
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