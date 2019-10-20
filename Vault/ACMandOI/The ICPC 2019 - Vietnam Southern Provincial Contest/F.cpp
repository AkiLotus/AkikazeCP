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
int n; vector<pair<int, int>> A;
int maxValue = 0;
/************************************************/

/************** [FUNCTIONS] **************/
void compress(vector<pair<int, int>> &A) {
	set<int> Set; map<int, int> Map;
	for (int i=0; i<A.size(); i++) {
		Set.insert(A[i].first);
		Set.insert(A[i].second);
	}
	for (auto it=Set.begin(); it!=Set.end(); it++) {
		int x = *it; Map[x] = maxValue; maxValue++;
	}
	for (int i=0; i<A.size(); i++) {
		A[i].first = Map[A[i].first];
		A[i].second = Map[A[i].second];
	}
}

int getAns(vector<pair<int, int>> A) {
	vector<int> chroma(maxValue, -1);
	for (int i=0; i<n; i++) {
		for (int x=A[i].first; x<=A[i].second; x++) {
			chroma[x] = i;
		}
	}
	set<int> S;
	for (auto &z: chroma) {
		if (z != -1) S.insert(z);
	}
	return S.size();
}

bool segmentsort1(pair<int, int> x, pair<int, int> y) {
	if (x.first <= y.first && y.second <= x.second) return true;
	if (y.first <= x.first && x.second <= y.second) return false;
	if (x.second != y.second) return (x.second < y.second);
	return (x.first < y.first);
}

bool segmentsort2(pair<int, int> x, pair<int, int> y) {
	if (x.first <= y.first && y.second <= x.second) return true;
	if (y.first <= x.first && x.second <= y.second) return false;
	if (x.second != y.second) return (x.second < y.second);
	return (x.first > y.first);
}

bool segmentsort3(pair<int, int> x, pair<int, int> y) {
	if (x.first <= y.first && y.second <= x.second) return true;
	if (y.first <= x.first && x.second <= y.second) return false;
	if (x.second != y.second) return (x.second > y.second);
	return (x.first < y.first);
}

bool segmentsort4(pair<int, int> x, pair<int, int> y) {
	if (x.first <= y.first && y.second <= x.second) return true;
	if (y.first <= x.first && x.second <= y.second) return false;
	if (x.second != y.second) return (x.second > y.second);
	return (x.first > y.first);
}

bool segmentsort5(pair<int, int> x, pair<int, int> y) {
	if (x.first <= y.first && y.second <= x.second) return true;
	if (y.first <= x.first && x.second <= y.second) return false;
	if (x.first != y.first) return (x.first < y.first);
	return (x.second < y.second);
}

bool segmentsort6(pair<int, int> x, pair<int, int> y) {
	if (x.first <= y.first && y.second <= x.second) return true;
	if (y.first <= x.first && x.second <= y.second) return false;
	if (x.first != y.first) return (x.first < y.first);
	return (x.second > y.second);
}

bool segmentsort7(pair<int, int> x, pair<int, int> y) {
	if (x.first <= y.first && y.second <= x.second) return true;
	if (y.first <= x.first && x.second <= y.second) return false;
	if (x.first != y.first) return (x.first > y.first);
	return (x.second < y.second);
}

bool segmentsort8(pair<int, int> x, pair<int, int> y) {
	if (x.first <= y.first && y.second <= x.second) return true;
	if (y.first <= x.first && x.second <= y.second) return false;
	if (x.first != y.first) return (x.first > y.first);
	return (x.second > y.second);
}

void Input() {
	cin >> n; A.resize(n);
	for (int i=0; i<n; i++) cin >> A[i].first >> A[i].second;
}

void Solve() {
	compress(A);
	int ans = 0;
	if (n <= 10) {
		vector<int> p(n);
		for (int i=0; i<n; i++) p[i] = i;
		do {
			vector<int> chroma(maxValue, -1);
			for (int i=0; i<n; i++) {
				for (int x=A[p[i]].first; x<=A[p[i]].second; x++) {
					chroma[x] = i;
				}
			}
			set<int> S;
			for (auto &z: chroma) {
				if (z != -1) S.insert(z);
			}
			ans = max(ans, (int)S.size());
		} while (next_permutation(p.begin(), p.end()));
	}
	else {
		sort(A.begin(), A.end(), segmentsort1);
		ans = max(ans, getAns(A));
		sort(A.begin(), A.end(), segmentsort2);
		ans = max(ans, getAns(A));
		sort(A.begin(), A.end(), segmentsort3);
		ans = max(ans, getAns(A));
		sort(A.begin(), A.end(), segmentsort4);
		ans = max(ans, getAns(A));
		sort(A.begin(), A.end(), segmentsort5);
		ans = max(ans, getAns(A));
		sort(A.begin(), A.end(), segmentsort6);
		ans = max(ans, getAns(A));
		sort(A.begin(), A.end(), segmentsort7);
		ans = max(ans, getAns(A));
		sort(A.begin(), A.end(), segmentsort8);
		ans = max(ans, getAns(A));
	}
	cout << ans << endl;
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
