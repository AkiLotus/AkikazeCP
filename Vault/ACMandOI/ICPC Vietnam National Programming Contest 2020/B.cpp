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
int MultiTest = 1;
int Interactive = 0;

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int r, c; vector<vector<char>> matrix;
int dx[] = {-1, -1, -1, 0, 0, +1, +1, +1};
int dy[] = {-1, 0, +1, -1, +1, -1, 0, +1};
/************************************************/

/************** [FUNCTIONS] **************/
bool inBoard(int x, int y) {
	return (x >= 0 && x <= r+1 && y >= 0 && y <= c+1);
}

void Input() {
	cin >> r >> c; matrix.clear(); matrix.resize(r+2, vector<char>(c+2));
	if (r == 0 && c == 0) exit(0);
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			cin >> matrix[i][j];
		}
	}
}

void Solve() {
	for (int i=2; i<=r+1; i++) matrix[i][0] = '#';
	for (int i=0; i<=r-1; i++) matrix[i][c+1] = '#';
	for (int j=2; j<=c+1; j++) matrix[0][j] = '#';
	for (int j=0; j<=c-1; j++) matrix[r+1][j] = '#';
	matrix[0][0] = '@'; matrix[0][1] = '@'; matrix[1][0] = '@';
	matrix[r+1][c+1] = '@'; matrix[r][c+1] = '@'; matrix[r+1][c] = '@';

	deque<pair<int, int>> D;
	vector<vector<int>> distance(r+2, vector<int>(c+2, INF));
	distance[2][0] = 0; D.push_front(make_pair(2, 0));

	while (!D.empty()) {
		pair<int, int> token = D.front(); D.pop_front();
		int x = token.first, y = token.second;

		//cout << x << " " << y << " " << distance[x][y] << endl;

		for (int i=0; i<8; i++) {
			if (!inBoard(x+dx[i], y+dy[i])) continue;
			if (distance[x+dx[i]][y+dy[i]] < INF) continue;
			if (matrix[x+dx[i]][y+dy[i]] == '@') continue;
			//cout << "target: " << x+dx[i] << " " << y+dy[i] << endl;
			if (matrix[x+dx[i]][y+dy[i]] == '#') {
				distance[x+dx[i]][y+dy[i]] = distance[x][y];
				D.push_front(make_pair(x+dx[i], y+dy[i]));
			}
			if (matrix[x+dx[i]][y+dy[i]] == '.') {
				distance[x+dx[i]][y+dy[i]] = distance[x][y] + 1;
				D.push_back(make_pair(x+dx[i], y+dy[i]));
			}
		}
	}

	int answer = INF;
	for (int j=2; j<=c+1; j++) answer = min(answer, distance[0][j]);
	for (int i=0; i<=r-1; i++) answer = min(answer, distance[i][c+1]);
	if (answer == INF) cout << "-1\n";
	else cout << answer << endl;
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