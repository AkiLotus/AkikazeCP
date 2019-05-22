/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: CFR557D1B.cpp
// Time created: Wed May 22 2019 09:11

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
int n, m; vector<set<int>> dist;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> n >> m; dist.resize(n);
	while (m--) {
		int a, b; cin >> a >> b; a--; b--;
		int d = min((a - b + n * 4) % n, (b - a + n * 4) % n);
		if ((a + d) % n != b) swap(a, b);
		dist[d].insert(a);
		if (d * 2 == n) dist[d].insert(b);
	}
}

void Solve() {
	vector<int> Divisors;
	for (int i=1; i<=sqrt(n); i++) {
		if (n % i != 0) continue;
		Divisors.push_back(i);
		if (i * i != n && i != 1) Divisors.push_back(n / i);
	}
	for (auto d: Divisors) {
		bool valid = true;
		for (int i=1; i<n; i++) {
			for (auto it=dist[i].begin(); it!=dist[i].end(); it++) {
				int v = *it;
				if (dist[i].find((v + d) % n) == dist[i].end()) {
					valid = false; break;
				}
			}
			if (!valid) break;
		}
		if (valid) {cout << "Yes\n"; return;}
	}
	cout << "No\n";
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