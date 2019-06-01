/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: 1162B.cpp
// Time created: Sun May 19 2019 11:08

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

char infile[] = "FILE.IN";
char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int n, m; vector<vector<int>> a, b;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> n >> m;
	a.resize(n, vector<int>(m));
	b.resize(n, vector<int>(m));
	for (auto &rowa: a) {
		for (auto &elea: rowa) cin >> elea;
	}
	for (auto &rowb: b) {
		for (auto &eleb: rowb) cin >> eleb;
	}
}

void Solve() {
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			int Min = min(a[i][j], b[i][j]), Max = max(a[i][j], b[i][j]);
			a[i][j] = Min; b[i][j] = Max;
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (i > 0 && a[i-1][j] >= a[i][j]) {cout << "Impossible\n"; return;}
			if (j > 0 && a[i][j-1] >= a[i][j]) {cout << "Impossible\n"; return;}
			if (i > 0 && b[i-1][j] >= b[i][j]) {cout << "Impossible\n"; return;}
			if (j > 0 && b[i][j-1] >= b[i][j]) {cout << "Impossible\n"; return;}
		}
	}
	cout << "Possible\n";
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
			freopen(infile, "r", stdin);
			freopen(outfile, "w", stdout);
		}
	#endif
	
	ios_base::sync_with_stdio(false);
	if (!Interactive) cin.tie(NULL);
	
	int T = 1; if (MultiTest) cin >> T;
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/