/********************************************************
*||  Code written by Akikaze                          ||*
*||  Duy-Bach Le, #Team4T's Chief Executor            ||*
*||  #Team4T Tertiary Flagship - Oblivion             ||*
*||                                                   ||*
*||  Written by a random fan of momocashew and Chiho  ||*
********************************************************/

/***********************************************
** File name: 2-Draupnir.cpp
** Time created: Sun Apr 28 2019 16:52
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
int Interactive = 1;

void ConfigMonitor();
char infile[] = "FILE.IN";
char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
i64 ans224, ans56;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cout << "224\n"; fflush(stdout);
	cin >> ans224; if (ans224 == -1) exit(0);
	cout << "56\n"; fflush(stdout);
	cin >> ans56; if (ans56 == -1) exit(0);
}

void Solve() {
	i64 R6 = (ans224 >> 37) % (1LL << 7);
	i64 R5 = (ans224 >> 44) % (1LL << 7);
	i64 R4 = (ans224 >> 56) % (1LL << 7);

	ans56 -= ((R6) << 9);
	ans56 -= ((R5) << 11);
	ans56 -= ((R4) << 14);

	i64 R3 = (ans56 >> 18) % (1LL << 7);
	i64 R2 = (ans56 >> 28) % (1LL << 7);
	i64 R1 = (ans56 >> 56) % (1LL << 7);
	cout << R1 << " " << R2 << " " << R3 << " " << R4 << " " << R5 << " " << R6 << " " << endl; fflush(stdout);
	int verdict; cin >> verdict; if (verdict == -1) exit(0);
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	ConfigMonitor();
	ios_base::sync_with_stdio(false);
	if (!Interactive) cin.tie(NULL);
	
	int T = 1, W; if (MultiTest) cin >> T >> W;
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