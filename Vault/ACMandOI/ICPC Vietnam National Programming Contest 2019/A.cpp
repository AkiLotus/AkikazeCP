/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: A.cpp
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
int C, A; vector<vector<char>> mat;
vector<vector<int>> dist;
int dx[] = {-1, 0, 0, 0, +1};
int dy[] = {-1, -2, -1, 0, -1};
queue<pair<int, int>> Q;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> C >> A; mat.resize(C, vector<char>(A, '.'));
	dist.resize(C, vector<int>(A, INT_MAX));
	for (int i=0; i<C; i++) {
		for (int j=0; j<A; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'G') {
				dist[i][j] = 0;
				Q.push({i, j});
			}
		}
	}
}

void Solve() {
	int res = INT_MAX;
	while (!Q.empty()) {
		pair<int, int> Token = Q.front(); Q.pop();
		int x = Token.first, y = Token.second;
		if (x == C-1) {res = min(res, dist[x][y] + 1); break;}
		for (int i=0; i<5; i++) {
			if (x + dx[i] < 0) continue;
			int xn = x + dx[i], yn = (y + dy[i] + A * 4) % A;
			if (mat[xn][yn] == 'M') continue;
			if (mat[xn][(yn + 1) % A] == 'M') continue;
			if (dist[xn][yn] != INT_MAX) continue;
			dist[xn][yn] = dist[x][y] + 1; Q.push({xn, yn});
		}
	}
	if (res != INT_MAX) cout << res << endl;
	else cout << "-1\n";
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