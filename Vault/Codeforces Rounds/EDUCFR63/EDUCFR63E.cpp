/********************************************************
*||  Code written by Akikaze                          ||*
*||  Duy-Bach Le, #Team4T's Chief Executor            ||*
*||  #Team4T Tertiary Flagship - Oblivion             ||*
*||                                                   ||*
*||  Written by a random fan of momocashew and Chiho  ||*
********************************************************/

/***********************************************
** File name: EDUCFR63E.cpp
** Time created: Mon Apr 22 2019 14:33
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
const long long Mod = 1000003LL, INF = 1e9, LINF = 1e18;
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

void ConfigMonitor();
char infile[] = "FILE.IN";
char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
vector<int> a, fes;
vector<vector<int>> aes;
/************************************************/

/************** [FUNCTIONS] **************/
int f(int x) {
	x %= Mod; while (x < 0) x += Mod;
	int z = 1, ans = 0;
	for (int i=0; i<=10; i++) {
		ans = (ans + (1LL * z * a[i]) % Mod) % Mod;
		z = (1LL * z * x) % Mod;
	}
	return ans;
}

int modPow(int a, int b, int res = 1) {
	while (b > 0) {
		if (b & 1) {b--; res = (1LL * res * a) % Mod;}
		b >>= 1; a = (1LL * a * a) % Mod;
	}
	return res;
}

void GaussianElimination() {
	for (int i=0; i<10; i++) {
		for (int j=i+1; j<=10; j++) {
			int Mul = (1LL * (Mod - aes[j][i]) * modPow(aes[i][i], Mod-2)) % Mod;
			for (int x=0; x<=10; x++) aes[j][x] = (0LL + aes[j][x] + 1LL * aes[i][x] * Mul) % Mod;
			fes[j] = (0LL + fes[j] + 1LL * fes[i] * Mul) % Mod;
		}
	}
	for (int i=10; i>0; i--) {
		for (int j=i-1; j>=0; j--) {
			int Mul = (1LL * (Mod - aes[j][i]) * modPow(aes[i][i], Mod-2)) % Mod;
			for (int x=0; x<=10; x++) aes[j][x] = (0LL + aes[j][x] + 1LL * aes[i][x] * Mul) % Mod;
			fes[j] = (0LL + fes[j] + 1LL * fes[i] * Mul) % Mod;
		}
	}
	for (int i=0; i<=10; i++) a[i] = (1LL * fes[i] * modPow(aes[i][i], Mod-2)) % Mod;
}

void Input() {
	a.resize(11, 0); fes.resize(11, 0);
	aes.resize(11, vector<int>(11, 0));
}

void Solve() {
	for (int i=0; i<=10; i++) {
		for (int j=0; j<=10; j++) {
			if (j == 0) aes[i][j] = 1;
			else aes[i][j] = (1LL * aes[i][j-1] * i) % Mod;
		}
		cout << "? " << i << endl; fflush(stdout);
		cin >> fes[i];
		if (fes[i] == -1) exit(-4);
	}
	GaussianElimination();
	for (int i=0; i<Mod; i++) {
		if (f(i) == 0) {
			cout << "! " << i << endl;
			fflush(stdout); return;
		}
	}
	cerr << "! -1\n";
	cout << "! -1\n"; fflush(stdout);
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