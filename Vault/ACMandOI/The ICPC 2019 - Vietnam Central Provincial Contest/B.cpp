/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: B.cpp
// Time created: Sun Oct 06 2019 04:39

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
int n; vector<int> D, T;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> n; D.resize(n); T.resize(n);
	for (int i=0; i<n; i++) cin >> D[i] >> T[i];
}

void Solve() {
	vector<pair<int, int>> arranged;
	for (int i=0; i<n; i++) {
		arranged.push_back({D[i], T[i]});
		int z = i;
		while (z > 0 && (arranged[z-1].first > arranged[z].first || (arranged[z-1].first == arranged[z].first && arranged[z-1].second > arranged[z].second))) {swap(arranged[z-1], arranged[z]); z--;}
		int ans = 0, Time = 0;
		for (int x=0; x<arranged.size(); x++) {
			ans = max(ans, max(0, Time + arranged[x].second - arranged[x].first));
			Time += arranged[x].second;
		}
		cout << ans << endl;
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