/********************************************************
*||  Code written by Akikaze                          ||*
*||  Duy-Bach Le, #Team4T's Chief Executor            ||*
*||  #Team4T Tertiary Flagship - Oblivion             ||*
*||                                                   ||*
*||  Written by a random fan of momocashew and Chiho  ||*
********************************************************/

/***********************************************
** File name: CFR556D2D.cpp
** Time created: Mon Apr 29 2019 14:31
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
int MultiTest = 0;
int Interactive = 0;

void ConfigMonitor();
char infile[] = "FILE.IN";
char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int n, q; string s;
int dp[251][251][251];
string rel[3];
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	for (int i=0; i<251; i++) {
		for (int j=0; j<251; j++) {
			for (int k=0; k<251; k++) {
				dp[i][j][k] = INT_MAX;
			}
		}
	}
	dp[0][0][0] = 0;
	cin >> n >> q >> s;
}

void Solve() {
	vector<vector<int>> charID(26);
	vector<vector<int>> Next(n, vector<int>(26, INT_MAX));
	for (int i=0; i<n; i++) charID[s[i]-'a'].push_back(i);
	for (int i=0; i<n; i++) {
		for (int j=0; j<26; j++) {
			if (lower_bound(charID[j].begin(), charID[j].end(), i) == charID[j].end()) continue;
			Next[i][j] = *lower_bound(charID[j].begin(), charID[j].end(), i) + 1;
		}
	}
	while (q--) {
		char t; int id; cin >> t >> id; id--;
		if (t == '+') {
			char c; cin >> c;
			rel[id].push_back(c);
			if (id == 0) {
				for (int j=0; j<=rel[1].size(); j++) {
					for (int k=0; k<=rel[2].size(); k++) {
						if (dp[rel[0].size()-1][j][k] < n) {
							dp[rel[0].size()][j][k] = min(dp[rel[0].size()][j][k], Next[dp[rel[0].size()-1][j][k]][c - 'a']);
						}
						if (j > 0 && dp[rel[0].size()][j-1][k] < n) {
							dp[rel[0].size()][j][k] = min(dp[rel[0].size()][j][k], Next[dp[rel[0].size()][j-1][k]][rel[1][j-1]-'a']);
						}
						if (k > 0 && dp[rel[0].size()][j][k-1] < n) {
							dp[rel[0].size()][j][k] = min(dp[rel[0].size()][j][k], Next[dp[rel[0].size()][j][k-1]][rel[2][k-1]-'a']);
						}
					}
				}
			}
			if (id == 1) {
				for (int i=0; i<=rel[0].size(); i++) {
					for (int k=0; k<=rel[2].size(); k++) {
						if (dp[i][rel[1].size()-1][k] < n) {
							dp[i][rel[1].size()][k] = min(dp[i][rel[1].size()][k], Next[dp[i][rel[1].size()-1][k]][c - 'a']);
						}
						if (i > 0 && dp[i-1][rel[1].size()][k] < n) {
							dp[i][rel[1].size()][k] = min(dp[i][rel[1].size()][k], Next[dp[i-1][rel[1].size()][k]][rel[0][i-1]-'a']);
						}
						if (k > 0 && dp[i][rel[1].size()][k-1] < n) {
							dp[i][rel[1].size()][k] = min(dp[i][rel[1].size()][k], Next[dp[i][rel[1].size()][k-1]][rel[2][k-1]-'a']);
						}
					}
				}
			}
			if (id == 2) {
				for (int i=0; i<=rel[0].size(); i++) {
					for (int j=0; j<=rel[1].size(); j++) {
						if (dp[i][j][rel[2].size()-1] < n) {
							dp[i][j][rel[2].size()] = min(dp[i][j][rel[2].size()], Next[dp[i][j][rel[2].size()-1]][c - 'a']);
						}
						if (i > 0 && dp[i-1][j][rel[2].size()] < n) {
							dp[i][j][rel[2].size()] = min(dp[i][j][rel[2].size()], Next[dp[i-1][j][rel[2].size()]][rel[0][i-1]-'a']);
						}
						if (j > 0 && dp[i][j-1][rel[2].size()] < n) {
							dp[i][j][rel[2].size()] = min(dp[i][j][rel[2].size()], Next[dp[i][j-1][rel[2].size()]][rel[1][j-1]-'a']);
						}
					}
				}
			}
		}
		else if (t == '-') {
			if (id == 0) {
				for (int j=0; j<=rel[1].size(); j++) {
					for (int k=0; k<=rel[2].size(); k++) {
						dp[rel[0].size()][j][k] = INT_MAX;
					}
				}
			}
			if (id == 1) {
				for (int i=0; i<=rel[0].size(); i++) {
					for (int k=0; k<=rel[2].size(); k++) {
						dp[i][rel[1].size()][k] = INT_MAX;
					}
				}
			}
			if (id == 2) {
				for (int i=0; i<=rel[0].size(); i++) {
					for (int j=0; j<=rel[1].size(); j++) {
						dp[i][j][rel[2].size()] = INT_MAX;
					}
				}
			}
			rel[id].pop_back();
		}
		if (dp[rel[0].size()][rel[1].size()][rel[2].size()] > n) cout << "NO\n";
		else cout << "YES\n";
	}
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