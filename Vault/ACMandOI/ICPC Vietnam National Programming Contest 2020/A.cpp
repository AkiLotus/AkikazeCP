/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: A.cpp
// Time created: Sun Nov 15 2020 00:57

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
int day; string month;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> day >> month;
}

void Solve() {
	if (month == "Mar" && day >= 21) cout << "Aries\n";
	if (month == "Apr" && day <= 20) cout << "Aries\n";
	if (month == "Apr" && day >= 21) cout << "Taurus\n";
	if (month == "May" && day <= 20) cout << "Taurus\n";
	if (month == "May" && day >= 21) cout << "Gemini\n";
	if (month == "Jun" && day <= 21) cout << "Gemini\n";
	if (month == "Jun" && day >= 22) cout << "Cancer\n";
	if (month == "Jul" && day <= 22) cout << "Cancer\n";
	if (month == "Jul" && day >= 23) cout << "Leo\n";
	if (month == "Aug" && day <= 22) cout << "Leo\n";
	if (month == "Aug" && day >= 23) cout << "Virgo\n";
	if (month == "Sep" && day <= 21) cout << "Virgo\n";
	if (month == "Sep" && day >= 22) cout << "Libra\n";
	if (month == "Oct" && day <= 22) cout << "Libra\n";
	if (month == "Oct" && day >= 23) cout << "Scorpio\n";
	if (month == "Nov" && day <= 22) cout << "Scorpio\n";
	if (month == "Nov" && day >= 23) cout << "Sagittarius\n";
	if (month == "Dec" && day <= 21) cout << "Sagittarius\n";
	if (month == "Dec" && day >= 22) cout << "Capricorn\n";
	if (month == "Jan" && day <= 20) cout << "Capricorn\n";
	if (month == "Jan" && day >= 21) cout << "Aquarius\n";
	if (month == "Feb" && day <= 19) cout << "Aquarius\n";
	if (month == "Feb" && day >= 20) cout << "Pisces\n";
	if (month == "Mar" && day <= 20) cout << "Pisces\n";
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