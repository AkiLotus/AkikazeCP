/********************************************************
*||  Code written by Akikaze                          ||*
*||  Duy-Bach Le, #Team4T's Chief Executor            ||*
*||  #Team4T Tertiary Flagship - Oblivion             ||*
*||                                                   ||*
*||  Written by a random fan of momocashew and Chiho  ||*
********************************************************/

/***********************************************
** File name: CFR558D2B.cpp
** Time created: Thu May 09 2019 14:33
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
int cnt[100001]; map<int, int> Map;
/************************************************/

/************** [FUNCTIONS] **************/
bool validMap() {
	if (Map.size() == 1 && (Map.begin()->first == 1 || Map.begin()->second == 1)) return true;
	if (Map.size() != 2) return false;
	if (Map.size() == 2 && Map.begin()->first != 1) {
		int cnt1 = Map.begin()->second, cnt2 = Map.rbegin()->second;
		if ((cnt1 == cnt2 || cnt2 == 1) && Map.rbegin()->first - Map.begin()->first == 1) return true;
		return false;
	}
	int cnt1 = Map[1], cnt2 = Map.rbegin()->second;
	if (cnt1 == 1) return true;
	if (Map.rbegin()->first == 2 && cnt2 == 1) return true;
	return false;
}

void Input() {
	cin >> n; a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	int x = 0;
	for (int i=0; i<n; i++) {
		if (cnt[a[i]]) {
			Map[cnt[a[i]]]--;
			if (!Map[cnt[a[i]]]) Map.erase(cnt[a[i]]);
		}
		cnt[a[i]]++;
		Map[cnt[a[i]]]++;
		if (validMap()) x = max(x, i+1);
	}
	cout << x << endl;
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