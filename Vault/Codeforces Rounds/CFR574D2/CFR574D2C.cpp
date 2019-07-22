/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: CFR574D2C.cpp
// Time created: Wed Jul 17 2019 14:27

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
int n; vector<vector<int>> h;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> n; h.resize(2, vector<int>(n));
	for (auto &Row: h) {
		for (auto &z: Row) cin >> z;
	}
}

void Solve() {
	vector<vector<long long>> dp(2, vector<long long>(n));
	dp[0][0] = h[0][0]; dp[1][0] = h[1][0];
	for (int i=1; i<n; i++) {
		dp[0][i] = max(dp[0][i-1], dp[1][i-1] + h[0][i]);
		dp[1][i] = max(dp[1][i-1], dp[0][i-1] + h[1][i]);
	}
	cout << max(dp[0][n-1], dp[1][n-1]) << endl;
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	#ifdef Akikaze
		cout << "Source code by #Team4T-Akikaze.\n";
		cout << "Input: " << ((OImode) ? infile : "stdin");
		cout << " | Output: " << ((OImode) ? outfile : "stdout") << endl << endl;
		cout << "MultiTest-Mode: " << ((MultiTest) ? "ON\n" : "OFF\n");
		cout << "Interactive-Mode: " << ((Interactive) ? "ON\n\n" : "OFF\n\n");
	#else
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