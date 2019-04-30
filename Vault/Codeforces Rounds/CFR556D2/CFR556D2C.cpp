/********************************************************
*||  Code written by Akikaze                          ||*
*||  Duy-Bach Le, #Team4T's Chief Executor            ||*
*||  #Team4T Tertiary Flagship - Oblivion             ||*
*||                                                   ||*
*||  Written by a random fan of momocashew and Chiho  ||*
********************************************************/

/***********************************************
** File name: CFR556D2C.cpp
** Time created: Mon Apr 29 2019 14:31
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
int n; vector<int> a;
/************************************************/

/************** [FUNCTIONS] **************/
vector<int> GeneratePrime() {
	vector<bool> isPrime(400000, true);
	for (int i=2; i<400000; i++) {
		if (!isPrime[i]) continue;
		for (int j=2; j<=399999/i; j++) {
			isPrime[i*j] = false;
		}
	}
	vector<int> Prime;
	for (int i=2; i<400000; i++) {
		if (isPrime[i]) Prime.push_back(i);
	}
	return Prime;
}

void Input() {
	cin >> n; a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	vector<int> Prime = GeneratePrime();
	int One = 0, Two = 0;
	for (auto z: a) {One += (z == 1); Two += (z == 2);}
	int cur = 0, id = 0; vector<int> NewArr;
	while (id < Prime.size() && (One > 0 || Two > 0)) {
		int NextPrime = Prime[id];
		int TwoUsed = min(Two, (NextPrime - cur) / 2);
		int OneUsed = min(One, (NextPrime - cur) - 2 * TwoUsed);
		if (cur + OneUsed + TwoUsed * 2 < NextPrime) break;
		Two -= TwoUsed; One -= OneUsed; cur = NextPrime; id++;
		for (int x=0; x<TwoUsed; x++) NewArr.push_back(2);
		for (int x=0; x<OneUsed; x++) NewArr.push_back(1);
	}
	for (int x=0; x<Two; x++) NewArr.push_back(2);
	for (int x=0; x<One; x++) NewArr.push_back(1);
	for (auto z: NewArr) cout << z << " "; cout << endl;
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