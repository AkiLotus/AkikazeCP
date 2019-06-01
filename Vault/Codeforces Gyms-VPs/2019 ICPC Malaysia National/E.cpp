/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: E.cpp
// Time created: Fri May 31 2019 14:25

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
int T, N; vector<int> A;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> T; if (T == 0) exit(0);
	cin >> N; A.clear(); A.resize(N);
	for (auto &z: A) cin >> z;
}

void Solve() {
	vector<vector<vector<int>>> vis(N, vector<vector<int>>(T+1));
	if (A[0] <= T) vis[0][A[0]].push_back(0);
	for (int i=0; i<N-1; i++) {
		for (int j=0; j<=T; j++) {
			if (vis[i][j].empty() && j != 0) continue;
			if (vis[i+1][j].empty()) vis[i+1][j] = vis[i][j];
			else vis[i+1][j] = min(vis[i+1][j], vis[i][j]);
			if (j + A[i+1] <= T) {
				vector<int> Tmp = vis[i][j]; Tmp.push_back(i+1);
				if (vis[i+1][j+A[i+1]].empty()) vis[i+1][j+A[i+1]] = Tmp;
				else vis[i+1][j+A[i+1]] = min(vis[i+1][j+A[i+1]], Tmp);
			}
		}
	}
	for (int i=T; i>=0; i--) {
		if (vis[N-1][i].empty() && i != 0) continue;
		for (auto z: vis[N-1][i]) cout << A[z] << " ";
		cout << i << endl; return;
	}
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
	while(true) {Input(); Solve();}
	
	return 0;
}
/************************************/