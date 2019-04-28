/********************************************************
*||  Code written by Akikaze                          ||*
*||  Duy-Bach Le, #Team4T's Chief Executor            ||*
*||  #Team4T Tertiary Flagship - Oblivion             ||*
*||                                                   ||*
*||  Written by a random fan of momocashew and Chiho  ||*
********************************************************/

/***********************************************
** File name: CFGR2F.cpp
** Time created: Sat Apr 06 2019 17:16
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
int MultiTest = 1;
int Interactive = 0;

void ConfigMonitor();
char infile[] = "FILE.IN";
char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int n; string s;; int test = 0;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> n >> s; test++;
}

void Solve() {
	int cnts = 0, cnte = 0;
	for (auto z: s) {
		cnts += (z == 'S');
		cnte += (z == 'E');
	}
	cout << "Case #" << test << ": ";
	if (s[0] != s[n*2-3]) {
		if (s[0] == 'E') {
			for (int i=0; i<cnts; i++) cout << "S";
			for (int i=0; i<cnte; i++) cout << "E";
		}
		else {
			for (int i=0; i<cnte; i++) cout << "E";
			for (int i=0; i<cnts; i++) cout << "S";
		}
		cout << endl; return;
	}
	if (s[0] == 'S') {
		int x = 0, y = 0; map<int, int> Map;
		for (auto z: s) {
			if (z == 'E') {y++; continue;}
			x++; Map[y]++;
		}
		int id = 0; while (Map[id]) id++;
		for (int i=0; i<id; i++) cout << "E";
		for (int i=0; i<cnts; i++) cout << "S";
		for (int i=id; i<cnte; i++) cout << "E";
		cout << endl; return;
	}
	if (s[0] == 'E') {
		int x = 0, y = 0; map<int, int> Map;
		for (auto z: s) {
			if (z == 'S') {x++; continue;}
			y++; Map[x]++;
		}
		int id = 0; while (Map[id]) id++;
		for (int i=0; i<id; i++) cout << "S";
		for (int i=0; i<cnte; i++) cout << "E";
		for (int i=id; i<cnts; i++) cout << "S";
		cout << endl; return;
	}
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
