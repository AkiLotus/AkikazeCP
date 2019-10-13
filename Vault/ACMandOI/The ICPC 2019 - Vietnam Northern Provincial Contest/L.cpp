/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: L.cpp
// Time created: Sun Oct 13 2019 01:07

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
int n; vector<int> d;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> n; d.resize(n);
	for (auto &z: d) cin >> z;
}

void Solve() {
	sort(d.begin(), d.end());
	vector<i64> ans(3, 0);
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			i64 sqr = (1LL * d[i] * d[i]) + (1LL * d[j] * d[j]);
			i64 rightDemand = sqrt(sqr);
			int maxAllowed = d[i] + d[j] - 1;
			int maxID = upper_bound(d.begin(), d.end(), maxAllowed) - d.begin() - 1;
			int minRightID = min(max((int)(lower_bound(d.begin(), d.end(), (int)rightDemand) - d.begin()), j+ 1), maxID);
			int maxRightID = min((int)(upper_bound(d.begin(), d.end(), (int)rightDemand) - d.begin() - 1), maxID);
			if (rightDemand * rightDemand == sqr && minRightID < n && d[minRightID] == rightDemand) {
				ans[0] += max(0, (minRightID - 1) - (j + 1) + 1);
				ans[1] += max(0, maxRightID - minRightID + 1);
				ans[2] += max(0, maxID - (maxRightID + 1) + 1);
			}
			else {
				ans[0] += max(0, maxRightID - (j + 1) + 1);
				ans[2] += max(0, maxID - (maxRightID + 1) + 1);
			}
		}
	}
	for (auto &z: ans) cout << z << " "; cout << endl;
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