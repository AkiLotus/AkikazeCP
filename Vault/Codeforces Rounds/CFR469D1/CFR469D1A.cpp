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
string s; i64 n;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> s; n = s.size();
}

void ProSolve() {
	i64 oneCnt = 0, zeroCnt = 0;
	set<i64> One, Zero;
	for (i64 i=0; i<n; i++) {
		if (s[i] == '1') {oneCnt++; One.insert(i);}
		else {zeroCnt++; Zero.insert(i);}
	}
	if (oneCnt >= zeroCnt) {cout << "-1"; return;}
	i64 Size = zeroCnt - oneCnt;
	vector<vi> ans(Size); bool stuck = false;
	for (i64 i=0; i<min(Size-1, oneCnt); i++) {
		if (Zero.empty()) {stuck = true; break;}
		i64 firstEle = *Zero.begin();
		ans[i].pub(firstEle); Zero.erase(firstEle);
		if (One.lower_bound(firstEle) == One.end()) {stuck = true; break;}
		i64 secondEle = *One.lower_bound(firstEle);
		ans[i].pub(secondEle); One.erase(secondEle);
		if (Zero.empty()) {stuck = true; break;}
		auto ite0 = Zero.end(); ite0--;
		if (*ite0 < secondEle) {stuck = true; break;}
		i64 thirdEle = *ite0;
		ans[i].pub(thirdEle); Zero.erase(thirdEle);
	}
	if (!stuck) {
		if (One.empty()) {
			i64 z = oneCnt;
			for (; z<Size; z++) {
				ans[z].pub(*Zero.begin()); Zero.erase(Zero.begin());
			}
		}
		else {
			for (i64 i=0; i<n-3*(Size-1); i++) {
				if (i % 2 == 0) {
					if (Zero.empty() || (i > 0 && Zero.lower_bound(ans[Size-1][i-1]) == Zero.end())) {stuck = true; break;}
					i64 tmp = *Zero.begin(); if (i > 0) tmp = *Zero.lower_bound(ans[Size-1][i-1]);
					ans[Size-1].pub(tmp); Zero.erase(tmp);
				}
				else {
					if (One.empty() || (i > 0 && One.lower_bound(ans[Size-1][i-1]) == One.end())) {stuck = true; break;}
					i64 tmp = *One.begin(); if (i > 0) tmp = *One.lower_bound(ans[Size-1][i-1]);
					ans[Size-1].pub(tmp); One.erase(tmp);
				}
			}
		}
	}
	if (stuck) cout << "-1";
	else {
		cout << ans.size() << endl;
		for (i64 i=0; i<ans.size(); i++) {
			cout << ans[i].size() << " ";
			for (i64 j=0; j<ans[i].size(); j++) cout << (ans[i][j]+1) << " ";
			cout << endl;
		}
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