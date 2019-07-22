/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: CFR574D2D1.cpp
// Time created: Wed Jul 17 2019 14:27

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
const long long Mod = 998244353LL, INF = 1e9, LINF = 1e18;
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

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int n; vector<pair<int, int>> A;
/************************************************/

/************** [FUNCTIONS] **************/
int intLength(int z) {
	if (z == 0) return 1;
	int res = 0;
	while (z > 0) {res++; z /= 10;}
	return res;
}

void Input() {
	cin >> n; A.resize(n);
	for (auto &P: A) {
		cin >> P.first;
		P.second = intLength(P.first);
	}
}

void Solve() {
	vector<int> lengthFrequency(11, 0);
	for (auto &P: A) lengthFrequency[P.second]++;

	int ans = 0;

	for (int i=0; i<n; i++) {
		int val = A[i].first;
		int len = A[i].second;
		for (int x=1; x<11; x++) {
			int freq = lengthFrequency[x];
			int tmp = val, power = 1, curLen = 0;
			// calculate right
			tmp = val; power = 1;
			while (tmp > 0) {
				ans += (1LL * (tmp % 10) * power * freq) % Mod; ans %= Mod;
				tmp /= 10; curLen++;
				if (curLen <= x) power = (1LL * power * 100) % Mod;
				else power = (1LL * power * 10) % Mod;
			}
			// calculate left
			tmp = val; power = 10; curLen = 0;
			while (tmp > 0) {
				ans += (1LL * (tmp % 10) * power * freq) % Mod; ans %= Mod;
				tmp /= 10; curLen++;
				if (curLen < x) power = (1LL * power * 100) % Mod;
				else power = (1LL * power * 10) % Mod;
			}
		}
	}

	cout << ans << endl;
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