/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: B.cpp
// Time created: Sat Oct 19 2019 06:39

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
int MultiTest = 1;
int Interactive = 0;

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int n, k; vector<int> a;
/************************************************/

/************** [FUNCTIONS] **************/
int sign(int z) {
	if (z == 0) z = 5;
	if (z % 2 != 0) return z;
	return -z;
}

void Input() {
	cin >> n >> k; a.clear(); a.resize(n);
	for (int i=0; i<n; i++) cin >> a[i];
}

void Solve() {
	vector<vector<i64> > dp(n, vector<i64>(k*5+1, -LINF));
	dp[0][0] = 0; dp[0][1] = a[0];
	for (int i=0; i<n-1; i++) {
		for (int j=0; j<=k*5; j++) {
			if (dp[i][j] == -LINF) continue;
			dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
			if (j < k*5) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1LL * a[i+1] * sign((j + 1) % 5));
		}
	}
	cout << dp[n-1][k*5] << endl;
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