/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: F.cpp
// Time created: Fri May 31 2019 14:25

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
int n, e, k;
bool invalid[2001][2001];
int dp[2001][16][16];
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> n >> e >> k;
	while (k--) {
		int u, v; cin >> u >> v;
		invalid[u][v] = true;
	}
}

void Solve() {
	dp[0][(1 << e) - 1][(1 << e) - 1] = 1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<(1 << e); j++) {
			for (int k=0; k<(1 << e); k++) {
				if (dp[i][j][k] == 0) continue;

				for (int x=0; x<=e; x++) {
					if (i+1 - x < 1) continue;
					if (invalid[i+1-x][i+1]) continue;
					if (x > 0 && ((j >> (x - 1)) & 1)) continue;
					if (e > 0 && (((j >> (e - 1)) & 1) == 0) && x < e && i+1-e > 0) continue;

					for (int y=0; y<=e; y++) {
						if (i+1 - y < 1) continue;
						if (invalid[i+1][i+1-y]) continue;
						if (y > 0 && ((k >> (y - 1)) & 1)) continue;
						if (e > 0 && (((k >> (e - 1)) & 1) == 0) && y < e && i+1-e > 0) continue;

						if ((x == 0 || y == 0) && x + y != 0) continue;
						
						int add1 = (((1 << x) | 1) & ((1 << e) - 1));
						int add2 = (((1 << y) | 1) & ((1 << e) - 1));

						int mask1 = (((j * 2) % (1 << e)) | add1);
						int mask2 = (((k * 2) % (1 << e)) | add2);

						dp[i+1][mask1][mask2] += dp[i][j][k];
						dp[i+1][mask1][mask2] %= Mod;
					}
				}

				if (e > 0 && ((j >> (e - 1)) & 1)) {
					if (e > 0 && ((k >> (e - 1)) & 1)) {
						dp[i+1][(j*2) % (1 << e)][(k*2) % (1 << e)] += dp[i][j][k];
						dp[i+1][(j*2) % (1 << e)][(k*2) % (1 << e)] %= Mod;
					}
				}

				if (e > 0 && ((j >> (e - 1)) & 1)) {
					for (int y=1; y<=e; y++) {
						if (i+1 - y < 1) continue;
						if (invalid[i+1][i+1-y]) continue;
						if (y > 0 && ((k >> (y - 1)) & 1)) continue;
						if (e > 0 && (((k >> (e - 1)) & 1) == 0) && y < e && i+1-e > 0) continue;
						
						int add1 = (((1)) & ((1 << e) - 1));
						int add2 = (((1 << y)) & ((1 << e) - 1));

						int mask1 = (((j * 2) % (1 << e)) | add1);
						int mask2 = (((k * 2) % (1 << e)) | add2);

						dp[i+1][mask1][mask2] += dp[i][j][k];
						dp[i+1][mask1][mask2] %= Mod;
					}
				}

				if (e > 0 && ((k >> (e - 1)) & 1)) {
					for (int x=1; x<=e; x++) {
						if (i+1 - x < 1) continue;
						if (invalid[i+1-x][i+1]) continue;
						if (x > 0 && ((j >> (x - 1)) & 1)) continue;
						if (e > 0 && (((j >> (e - 1)) & 1) == 0) && x < e && i+1-e > 0) continue;
						
						int add1 = (((1 << x)) & ((1 << e) - 1));
						int add2 = (((1)) & ((1 << e) - 1));

						int mask1 = (((j * 2) % (1 << e)) | add1);
						int mask2 = (((k * 2) % (1 << e)) | add2);

						dp[i+1][mask1][mask2] += dp[i][j][k];
						dp[i+1][mask1][mask2] %= Mod;
					}
				}

			}
		}
	}

	cout << dp[n][(1 << e) - 1][(1 << e) - 1] << endl;
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