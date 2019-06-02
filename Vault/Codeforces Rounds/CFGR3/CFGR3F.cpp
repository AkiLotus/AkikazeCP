/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: CFGR3F.cpp
// Time created: Sat Jun 01 2019 14:20

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
int n; vector<int> val; vector<i64> mask;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> n; val.resize(n); mask.resize(n);
	for (int i=0; i<n; i++) cin >> val[i] >> mask[i];
}

void Solve() {
	int Min = 61, Max = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<62; j++) {
			if ((mask[i] >> j) & 1) {
				Min = min(Min, j);
				Max = max(Max, j);
			}
		}
	}
	i64 sum = 0;
	for (auto z: val) sum += z;
	for (int x=Min; x<=Max; x++) {
		for (int y=x; y<=Max; y++) {
			i64 s1 = ((1LL << x) | (1LL << y));
			i64 s2 = (((1LL << 62) - 1) ^ s1);
			i64 msum1 = 0, msum2 = 0;
			for (int i=0; i<n; i++) {
				int parity1 = __builtin_popcountll(mask[i] & s1) % 2;
				int parity2 = __builtin_popcountll(mask[i] & s2) % 2;
				msum1 += val[i] * (1 - 2 * parity1);
				msum2 += val[i] * (1 - 2 * parity2);
			}

			if (sum > 0 && msum1 < 0) {cout << s1 << endl; return;}
			if (sum < 0 && msum1 > 0) {cout << s1 << endl; return;}
			if (sum > 0 && msum2 < 0) {cout << s2 << endl; return;}
			if (sum < 0 && msum2 > 0) {cout << s2 << endl; return;}
		}
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