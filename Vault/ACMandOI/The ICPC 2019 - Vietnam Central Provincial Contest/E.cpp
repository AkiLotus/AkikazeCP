/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: E.cpp
// Time created: Sun Oct 06 2019 02:09

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
int n, m, bucket; set<int> Set; vector<int> a;
vector<vector<int>> Queries;
/************************************************/

/************** [FUNCTIONS] **************/
template <class T> struct BIT {
    vector<T> Tree;
    int maxVal;
    BIT(int maxValue) {
        maxVal = maxValue + 5;
        Tree.resize(maxVal);
    }
    
    void add(int i, T val) {
        for (; i < maxVal; i += i & -i) 
            Tree[i] += val;
    }
    
    T query(int i) {
        T ans = 0;
        for (; i > 0; i -= i & -i) ans += Tree[i];
        return ans;
    }
};

bool querysort(vector<int> A, vector<int> B) {
	if (A[0] / bucket != B[0] / bucket) return (A[0] / bucket < B[0] / bucket);
	return (A[1] < B[1]);
}

void Input() {
	cin >> n; a.resize(n); bucket = sqrt(n);
	for (auto &z: a) {cin >> z; Set.insert(z);}
	cin >> m; Queries.resize(m);
	int id = 0;
	for (auto &Q: Queries) {
		int l, r, x, y; cin >> l >> r >> x >> y; l--; r--;
		Q.push_back(l); Q.push_back(r); Q.push_back(x); Q.push_back(y);
		Q.push_back(id); id = id + 1;
	}
}

void Solve() {
	sort(Queries.begin(), Queries.end(), querysort);
	map<int, int> Map; int N = 0;
	for (auto it=Set.begin(); it!=Set.end(); it++) {Map[*it] = N; N++;}
	for (auto &z: a) z = Map[z];
	vector<int> cnt(N, 0), result(m, 0);
	int ptr1 = 0, ptr2 = -1;
	BIT<int> ST = BIT<int>(n+2);
	int offset = 1;
	for (auto &Q: Queries) {
		int l = Q[0], r = Q[1], x = Q[2], y = Q[3], id = Q[4];
		while (ptr2 < r) {ptr2++; ST.add(cnt[a[ptr2]]+offset, -1); cnt[a[ptr2]]++; ST.add(cnt[a[ptr2]]+offset, +1);}
		while (ptr2 > r) {ST.add(cnt[a[ptr2]]+offset, -1); cnt[a[ptr2]]--; ST.add(cnt[a[ptr2]]+offset, +1); ptr2--;}
		while (ptr1 > l) {ptr1--; ST.add(cnt[a[ptr1]]+offset, -1); cnt[a[ptr1]]++; ST.add(cnt[a[ptr1]]+offset, +1);}
		while (ptr1 < l) {ST.add(cnt[a[ptr1]]+offset, -1); cnt[a[ptr1]]--; ST.add(cnt[a[ptr1]]+offset, +1); ptr1++;}
		result[id] = ST.query(y+1) - ST.query(x);
	}
	for (auto &z: result) cout << z << endl;
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
	
	//ios_base::sync_with_stdio(false);
	//if (!Interactive) cin.tie(NULL);
	
	int T = 1; if (MultiTest) {cin >> T; cin.ignore();}
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/