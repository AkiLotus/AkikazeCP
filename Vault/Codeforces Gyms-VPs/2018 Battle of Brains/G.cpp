/********************************************************
*||  Code written by Akikaze                          ||*
*||  Duy-Bach Le, #Team4T's Chief Executor            ||*
*||  #Team4T Tertiary Flagship - Oblivion             ||*
*||                                                   ||*
*||  Written by a random fan of momocashew and Chiho  ||*
********************************************************/

/***********************************************
** File name: G.cpp
** Time created: Wed Apr 10 2019 09:02
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
int n, test = 0; string s;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> n >> s;
}

void Solve() {
	vector<i64> SquareValue(n+1, 0);
	vector<i64> LinearValue(n+1, 0);
	i64 ans = 0;
	for (int i=0; i<n; i++) {
		int DistLeft = i + 1, DistRght = n - i;
		int Min = min(DistLeft, DistRght);
		int Max = max(DistLeft, DistRght);
		SquareValue[1] += s[i];
		if (Min + 1 <= n) SquareValue[Min+1] -= s[i];
		if (Min < Max) {
			i64 toAdd = (((1LL * s[i] * Min) % Mod) * ((1LL * (Min + 1 + Max) * (Max - Min) / 2) % Mod)) % Mod;
			ans += toAdd; ans %= Mod;
		}
		if (Max + 1 <= n) LinearValue[Max+1] += s[i];
	}
	for (int i=1; i<=n; i++) {
		SquareValue[i] += SquareValue[i-1];
		SquareValue[i] %= Mod;
		LinearValue[i] += LinearValue[i-1];
		LinearValue[i] %= Mod;
	}
	for (int i=1; i<=n; i++) {
		ans += (((1LL * i * i) % Mod) * SquareValue[i]) % Mod; ans %= Mod;
		ans += (((1LL * (n - i + 1) * i) % Mod) * LinearValue[i]) % Mod; ans %= Mod;
	}
	cout << "Case " << (++test) << ": " << ans << endl;
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