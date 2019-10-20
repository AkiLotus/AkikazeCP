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
int n; vector<int> a;
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

i64 count_MinAtLeft(vector<int> a) {
	i64 res = 0;
	stack <int> S;

	vector<int> L(a.size()), R(a.size());
	
	// R[i] = k: -> a[k] < a[i] && k is maximum
	for (int i = 0; i < n; i++) {
		while (!S.empty() && a[S.top()] > a[i]) {
			R[S.top()] = i;
			S.pop();
		}
		S.push(i);
	}
	while (!S.empty()) {
		R[S.top()] = n;
		S.pop();
	}
	
	// L[i] = k -> a[k] > a[i] && k is minimum
	for (int i = n-1; i >= 0; i--) {
		while (!S.empty() && a[S.top()] < a[i]) {
			L[S.top()] = i;
			S.pop();
		}
		S.push(i);
	}
	while (!S.empty()) {
		L[S.top()] = -1;
		S.pop();
	}

	// query on R[]
	// query type: (L[i]+1, i-1, i): counting number of elements in R[L[i]+1:i] which is strictly larger than i
	vector<pair<int, int>> R_with_index(n);
	for (int i=0; i<n; i++) R_with_index[i] = make_pair(R[i], i);
	sort(R_with_index.rbegin(), R_with_index.rend());
	int ptr_onRWI = 0;
	BIT<int> ST = BIT<int>(n);
	for (int i=n-1; i>=0; i--) {
		int l = L[i] + 1, r = i-1, x = i;
		if (l > r) continue;
		while (ptr_onRWI < n && R_with_index[ptr_onRWI].first > x) {
			ST.add(R_with_index[ptr_onRWI].second + 1, +1);
			ptr_onRWI = ptr_onRWI + 1;
		}
		res += ST.query(r + 1);
		if (l > 0) res -= ST.query(l);
	}
	return res;
}

void Input() {
	scanf("%d", &n); a.resize(n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
}

void Solve() {
	i64 ans = 0;
	ans += count_MinAtLeft(a);
	reverse(a.begin(), a.end());
	ans += count_MinAtLeft(a);
	ans += n;
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
	
	int T = 1; if (MultiTest) {cin >> T; cin.ignore();}
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/
