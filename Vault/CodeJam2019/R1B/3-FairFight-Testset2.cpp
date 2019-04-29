/********************************************************
*||  Code written by Akikaze                          ||*
*||  Duy-Bach Le, #Team4T's Chief Executor            ||*
*||  #Team4T Tertiary Flagship - Oblivion             ||*
*||                                                   ||*
*||  Written by a random fan of momocashew and Chiho  ||*
********************************************************/

/***********************************************
** File name: 3-FairFight-Testset2.cpp
** Time created: Sun Apr 28 2019 17:37
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
int MultiTest = 1;
int Interactive = 0;

void ConfigMonitor();
char infile[] = "FILE.IN";
char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int n, k, test = 0; vector<int> c, d;
/************************************************/

/************** [FUNCTIONS] **************/
void PerformTable(vector<vector<int>> &TableC, vector<vector<int>> &TableD) {
	TableC.resize(n); TableD.resize(n);
	for (int j=0; j<20; j++) {
		for (int i=0; i<n; i++) {
			if (j == 0) {
				TableC[i].push_back(i);
				TableD[i].push_back(i);
				continue;
			}
			if (i + (1 << j) - 1 >= n) continue;

			int id1_C = TableC[i][j-1], id2_C = TableC[i + (1 << (j - 1))][j-1];
			int id1_D = TableD[i][j-1], id2_D = TableD[i + (1 << (j - 1))][j-1];

			if (c[id1_C] == c[id2_C]) TableC[i].push_back(min(id1_C, id2_C));
			else if (c[id1_C] > c[id2_C]) TableC[i].push_back(id1_C);
			else if (c[id1_C] < c[id2_C]) TableC[i].push_back(id2_C);

			if (d[id1_D] == d[id2_D]) TableD[i].push_back(min(id1_D, id2_D));
			else if (d[id1_D] > d[id2_D]) TableD[i].push_back(id1_D);
			else if (d[id1_D] < d[id2_D]) TableD[i].push_back(id2_D);
		}
	}
}

int GetMax(int L, int R, vector<vector<int>> &Table, vector<int> &arr) {
	int id = log2(R - L + 1);
	int p1 = Table[L][id];
	int p2 = Table[R - (1 << id) + 1][id];
	if (arr[p1] == arr[p2]) return min(p1, p2);
	if (arr[p1] > arr[p2]) return p1;
	if (arr[p1] < arr[p2]) return p2;
}

int binsearch_left_cenough(int top, int bot, int fixed, vector<vector<int>> &TableC, vector<vector<int>> &TableD) {
	int res = fixed + 1;
	while (top <= bot) {
		int mid = (top + bot) / 2;
		if (GetMax(mid, fixed, TableC, c) == fixed && 
			d[GetMax(mid, fixed, TableD, d)] <= c[fixed] + k) {
				res = mid; bot = mid - 1;
		}
		else top = mid + 1;
	}
	return res;
}

int binsearch_rght_cenough(int top, int bot, int fixed, vector<vector<int>> &TableC, vector<vector<int>> &TableD) {
	int res = fixed - 1;
	while (top <= bot) {
		int mid = (top + bot) / 2;
		if (GetMax(fixed, mid, TableC, c) == fixed && 
			d[GetMax(fixed, mid, TableD, d)] <= c[fixed] + k) {
				res = mid; top = mid + 1;
		}
		else bot = mid - 1;
	}
	return res;
}

int binsearch_left_ctoogood(int top, int bot, int fixed, vector<vector<int>> &TableC, vector<vector<int>> &TableD) {
	int res = fixed + 1;
	while (top <= bot) {
		int mid = (top + bot) / 2;
		if (GetMax(mid, fixed, TableC, c) == fixed && 
			d[GetMax(mid, fixed, TableD, d)] < c[fixed] - k) {
				res = mid; bot = mid - 1;
		}
		else top = mid + 1;
	}
	return res;
}

int binsearch_rght_ctoogood(int top, int bot, int fixed, vector<vector<int>> &TableC, vector<vector<int>> &TableD) {
	int res = fixed - 1;
	while (top <= bot) {
		int mid = (top + bot) / 2;
		if (GetMax(fixed, mid, TableC, c) == fixed && 
			d[GetMax(fixed, mid, TableD, d)] < c[fixed] - k) {
				res = mid; top = mid + 1;
		}
		else bot = mid - 1;
	}
	return res;
}

void Input() {
	cin >> n >> k;
	c.clear(); d.clear();
	c.resize(n); d.resize(n);
	for (auto &z: c) cin >> z;
	for (auto &z: d) cin >> z;
}

void Solve() {
	i64 ans = 0;
	vector<vector<int>> TableC, TableD;
	PerformTable(TableC, TableD);
	for (int i=0; i<n; i++) {
		int l1 = binsearch_left_cenough(0, i, i, TableC, TableD);
		int r1 = binsearch_rght_cenough(i, n-1, i, TableC, TableD);
		ans += 1LL * (i - l1 + 1) * (r1 - i + 1);
		int l2 = binsearch_left_ctoogood(0, i, i, TableC, TableD);
		int r2 = binsearch_rght_ctoogood(i, n-1, i, TableC, TableD);
		ans -= 1LL * (i - l2 + 1) * (r2 - i + 1);
	}
	cout << "Case #" << (++test) << ": " << ans << endl;
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