/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: H.cpp
// Time created: Sun Oct 06 2019 02:04

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
const long long Mod = 666777LL, INF = 1e9, LINF = 1e18;
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
int n, k;
/************************************************/

/************** [FUNCTIONS] **************/
typedef vector<vector<int>> matrix;
matrix matMul(matrix A, matrix B) {
	int n = A.size(), p = B.size(), m = B[0].size();
	matrix C = vector<vector<int>>(n, vector<int>(m, 0));
	for (int k=0; k<p; k++) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				C[i][j] += (1LL * A[i][k] * B[k][j]) % Mod;
				C[i][j] %= Mod;
			}
		}
	}
	return C;
}

matrix matPow(matrix A, int b) {
	matrix res = vector<vector<int>>(A.size(), vector<int>(A.size(), 0));
	for (int i=0; i<A.size(); i++) res[i][i] = 1;
	while (b > 0) {
		if (b & 1) res = matMul(res, A);
		A = matMul(A, A); b >>= 1;
	}
	return res;
}

void Input() {
	cin >> n >> k;
}

void Solve() {
	vector<vector<int>> Origin(1, vector<int>(k+1, 0)); Origin[0][0] = 1;
	vector<vector<int>> Trans(k+1, vector<int>(k+1, 0));
	for (int i=0; i<k+1; i++) Trans[i][0] = 1;
	for (int j=1; j<k+1; j++) Trans[j-1][j] = 1;
	vector<vector<int>> Aftermath = matMul(Origin, matPow(Trans, n));
	int res = 0; for (auto &z: Aftermath[0]) res = (res + z) % Mod;
	cout << res << endl;
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