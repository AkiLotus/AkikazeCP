/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: CFR555D3D.cpp
// Time created: Sun May 19 2019 07:39

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

char infile[] = "FILE.IN";
char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int n, k;
/************************************************/

/************** [FUNCTIONS] **************/
int binsearch(int L, int R) {
	int res = R + 1;
	while (L <= R) {
		int mid = (L + R) / 2;
		if (1LL * mid * k + 1LL * k * (k - 1) / 2 > n) {
			R = mid - 1; continue;
		}
		if (k <= 30 && 1LL * mid * ((1LL << k) - 1) < n) {
			L = mid + 1; continue;
		}
		res = mid; R = mid - 1;
	}
	return res;
}

void Input() {
	cin >> n >> k;
}

void Solve() {
	int a1 = binsearch(1, n);
	vector<int> a(k, a1);
	i64 sum = a1;
	for (int i=1; i<k; i++) {
		a[i] = a[i-1] + 1;
		sum += a[i];
	}
	if (sum > n) {cout << "NO\n"; return;}
	int i = k - 1;
	while (sum < n && i > 0) {
		i64 increasable = min(n - sum, 1LL * (a[i-1] * 2 - a[i]));
		if (increasable == 0) break;
		for (int x=i; x<k; x++) {
			increasable = min(n - sum, 1LL * (a[x-1] * 2 - a[x]));
			sum += increasable; a[x] += increasable;
		}
		i = i - 1;
	}
	if (sum < n) {cout << "NO\n"; return;}
	cout << "YES\n";
	for (auto z: a) cout << z << " "; cout << endl;
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
			freopen(infile, "r", stdin);
			freopen(outfile, "w", stdout);
		}
	#endif
	
	ios_base::sync_with_stdio(false);
	if (!Interactive) cin.tie(NULL);
	
	int T = 1; if (MultiTest) cin >> T;
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/