/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: L.cpp
// Time created: Sat Oct 19 2019 10:27

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

/************** [MASTER CONTROLS - PHASE 1] **************/
int OImode = 0;
int MultiTest = 0;
int Interactive = 0;

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/

/************************************************/

/************** [FUNCTIONS] **************/
vector <pair<int,int> > d;
vector <vector<int> > a;
vector <vector<int> > col, sum;
int n, m, k;
long long c[200005];

void Input() {
	cin >> m >> n >> k;
	d.resize(k+5);
	a.resize(m+5);
	// for (int i = 0; i < m+5; i++) a[i].resize(2*n+5);

	for (int i = 0; i < k; i++) cin >> d[i].first >> d[i].second;
	for (int i = 0; i < m; i++) {
		cout << i << endl;
		for (int j = 0; j < 2*n; j++) {
			int x; cin >> x;
			a[i].push_back(x);
		}
	}
}

long long cost(int i, int j) { // col i desk j
	int lo = d[j].first, hi = d[j].second;
	int l = 0, r = 2*m - 1;
	int u = -1, v = 2*m;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (col[j][mid] < lo) {
			u = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	l = 0, r = 2*m - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (col[j][mid] > hi) {
			v = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	int ans1, ans2;
	if (u == -1) ans1 = 0; else ans1 = lo*(u + 1) - sum[j][u+1];
	if (v == 2*m) ans2 = 0; else ans2 = sum[j][2*m-1] - sum[j][v];
	return (ans1 + ans2); 

}

long long Try(int i, int j, int u, int v) {
	tracker4(i, j, u, v);
	int mid = (i+j) / 2;

	long long mn = LINF;
	for (int k = u; k <= v; k++) {
		c[k] = cost(mid, k);
		mn = min(mn, c[k]);
	}
	int lo = INF, hi = -1;
	for (int k = u; k <= v; k++) {
		if (c[k] == mn) {
			lo = min(lo, k); hi = max(hi, k);
		}
	}
	tracker3(mn, u, v);
	if (i == j) return mn;
	else if (i == j - 1) return mn +Try(mid + 1, j, hi, v);
	else return mn + Try(i, mid - 1, u, lo) + Try(mid + 1, j, hi, v);
}


void Solve() {
	col.resize(n+5);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 2*n; j++) col[j/2].push_back(a[i][j]);
	}
	for (int j = 0; j < n; j++) sort(col[j].begin(), col[j].end());
	
	sum.resize(n+5);
	for (int j = 0; j < n; j++) {
		sum[j].push_back(0);
		for (int i = 0; i < 2*m; i++) 
			sum[j].push_back(col[j][i] + sum[j].back());
	}
	cout << Try(0, n - 1, 0, k -1) << endl;

}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	
	
	Input(); Solve();
	
	return 0;
}
/************************************/