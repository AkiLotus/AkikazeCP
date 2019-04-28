/********************************************************
*||  Code written by Akikaze                          ||*
*||  Duy-Bach Le, #Team4T's Chief Executor            ||*
*||  #Team4T Tertiary Flagship - Oblivion             ||*
*||                                                   ||*
*||  Written by a random fan of momocashew and Chiho  ||*
********************************************************/

/***********************************************
** File name: CFR553D2C.cpp
** Time created: Sun Apr 28 2019 12:18
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
i64 l, r;
/************************************************/

/************** [FUNCTIONS] **************/
i64 modPow(i64 a, i64 b, i64 res = 1) {
	while (b > 0) {
		if (b & 1) {res *= a; res %= Mod;}
		b >>= 1; a *= a; a %= Mod;
	}
	return res;
}

i64 findSum(i64 z) {
	if (z == 0) return 0;
	i64 accumulated = 0, size = 1, parity = 1;
	i64 oddcnt = 0, evencnt = 0;
	while (accumulated < z) {
		i64 toAppend = min(size, z - accumulated);
		if (parity == 1) oddcnt += toAppend;
		else evencnt += toAppend;
		size *= 2; accumulated += toAppend; parity = 1 - parity;
	}

	i64 evensum = 0, oddsum = 0;
	evensum = (((evencnt % Mod) * ((evencnt + 1) % Mod)) % Mod);
	oddsum = (((((oddcnt % Mod) * ((oddcnt + 1) % Mod)) % Mod)) - oddcnt + Mod * 4) % Mod;

	i64 ans = (evensum + oddsum) % Mod;
	return ans;
}

void Input() {
	cin >> l >> r;
}

void Solve() {
	i64 sumR = findSum(r);
	i64 sumL = findSum(l - 1);
	i64 ans = ((sumR - sumL) % Mod + Mod * 4) % Mod;
	cout << ans << endl;
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