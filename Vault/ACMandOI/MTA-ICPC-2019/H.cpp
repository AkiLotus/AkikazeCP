/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: H.cpp
// Time created: Sat Oct 19 2019 06:54

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
/*************************************************/

/************** [MASTER CONTROLS - PHASE 1] **************/
int OImode = 0;
int MultiTest = 0;
int Interactive = 0;

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
string s; int n;
/************************************************/

/************** [FUNCTIONS] **************/
int toRoman(string str) {
	int res = 0;
	char next = 'M';
	bool hasD = false, hasL = false, hasV = false;
	for (int i=0; i<str.size(); i++) {
		if (str[i] == 'M') {
			if (next != 'M') return -1;
			int j = i;
			while (j+1 < str.size() && str[j+1] == 'M') j++;
			if (j-i+1 > 3) return -1;
			next = 'D';
			res += 1000 * (j - i + 1); i = j;
		}
		else if (str[i] == 'D') {
			if (next != 'M' && next != 'D') return -1;
			next = 'C'; hasD = true; res += 500;
		}
		else if (str[i] == 'C') {
			if (next != 'M' && next != 'D' && next != 'C') return -1;
			if (i+1 < str.size() && str[i+1] == 'M') {
				if (hasD) return -1;
				i += 1; res += 900; next = 'L';
			}
			else if (i+1 < str.size() && str[i+1] == 'D') {
				if (hasD) return -1;
				i += 1; res += 400; next = 'L';
			}
			else {
				int j = i;
				while (j+1 < str.size() && str[j+1] == 'C') j++;
				if (j-i+1 > 3) return -1;
				next = 'L';
				res += 100 * (j - i + 1); i = j;
			}
		}
		else if (str[i] == 'L') {
			if (next != 'M' && next != 'D' && next != 'C' && next != 'L') return -1;
			next = 'X'; hasL = true; res += 50;
		}
		else if (str[i] == 'X') {
			if (next != 'M' && next != 'D' && next != 'C' && next != 'L' && next != 'X') return -1;
			if (i+1 < str.size() && str[i+1] == 'C') {
				if (hasL) return -1;
				i += 1; res += 90; next = 'V';
			}
			else if (i+1 < str.size() && str[i+1] == 'L') {
				if (hasL) return -1;
				i += 1; res += 40; next = 'V';
			}
			else {
				int j = i;
				while (j+1 < str.size() && str[j+1] == 'X') j++;
				if (j-i+1 > 3) return -1;
				next = 'V';
				res += 10 * (j - i + 1); i = j;
			}
		}
		else if (str[i] == 'V') {
			if (next != 'M' && next != 'D' && next != 'C' && next != 'L' && next != 'X' && next != 'V') return -1;
			next = 'I'; hasV = true; res += 5;
		}
		else if (str[i] == 'I') {
			if (next != 'M' && next != 'D' && next != 'C' && next != 'L' && next != 'X' && next != 'V' && next != 'I') return -1;
			if (i+1 < str.size() && str[i+1] == 'X') {
				if (hasV) return -1;
				i += 1; res += 9; next = '#';
			}
			else if (i+1 < str.size() && str[i+1] == 'V') {
				if (hasV) return -1;
				i += 1; res += 4; next = '#';
			}
			else {
				int j = i;
				while (j+1 < str.size() && str[j+1] == 'I') j++;
				if (j-i+1 > 3) return -1;
				next = '#';
				res += 1 * (j - i + 1); i = j;
			}
		}
	}
	return res;
}

void Input() {
	cin >> s;
	n = s.size();
}

void Solve() {
	vector<int> dp(n, INF);
	for (int i=-1; i<n-1; i++) {
		for (int j=i+1; j<=min(n-1, i+20); j++) {
			if (toRoman(s.substr(i+1, j-i)) == -1) continue;
			if (i == -1) dp[j] = min(dp[j], toRoman(s.substr(i+1, j-i)));
			else dp[j] = min(dp[j], dp[i] + toRoman(s.substr(i+1, j-i)));
		}
	}
	cout << dp[n-1] << endl;
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