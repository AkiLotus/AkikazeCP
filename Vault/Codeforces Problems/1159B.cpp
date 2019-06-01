/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: 1159B.cpp
// Time created: Sun May 19 2019 11:14

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
int n; vector<pair<int, int>> a;
/************************************************/

/************** [FUNCTIONS] **************/
bool valid(int k) {
	vector<bool> vis(n, false);
	int L = 0, R = n-1;
	for (auto Pair: a) {
		int val = Pair.first, id = Pair.second;
		vis[id] = true;
		while (L <= R && vis[L]) L++;
		while (L <= R && vis[R]) R--;
		if (L > R) break;
		if (1LL * k * abs(id - L) > val) return false;
		if (1LL * k * abs(id - R) > val) return false;
	}
	return true;
}

int binsearch(int L, int R) {
	int res = L;
	while (L <= R) {
		int mid = (0LL + L + R) / 2;
		if (valid(mid)) {res = mid; L = mid + 1;}
		else R = mid - 1;
	}
	return res;
}

void Input() {
	cin >> n; a.resize(n); int id = 0;
	for (auto &Pair: a) {
		cin >> Pair.first;
		Pair.second = id++;
	}
}

void Solve() {
	sort(a.begin(), a.end());
	cout << binsearch(0, 2000000000) << endl;
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