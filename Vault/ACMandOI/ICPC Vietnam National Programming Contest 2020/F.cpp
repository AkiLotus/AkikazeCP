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
int MultiTest = 0;
int Interactive = 1;

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int d = INF;
string commands[] = {"UU", "UR", "RR", "RD", "DD", "DL", "LL", "LU"};
int direction = 0; // 0=L, 1=U, 2=R, 3=D
/************************************************/

/************** [FUNCTIONS] **************/
int performMove(string directions) {
	cout << directions.size() << " " << directions << endl;
	cout.flush();

	int new_distance; cin >> new_distance;
	return new_distance;
}

int performCatch() {
	int coin = rng32() % 4;
	if (d == 1) {
		string dir[] = {"L", "U", "R", "D"};
		return performMove(dir[coin]);
	}
	if (d == 2) {
		string dir[] = {"LU", "LD", "RU", "RD"};
		return performMove(dir[coin]);
	}
	if (d == 4) {
		string dir[] = {"LL", "UU", "RR", "DD"};
		return performMove(dir[coin]);
	}
	if (d == 3) {return -1;} // blame pvh for this error
	return -1; // blame pvh for this also
}

void Input() {
	
}

void Solve() {
	int remaining_move = 10000;
	while (remaining_move--) {
		if (d <= 4) {
			int new_dist = performCatch();
			if (new_dist == 0) return;
			else d = new_dist;
		}
		else {
			int new_dist = performMove(commands[direction]);

			if (new_dist > d) {
				int tmp = 9;
				do {tmp = rng32() % 8;} while (tmp == direction);
				direction = tmp;
			}

			d = new_dist;
		}
	}
	exit(4);
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