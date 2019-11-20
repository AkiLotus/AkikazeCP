/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: E.cpp
// Time created: Sun Nov 03 2019 00:50

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
string g, k; double p;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> g >> k >> p;
}

void Solve() {
	int n = g.size(), m = k.size();
	vector<vector<vector<double>>> dp(n+1, vector<vector<double>>(m+1, vector<double>(500001, 0.0)));
	dp[0][0][0] = 1.0;
	double res = 0.0;
	for (int i=0; i<500001; i++) {
		for (int x=0; x<=n; x++) {
			for (int y=0; y<m; y++) {
				if (dp[x][y][i] == 0.0) continue;
				if (x == n) {res += dp[x][y][i]; continue;}
				if (i == 500000) continue;
				if (x == 0 && y == 0 && i != 0) continue;
				int newx_H = x, newy_H = y, newx_T = x, newy_T = y;
				if (g[x] == 'H') {newx_H++; newx_T = 0;} else {newx_H = 0; newx_T++;}
				if (k[y] == 'H') {newy_H++; newy_T = 0;} else {newy_H = 0; newy_T++;}
				dp[newx_H][newy_H][i+1] += dp[x][y][i] * p;
				dp[newx_T][newy_T][i+1] += dp[x][y][i] * (1.0 - p);
			}
		}
	}
	cout << fixed << setprecision(9) << res << endl;
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