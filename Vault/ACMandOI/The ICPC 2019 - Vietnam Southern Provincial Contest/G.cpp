/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: E.cpp
// Time created: Sun Oct 13 2019 02:40

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

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
i64 n, S; vector<i64> l;
map<i64, vector<int>> position;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> n >> S; l.resize(n);
	for (int i=0; i<n; i++) {
		cin >> l[i];
		position[l[i]].push_back(i + 1);
	}
}

void Solve() {
	vector<i64> List;
	pair<i64, vector<int>> answer = {0, vector<int>(0)};
	for (auto it=position.begin(); it!=position.end(); it++) {
		i64 x = it->first;
		if (position[x].size() >= 4 && x <= S / x) {
			vector<int> tmp;
			for (int i=0; i<4; i++) tmp.push_back(-position[x][i]);
			answer = max(answer, {x * x, tmp});
		}
		if (position[x].size() >= 2) List.push_back(x);
	}
	int m = List.size();
	for (int i=0; i<m; i++) {
		i64 maximumAllowed = S / List[i];
		int j = upper_bound(List.begin(), List.end(), maximumAllowed) - List.begin();
		if (j-1 <= i) continue;
		vector<int> tmp;
		for (int x=0; x<2; x++) tmp.push_back(-position[List[i]][x]);
		for (int x=0; x<2; x++) tmp.push_back(-position[List[j-1]][x]);
		sort(tmp.rbegin(), tmp.rend());
		answer = max(answer, {List[i] * List[j-1], tmp});
	}
	if (answer.first == 0) cout << "-1";
	else for (auto z: answer.second) cout << -z << " ";
	cout << endl;
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	#ifndef Akikaze
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
