/**********************************************
*||  Code written by Akikaze                ||*
**********************************************/

/************** [OPTIMIZATION PROTOCOL] **************/
#pragma GCC optimize("Ofast")
/*****************************************************/

/************** [LIBRARY PROTOCOL] **************/
#include <bits/stdc++.h>
using namespace std;
/************************************************/

/************** [GNU OMISSIONS] **************/
#define y0 sha256_de0ae856ea00617a9c423b6433ffc2d30f6ae9a6ca895b98d1e77695103f795b
#define y1 sha256_f634ea7da526ace7777cae743c87abb8807b460ccc232a32ea3bf75808977c96
#define yn sha256_05d6f16fa922cf3f854808558ad3ac969e806d96f077683c9202be581197d97f
#define j1 sha256_3eb66ec36123550fa9e0e244db989634f234735d3bb78edf081cdd19cd9d2080
/*********************************************/

/************** [LEGENDS/CONSTANTS] **************/
#define endl '\n'
#define i64 long long
#define ld long double
const long long Mod = 1000000007LL, Inf = 1e9, LInf = 1e18;
const long double Pi = 3.141592653589793116L;
const long double Eps = 0.000000001L, Gold = ((1.0L+sqrt(5.0L))/2.0L);
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

/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	
}

void Solve() {
	
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