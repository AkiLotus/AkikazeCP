/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: K.cpp
// Time created: Sun Nov 15 2020 01:14

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
int n; vector<pair<int, int>> a;
/************************************************/

/************** [FUNCTIONS] **************/
int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	int dx1 = p2.first - p1.first, dy1 = p2.second - p1.second;
	int dx2 = p3.first - p2.first, dy2 = p3.second - p2.second;
	i64 cross = 1LL * dx1 * dy2 - 1LL * dx2 * dy1;
	if (cross < 0) return -1;
	if (cross == 0) return 0;
	if (cross > 0) return +1;
	return 0;
}

bool check_sides(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4) {
	return (ccw(p1, p2, p3) * ccw(p1, p2, p4) < 0);
}

bool convex_polygon(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4) {
	return ((check_sides(p1, p2, p3, p4) && check_sides(p3, p4, p1, p2)) || (check_sides(p1, p3, p2, p4) && check_sides(p2, p4, p1, p3)) || (check_sides(p1, p4, p2, p3) && check_sides(p2, p3, p1, p4)));
}

void Input() {
	cin >> n; a.clear(); a.resize(n);
	if (n == 0) exit(0);
	for (auto &z: a) cin >> z.first >> z.second;
}

void Solve() {
	int ans = 0;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			for (int k=j+1; k<n; k++) {
				for (int l=k+1; l<n; l++) {
					if (convex_polygon(a[i], a[j], a[k], a[l])) {
						ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
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
	
	while(true) {Input(); Solve();}
	
	return 0;
}
/************************************/