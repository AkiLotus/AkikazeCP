/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: A.cpp
// Time created: Fri May 31 2019 14:26

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
int n; string s; vector<vector<char>> A;
/************************************************/

/************** [FUNCTIONS] **************/
void rotateRight(vector<vector<char>> &mat1) {
	vector<vector<char>> mat0 = mat1;
	int dim = mat1.size();
	for (int i=0; i<dim; i++) {
		for (int j=0; j<dim; j++) {
			int x = (dim - 1 - j);
			int y = i;
			if (mat1[i][j] == '.') mat0[x][y] = '.';
			if (mat1[i][j] == '^') mat0[x][y] = '<';
			if (mat1[i][j] == 'v') mat0[x][y] = '>';
			if (mat1[i][j] == '<') mat0[x][y] = 'v';
			if (mat1[i][j] == '>') mat0[x][y] = '^';
		}
	}
	mat1 = mat0;
}

void Input() {
	cin >> n >> s; A.resize(n, vector<char>(n, '.'));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> A[i][j];
		}
	}
}

void Solve() {
	int iter = 0;
	for (auto cmd: s) iter += (1 + (cmd == 'R') * 2);
	for (int i=0; i<(iter % 4); i++) rotateRight(A);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << A[i][j];
		}
		cout << endl;
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
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/