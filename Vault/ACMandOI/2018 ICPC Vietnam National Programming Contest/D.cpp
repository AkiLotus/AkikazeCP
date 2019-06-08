/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: D.cpp
// Time created: Fri Jun 07 2019 11:05

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

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
string s, ans; int cnt;
/************************************************/

/************** [FUNCTIONS] **************/
bool isLeap(int x) {
	if (x % 100 == 0 && x % 400 != 0) return false;
	if (x % 4 == 0) return true; return false;
}

bool valid(string str) {
	int d = (str[0] - 48) * 10 + (str[1] - 48);
	int m = (str[2] - 48) * 10 + (str[3] - 48);
	int y = (str[4] - 48) * 1000 + (str[5] - 48) * 100 + (str[6] - 48) * 10 + (str[7] - 48) * 1;
	if (y < 2000) return false;
	if (m < 1 || m > 12) return false;
	if (d < 1 || d > 31) return false;
	if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return false;
	if (m == 2) {
		if (isLeap(y) && d > 29) return false;
		if (!isLeap(y) && d > 28) return false;
	}
	return true;
}

bool earlier(string str) {
	int d1 = (str[0] - 48) * 10 + (str[1] - 48);
	int m1 = (str[2] - 48) * 10 + (str[3] - 48);
	int y1 = (str[4] - 48) * 1000 + (str[5] - 48) * 100 + (str[6] - 48) * 10 + (str[7] - 48) * 1;
	int d2 = (ans[0] - 48) * 10 + (ans[1] - 48);
	int m2 = (ans[2] - 48) * 10 + (ans[3] - 48);
	int y2 = (ans[4] - 48) * 1000 + (ans[5] - 48) * 100 + (ans[6] - 48) * 10 + (ans[7] - 48) * 1;
	if (y1 != y2) return (y1 < y2);
	if (m1 != m2) return (m1 < m2);
	return (d1 < d2);
}

string Process(string str) {
	str.insert(4, " ");
	str.insert(2, " ");
	return str;
}

void Input() {
	getline(cin, s); ans = "#"; cnt = 0;
}

void Solve() {
	s.erase(5, 1); s.erase(2, 1);
	sort(s.begin(), s.end());
	do {
		if (valid(s)) {
			cnt++;
			if (ans == "#") ans = s;
			else if (earlier(s)) ans = s;
		}
	} while (next_permutation(s.begin(), s.end()));
	if (cnt == 0) {cout << "0\n"; return;}
	cout << cnt << " " << Process(ans) << endl;
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