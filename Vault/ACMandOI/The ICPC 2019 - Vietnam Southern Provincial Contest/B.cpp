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
int n; vector<int> a;
int maxIteration, limitCalculation = 20000000;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> n; a.resize(n);
	maxIteration = limitCalculation / n;
	for (auto &z: a) cin >> z;
}

void Solve() {
	int m = n, sum = 0;
	for (int i=0; i<m; i++) {
		sum += a[i];
		if (a[i] % 2 != 0) continue;
		a[i] /= 2; a.push_back(a[i]); n++;
	}
	int ans = INT_MAX;
	for (int iteration=0; iteration < maxIteration; iteration++) {
		int pot0 = 0, pot1 = 0;
		for (int i=0; i<n; i++) {
			if (pot0 * 2 >= sum) pot1 += a[i];
			else if (pot1 * 2 >= sum) pot0 += a[i];
			else {
				int choice = rng32() % 2;
				if (choice) pot1 += a[i]; else pot0 += a[i];
			}
		}
		ans = min(ans, (int)abs(pot0 - pot1));
	}
	cout << (sum + ans) / 2 << endl;
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
	
	int T = 1; if (MultiTest) {cin >> T; cin.ignore();}
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/
