/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: M.cpp
// Time created: Sat Oct 19 2019 07:20

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
int MultiTest = 0;
int Interactive = 0;

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int n, m; vector<vector<char> > a, b;
/************************************************/

/************** [FUNCTIONS] **************/
int adjacency(vector<pair<int, int> > &HList, vector<pair<int, int> > &WList,
			int offsetx_H, int offsety_H, int offsetx_W, int offsety_W) {
	vector<vector<char> > A(n*3, vector<char>(m*3, '.'));
	for (int i=0; i<HList.size(); i++) {
		int x = HList[i].first + offsetx_H;
		int y = HList[i].second + offsety_H;
		A[x][y] = 'H';
	}
	int res = 0;
	for (int i=0; i<WList.size(); i++) {
		int x = WList[i].first + offsetx_W;
		int y = WList[i].second + offsety_W;
		if (A[x][y] == 'H') return 0;
		for (int dx=-1; dx<=+1; dx++) {
			for (int dy=-1; dy<=+1; dy++) {
				if (dx * dy != 0) continue;
				if (dx == 0 && dy == 0) continue;
				if (x + dx < 0 || x + dx >= n*3) continue;
				if (y + dy < 0 || y + dy >= m*3) continue;
				res += (A[x+dx][y+dy] == 'H');
			}
		}
	}
	return res;
}

void Input() {
	cin >> n >> m;
	a.resize(n, vector<char>(m));
	b.resize(n, vector<char>(m));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> b[i][j];
		}
	}
}

void Solve() {
	int mnx_H = INF, mxx_H = -INF, mny_H = INF, mxy_H = -INF;
	int mnx_W = INF, mxx_W = -INF, mny_W = INF, mxy_W = -INF;
	vector<pair<int, int> > HList, WList;
	vector<vector<bool> > visA(n, vector<bool>(m, false));
	vector<vector<bool> > visB(n, vector<bool>(m, false));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (visA[i][j]) continue;
			if (a[i][j] == '.') continue;
			queue<pair<int, int> > Q;
			visA[i][j] = true; Q.push(make_pair(i, j));
			while (!Q.empty()) {
				pair<int, int> Token = Q.front(); Q.pop();
				int x = Token.first, y = Token.second;
				mnx_H = min(mnx_H, x); mxx_H = max(mxx_H, x);
				mny_H = min(mny_H, y); mxy_H = max(mxy_H, y);
				HList.push_back(Token);
				if (x-1 >= 0 && !visA[x-1][y] && a[x-1][y] == 'H') {
					visA[x-1][y] = true; Q.push(make_pair(x-1, y));
				}
				if (x+1 < n && !visA[x+1][y] && a[x+1][y] == 'H') {
					visA[x+1][y] = true; Q.push(make_pair(x+1, y));
				}
				if (y-1 >= 0 && !visA[x][y-1] && a[x][y-1] == 'H') {
					visA[x][y-1] = true; Q.push(make_pair(x, y-1));
				}
				if (y+1 < m && !visA[x][y+1] && a[x][y+1] == 'H') {
					visA[x][y+1] = true; Q.push(make_pair(x, y+1));
				}
			}
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (visB[i][j]) continue;
			if (b[i][j] == '.') continue;
			queue<pair<int, int> > Q;
			visB[i][j] = true; Q.push(make_pair(i, j));
			while (!Q.empty()) {
				pair<int, int> Token = Q.front(); Q.pop();
				int x = Token.first, y = Token.second;
				mnx_W = min(mnx_W, x); mxx_W = max(mxx_W, x);
				mny_W = min(mny_W, y); mxy_W = max(mxy_W, y);
				WList.push_back(Token);
				if (x-1 >= 0 && !visB[x-1][y] && b[x-1][y] == 'W') {
					visB[x-1][y] = true; Q.push(make_pair(x-1, y));
				}
				if (x+1 < n && !visB[x+1][y] && b[x+1][y] == 'W') {
					visB[x+1][y] = true; Q.push(make_pair(x+1, y));
				}
				if (y-1 >= 0 && !visB[x][y-1] && b[x][y-1] == 'W') {
					visB[x][y-1] = true; Q.push(make_pair(x, y-1));
				}
				if (y+1 < m && !visB[x][y+1] && b[x][y+1] == 'W') {
					visB[x][y+1] = true; Q.push(make_pair(x, y+1));
				}
			}
		}
	}
	for (int i=0; i<HList.size(); i++) {
		HList[i].first -= mnx_H;
		HList[i].second -= mny_H;
	}
	mxx_H -= mnx_H; mxy_H -= mny_H; mnx_H = mny_H = 0;
	for (int i=0; i<WList.size(); i++) {
		WList[i].first -= mnx_W;
		WList[i].second -= mny_W;
	}
	mxx_W -= mnx_W; mxy_W -= mny_W; mnx_W = mny_W = 0;
	int ans = 0;
	for (int i=0; i<n*3; i++) {
		for (int j=0; j<m*3; j++) {
			if (i + mxx_H >= n*3) continue;
			if (j + mxy_H >= m*3) continue;
			ans = max(ans, adjacency(HList, WList, i, j, n, m));
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
	
	int T = 1; if (MultiTest) {cin >> T; cin.ignore();}
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/