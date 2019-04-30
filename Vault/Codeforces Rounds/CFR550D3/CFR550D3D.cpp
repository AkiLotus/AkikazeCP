/********************************************************
*||  Code written by Akikaze                          ||*
*||  Duy-Bach Le, #Team4T's Chief Executor            ||*
*||  #Team4T Tertiary Flagship - Oblivion             ||*
*||                                                   ||*
*||  Written by a random fan of momocashew and Chiho  ||*
********************************************************/

/***********************************************
** File name: CFR550D3D.cpp
** Time created: Tue Apr 30 2019 06:48
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


void Input() {
	cin >> n; a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	map<int, int> Map;
	for (auto z: a) Map[z]++;
	int freq = 0, ele = 0;
	for (auto z: a) {
		if (Map[z] > freq) {
			freq = Map[z];
			ele = z;
		}
	}
	vector<pair<int, int>> Ranges;
	for (int i=0; i<n; i++) {
		if (a[i] != ele) continue;
		int j = i;
		while (j+1 < n && a[j+1] == ele) j++;
		Ranges.push_back({i, j}); i = j;
	}
	Ranges.push_back({n, n});
	vector<pair<int, pair<int, int>>> Operations;
	for (int i=0; i<Ranges.size(); i++) {
		if (i == 0) {
			for (int x=Ranges[0].first-1; x>=0; x--) {
				if (a[x] < ele) Operations.push_back({1, {x+1, x+2}});
				else Operations.push_back({2, {x+1, x+2}});
			}
			continue;
		}
		for (int x=Ranges[i-1].second+1; x<Ranges[i].first; x++) {
			if (a[x] < ele) Operations.push_back({1, {x+1, x}});
			else Operations.push_back({2, {x+1, x}});
		}
	}
	cout << Operations.size() << endl;
	for (auto Token: Operations) {
		int t = Token.first;
		int i = Token.second.first;
		int j = Token.second.second;
		cout << t << " " << i << " " << j << endl;
	}
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