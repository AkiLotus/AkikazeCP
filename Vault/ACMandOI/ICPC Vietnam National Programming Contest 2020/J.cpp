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
int MultiTest = 0;
int Interactive = 0;

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int n, k; vector<int> a;
/************************************************/

/************** [FUNCTIONS] **************/
i64 calculate(vector<int> arr) {
	i64 ans = 0;
	for (int i=1; i<n-1; i++) {
		int mxL = -INF;
		int mxR = -INF;
		for (int j = 0; j < i; j++) mxL = max(mxL, arr[j]);
		for (int j = i+1; j < n; j++) mxR = max(mxR, arr[j]);
		int h = min(mxL, mxR);
		if (h < arr[i]) continue;
		ans += h - arr[i];
	}
	return ans;
}

void Input() {
	cin >> n >> k; a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	i64 answer = 0;
	// single
	for (int i=0; i<n; i++) {
		a[i] += k;
		answer = max(answer, calculate(a));
		a[i] -= k;
	}
	
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			for (int x=1; x<k; x++) {
				if (k - x <= 0) continue;
				a[i] += x; a[j] += k - x;
				answer = max(answer, calculate(a));
				a[i] -= x; a[j] -= k - x;
			}
		}
	}
	// cout << answer << endl;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			for (int j2=j+1; j2<n; j2++) {
				for (int x=1; x<k; x++) {
					for (int y=1; y<k-x; y++) {
						if (k - x - y <= 0) continue;
						a[i] += x; a[j] += y; a[j2] += k - x - y;
						answer = max(answer, calculate(a));
						a[i] -= x; a[j] -= y; a[j2] -= k - x - y;
					}
				}
			}
		}
	}

	cout << answer << endl;
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