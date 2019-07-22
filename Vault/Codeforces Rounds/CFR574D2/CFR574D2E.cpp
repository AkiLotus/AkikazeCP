/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: CFR574D2E.cpp
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
int n, m, a, b, x, y, z; vector<int> g;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> n >> m >> a >> b; g.resize(n*m);
	cin >> g[0] >> x >> y >> z;
	for (int i=1; i<n*m; i++) g[i] = (1LL * g[i-1] * x + y) % z;
}

void Solve() {
	vector<vector<int>> minRow(n, vector<int>(m, INT_MAX));
	for (int i=0; i<n; i++) {
		deque<pair<int, int>> Deque;
		for (int j=0; j<m; j++) {
			while (!Deque.empty() && g[Deque.back().first * m + Deque.back().second] > g[i*m+j]) Deque.pop_back();
			Deque.push_back(make_pair(i, j));
			if (j >= b-1) {
				int x = Deque.front().first, y = Deque.front().second;
				minRow[i][j-b+1] = g[x*m+y];
			}
			while (!Deque.empty() && Deque.front().second <= j-b+1) Deque.pop_front();
		}
	}
	vector<vector<int>> minRect(n, vector<int>(m, INT_MAX));
	for (int j=0; j<m; j++) {
		deque<pair<int, int>> Deque;
		for (int i=0; i<n; i++) {
			while (!Deque.empty() && minRow[Deque.back().first][Deque.back().second] > minRow[i][j]) Deque.pop_back();
			Deque.push_back(make_pair(i, j));
			if (i >= a-1) {
				int x = Deque.front().first, y = Deque.front().second;
				minRect[i-a+1][j] = minRow[x][y];
			}
			while (!Deque.empty() && Deque.front().first <= i-a+1) {
				Deque.pop_front();
			}
		}
	}
	i64 ans = 0;
	for (auto &Row: minRect) {
		for (auto &z: Row) {
			if (z != INT_MAX) ans += z;
		}
	}
	cout << ans << endl;
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