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
int MultiTest = 0;
int Interactive = 0;

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
string s, t;
/************************************************/

/************** [FUNCTIONS] **************/
string minimum(string a, string b) {
	if (a.size() > b.size()) return b;
	if (a.size() < b.size()) return a;
	if (a < b) return a;
	return b;
}

string maximum(string a, string b) {
	if (minimum(a, b) == a) return b;
	return a;
}

string sub(string a, string b) {
	if (minimum(a, b) == a) swap(a, b);
	while (a.size() > b.size()) b = "0" + b;
	string c = a;
	int carry = 0;
	for (int i=a.size()-1; i>=0; i--) {
		int d = (a[i] - '0') - (b[i] - '0') - carry;
		carry = 0;
		while (d < 0) {carry++; d += 10;}
		c[i] = char(48 + d);
	}
	while (c.size() > 1 && c[0] == '0') c.erase(0, 1);
	return c;
}

void Input() {
	cin >> s >> t;
}

void Solve() {
	string minS = s, maxS = s;
	string minT = t, maxT = t;
	int n = s.size(), m = t.size();
	for (int i=1; i<n; i++) {
		s = s.substr(1) + s[0];
		if (s[0] == '0') continue;
		maxS = max(maxS, s);
		minS = min(minS, s);
	}
	for (int i=1; i<m; i++) {
		t = t.substr(1) + t[0];
		if (t[0] == '0') continue;
		maxT = max(maxT, t);
		minT = min(minT, t);
	}
	cout << maximum(sub(maxS, minT), sub(maxT, minS));
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
