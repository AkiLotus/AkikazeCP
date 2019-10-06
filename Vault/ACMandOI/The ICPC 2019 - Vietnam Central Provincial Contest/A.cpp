/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: A.cpp
// Time created: Sun Oct 06 2019 01:32

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
string s; int n;
/************************************************/

/************** [FUNCTIONS] **************/
bool isBeautiful(string str, int checkFrom=1) {
	for (int i=checkFrom; i<str.size(); i++) {
		if (str.substr(0, i) >= str.substr(i)) return false;
	}
	return true;
}

void Input() {
	cin >> s; n = s.size();
}

void Solve() {
	if (n == 1) {cout << ((s == "0") ? "1\n" : "\n"); return;}
	// it is guaranteed that s[0] = '0', obviously
	// also, if s[0] = '1', it can never be a beautiful string if n > 1
	// with n > 1, a beautiful string always has s.back() = 1
	s[n - 1] += 1;
	while (true) {
		int i = n - 1;
		for (; (i>0 && s[i] > '1'); i--) {
			s[i] -= 2; s[i-1]++;
		}
		if (i == 0) {cout << endl; return;}
		int checkFrom = i;
		while (i+1 < n) {
			for (int j=i+1; (j<n && j-i-1<=i); j++) {
				if (j == n-1) s[j] = '1';
				else s[j] = s[j-i-1];
			}
			i = min(i+i+1, n-1);
		}
		if (isBeautiful(s, checkFrom)) {cout << s << endl; break;}
		else s[n-1] += 1;
	}
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