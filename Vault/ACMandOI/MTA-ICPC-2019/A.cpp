/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: A.cpp
// Time created: Sat Oct 19 2019 08:04

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
/*************************************************/

/************** [MASTER CONTROLS - PHASE 1] **************/
int OImode = 0;
int MultiTest = 1;
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
        Tree.resize(maxVal, 0);
    }
    
    void add(int i, T val) {
		Tree[i] = max(Tree[i], val);
        for (; i < maxVal; i += i & -i) 
            Tree[i] = max(Tree[i], val);;
    }
    
    T query(int i) {
        T ans = 0;
        for (; i > 0; i -= i & -i) ans = max(ans, Tree[i]);
        return ans;
    }
};

//  BIT <int> q(maxValue);
//  for ... q.add(x, 1);
//  q.query(x);

void Input() {
	cin >> n; a.clear(); a.resize(n);
	for (int i=0; i<n; i++) cin >> a[i];
}

void Solve() {
	vector<pair<int, int> > b;
	for (int i=0; i<n; i++) b.push_back(make_pair(a[i], i));
	sort(b.begin(), b.end());
	int value = 0;
	for (int i=0; i<n; i++) {
		if (i == 0 || b[i].first > b[i-1].first) value++;
		int id = b[i].second; a[id] = value;
	}



	vector <int> M, C;
	M.resize(n+5); C.resize(n+5);
	
	vector <vector <pair<int, int> > > G;
	G.resize(n+5);
	BIT <int> BB(n+5);
	int i = 0;
	M[i] = 1; C[i] = 1;
	BB.add(a[i], M[i]);
	G[M[i]].push_back(make_pair(a[i], C[i]));
	if (G[M[i]].size() > 1) {
		int x = G[M[i]].size();
		G[M[i]][x-1].second += G[M[i]][x-2].second; 
	}
	G[0].push_back(make_pair(0, 1));

	for (int i = 1; i < n; i++) {
		M[i] = BB.query(a[i]-1) + 1;

		int l = 0, r = G[M[i]-1].size() - 1, ans;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (G[M[i]-1][mid].first < a[i]) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		int x = M[i] - 1;
		if (ans == 0) C[i] = G[x][G[x].size() - 1].second;
		else C[i] = G[x][G[x].size() - 1].second - G[x][ans - 1].second + Mod;
		C[i] %= Mod;
		//
		BB.add(a[i], M[i]);
		G[M[i]].push_back(make_pair(a[i], C[i]));
		if (G[M[i]].size() > 1) {
			int x = G[M[i]].size();
			G[M[i]][x-1].second += G[M[i]][x-2].second; 
			G[M[i]][x-1].second %= Mod;
		}
	}
	long long tmp = 0, maxLen = 0;
	for (int i = 0; i < n; i++) {
		if (M[i] > maxLen) {
			maxLen = M[i];
			tmp = C[i];
		}
		else if (M[i] == maxLen) {
			tmp += C[i];
		}
		tmp %= Mod;
	}
	
	cout << tmp << endl;
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