/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: CFR574D2F.cpp
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
int n, bucket; vector<vector<pair<int, int>>> Poly;
vector<int> Start, End;
/************************************************/

/************** [FUNCTIONS] **************/
bool querysort(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
	if (x.first.first / bucket != y.first.first / bucket) return (x.first.first / bucket < y.first.first / bucket);
	return (x.first.second < y.first.second);
}

pair<int, int> CreateVector(pair<int, int> p1, pair<int, int> p2) {
	int dx = p2.first - p1.first, dy = p2.second - p1.second;
	if (dx == 0 && dy == 0) return make_pair(0, 0);
	if (dx == 0) {
		if (dy < 0) return make_pair(0, -1);
		else return make_pair(0, 1);
	}
	if (dy == 0) {
		if (dx < 0) return make_pair(-1, 0);
		else return make_pair(1, 0);
	}
	int g = __gcd(abs(dx), abs(dy));
	dx /= g; dy /= g;
	return make_pair(dx, dy);
}

void Input() {
	cin >> n; Poly.resize(n);
	Start.resize(n); End.resize(n);
	int enumerate = 0, id = 0;
	for (auto &P: Poly) {
		int k; cin >> k; P.resize(k);
		for (auto &z: P) cin >> z.first >> z.second;
		Start[id] = enumerate; End[id] = enumerate + k - 1;
		enumerate += k; id += 1;
	}
}

void Solve() {
	map<pair<int, int>, int> VecMap;
	vector<int> VecList;
	int enumerate = 0;
	for (auto &Pl: Poly) {
		int k = Pl.size();
		for (int i=0; i<k; i++) {
			pair<int, int> vec = CreateVector(Pl[i], Pl[(i+1) % k]);
			if (VecMap.find(vec) == VecMap.end()) VecMap[vec] = enumerate++;
			
			VecList.push_back(VecMap[vec]);
		}
	}
	
	int vecCount = VecList.size();
	bucket = sqrt(vecCount);
	vector<int> freq(enumerate, 0);
	
	int q; cin >> q; vector<pair<pair<int, int>, int>> Queries(q);
	vector<int> Result(q);
	for (int i=0; i<q; i++) {
		int l, r; cin >> l >> r; l--; r--;
		Queries[i] = make_pair(make_pair(Start[l], End[r]), i);
	}
	sort(Queries.begin(), Queries.end(), querysort);
	int ptr1 = 0, ptr2 = -1, cnt = 0;
	for (auto quer: Queries) {
		int id = quer.second, L = quer.first.first, R = quer.first.second;
		while (ptr1 < L) {
			freq[VecList[ptr1]]--;
			if (freq[VecList[ptr1]] == 0) cnt--;
			ptr1++;
		}
		while (ptr1 > L) {
			ptr1--; freq[VecList[ptr1]]++;
			if (freq[VecList[ptr1]] == 1) cnt++;
		}
		while (ptr2 < R) {
			ptr2++; freq[VecList[ptr2]]++;
			if (freq[VecList[ptr2]] == 1) cnt++;
		}
		while (ptr2 > R) {
			freq[VecList[ptr2]]--;
			if (freq[VecList[ptr2]] == 0) cnt--;
			ptr2--;
		}
		Result[id] = cnt;
	}
	for (auto z: Result) cout << z << endl;
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