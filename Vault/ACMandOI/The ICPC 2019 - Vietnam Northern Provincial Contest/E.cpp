/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: E.cpp
// Time created: Sun Oct 13 2019 02:40

/************** [OPTIMIZATION PROTOCOL] **************/
#pragma GCC optimize("Ofast")
/*****************************************************/

/************** [LIBRARY PROTOCOL] **************/
#include <bits/stdc++.h>
using namespace std;
/************************************************/

/************** [GNU OMISSIONS] **************/
#define y0 withindarkness
#define y1 apinklotusbloomed
#define yn carryingapurplesoul
#define j1 togetherformingtheTeam
/*********************************************/

/************** [LEGENDS/CONSTANTS] **************/
#define endl '\n'
#define i64 long long
#define ld long double
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116L;
const long double EPS = 0.000000001L, Gold = ((1.0L+sqrt(5.0L))/2.0L);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
/*************************************************/

/************** [MASTER CONTROLS - PHASE 1] **************/
int OImode = 0;
int MultiTest = 1;
int Interactive = 0;

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
i64 n; vector<i64> a;
/************************************************/

/************** [FUNCTIONS] **************/
i64 f(vector<i64> A, i64 x) {
	i64 r = 1, res = 0;
	for (int i=A.size()-1; i>=0; i--) {
		res += r * A[i];
		r *= x;
	}
	return res;
}

void Input() {
	cin >> n; a.clear(); a.resize(n+1);
	for (auto &z: a) cin >> z;
}

void Solve() {
	i64 ans = LINF;
	while (a.back() == 0) {ans = min(ans, 0LL); a.pop_back();}
	for (int i=1; i<=sqrt(abs(a.back())); i++) {
		if (a.back() % i != 0) continue;
		if (f(a, i) == 0) ans = min(ans, 1LL * i);
		if (f(a, -i) == 0) ans = min(ans, 1LL * -i);
		if (f(a, a.back() / i) == 0) ans = min(ans, 1LL * a.back() / i);
		if (f(a, -a.back() / i) == 0) ans = min(ans, 1LL * -a.back() / i);
	}
	cout << ans << endl;
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	#ifndef Akikaze
		if (OImode) {
			assert(freopen(infile, "r", stdin));
			assert(freopen(outfile, "w", stdout));
		}
	#endif
	
	ios_base::sync_with_stdio(false);
	if (!Interactive) cin.tie(NULL);
	
	int T = 1; if (MultiTest) {cin >> T; cin.ignore();}
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/