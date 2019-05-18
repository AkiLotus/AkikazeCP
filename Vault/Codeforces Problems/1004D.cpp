/********************************************************
*||  Code written by Akikaze                          ||*
*||  Duy-Bach Le, #Team4T's Chief Executor            ||*
*||  #Team4T Tertiary Flagship - Oblivion             ||*
*||                                                   ||*
*||  Written by a random fan of momocashew and Chiho  ||*
********************************************************/

/***********************************************
** File name: 1004D.cpp
** Time created: Thu May 09 2019 11:13
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
int t; vector<int> a, cnt;
/************************************************/

/************** [FUNCTIONS] **************/
bool valid(int n, int m, int x, int y) {
	vector<int> freq(t+1, 0);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			int z = abs(x-i) + abs(y-j);
			freq[z]++;
			if (freq[z] > cnt[z]) return false;
		}
	}
	return true;
}

int Token = -1;

void Input() {
	cin >> t; cnt.resize(t+1, 0); a.resize(t);
	for (auto &z: a) {cin >> z; cnt[z]++; if (Token == -1) Token = z;}
}

void Solve() {
	int x = 0;
	for (int i=1; i<=t; i++) {
		if (cnt[i] != i * 4) {
			x = i; break;
		}
	}
	int b = *max_element(a.begin(), a.end());
	for (int n=1; n<=sqrt(t); n++) {
		if (t % n != 0) continue;
		int m = t / n;
		int y = n + m - b - x;
		if (1 <= x && x <= n && 1 <= y && y <= m
		&& valid(n, m, x, y)) {
			cout << n << " " << m << endl;
			cout << x << " " << y << endl; return;
		}
		if (1 <= x && x <= n && 1 <= y && y <= m
		&& valid(n, m, y, x)) {
			cout << n << " " << m << endl;
			cout << y << " " << x << endl; return;
		}
	}
	cout << "-1\n";
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