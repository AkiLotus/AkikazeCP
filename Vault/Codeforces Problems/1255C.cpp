/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: 1255C.cpp
// Time created: Wed Nov 20 2019 15:30

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
int n; vector<vector<int>> triplets;
vector<bool> considered;
vector<int> cnt; vector<vector<int>> occurences;
/************************************************/

/************** [FUNCTIONS] **************/
int findTriplet(int a, int b) {
	for (auto z: occurences[a]) {
		if (considered[z]) continue;
		if (find(occurences[b].begin(), occurences[b].end(), z) == occurences[b].end()) continue;
		return z;
	}
	return -1;
}

void Input() {
	cin >> n; triplets.resize(n-2, vector<int>(3));
	considered.resize(n-2, false);
	cnt.resize(n, 0); occurences.resize(n);
	for (int i=0; i<n-2; i++) {
		for (auto &z: triplets[i]) {
			cin >> z; z--; cnt[z]++;
			occurences[z].push_back(i);
		}
	}
}

void Solve() {
	vector<int> perm(1, min_element(cnt.begin(), cnt.end()) - cnt.begin());
	vector<int> firstSegment_copy = triplets[occurences[perm[0]][0]];
	firstSegment_copy.erase(find(firstSegment_copy.begin(), firstSegment_copy.end(), perm[0]));
	if (cnt[firstSegment_copy[0]] > cnt[firstSegment_copy[1]]) swap(firstSegment_copy[0], firstSegment_copy[1]);
	perm.push_back(firstSegment_copy[0]); perm.push_back(firstSegment_copy[1]);
	considered[occurences[perm[0]][0]] = true;
	for (int i=3; i<n; i++) {
		int nextTriplet = findTriplet(perm[i-2], perm[i-1]);
		vector<int> segCopy = triplets[nextTriplet];
		segCopy.erase(find(segCopy.begin(), segCopy.end(), perm[i-2]));
		segCopy.erase(find(segCopy.begin(), segCopy.end(), perm[i-1]));
		considered[nextTriplet] = true; perm.push_back(segCopy[0]);
	}
	for (auto z: perm) cout << (z + 1) << " "; cout << endl;
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