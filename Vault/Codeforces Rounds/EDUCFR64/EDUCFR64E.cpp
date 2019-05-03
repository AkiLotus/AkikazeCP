/********************************************************
*||  Code written by Akikaze                          ||*
*||  Duy-Bach Le, #Team4T's Chief Executor            ||*
*||  #Team4T Tertiary Flagship - Oblivion             ||*
*||                                                   ||*
*||  Written by a random fan of momocashew and Chiho  ||*
********************************************************/

/***********************************************
** File name: EDUCFR64E.cpp
** Time created: Wed May 01 2019 13:58
***********************************************/

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

void ConfigMonitor();
char infile[] = "FILE.IN";
char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int n; vector<int> p, pos; vector<vector<int>> Table;
/************************************************/

/************** [FUNCTIONS] **************/
void ProcessTable() {
	Table.resize(n);
	for (int j=0; j<20; j++) {
		for (int i=0; i<n; i++) {
			if (i + (1 << j) > n) continue;
			if (j == 0) {Table[i].push_back(i); continue;}
			int id1 = Table[i][j-1];
			int id2 = Table[i + (1 << (j-1))][j-1];
			if (p[id1] > p[id2]) Table[i].push_back(id1);
			else Table[i].push_back(id2);
		}
	}
}

int maxarg(int L, int R) {
	int id = log2(R - L + 1);
	int p1 = Table[L][id];
	int p2 = Table[R+1 - (1 << id)][id];
	if (p[p1] > p[p2]) return p1;
	return p2;
}

i64 count(int L, int R) {
	if (L > R) return 0LL;
	int MA = maxarg(L, R);
	int Max = p[MA];
	i64 res = count(L, MA-1) + count(MA+1, R);
	int x = L, y = MA-1;
	if ((MA-L) > (R-MA)) {x = MA+1; y = R;}
	for (int id=x; id<=y; id++) {
		int posreq = pos[Max - p[id]];
		res += (L <= posreq && posreq <= R && !(x <= posreq && posreq <= y));
	}
	return res;
}

void Input() {
	cin >> n; p.resize(n); pos.resize(n+1);
	for (int i=0; i<n; i++) {cin >> p[i]; pos[p[i]] = i;}
}

void Solve() {
	ProcessTable();
	cout << count(0, n-1) << endl;
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	ConfigMonitor();
	ios_base::sync_with_stdio(false);
	if (!Interactive) cin.tie(NULL);
	
	int T = 1; if (MultiTest) cin >> T;
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/

/************** [MASTER CONTROLS - PHASE 2] **************/
void ConfigMonitor() {
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
}
/*********************************************************/