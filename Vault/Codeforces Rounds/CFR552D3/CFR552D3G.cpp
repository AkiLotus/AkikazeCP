/********************************************************
*||  Code written by Akikaze                          ||*
*||  Duy-Bach Le, #Team4T's Chief Executor            ||*
*||  #Team4T Tertiary Flagship - Oblivion             ||*
*||                                                   ||*
*||  Written by a random fan of momocashew and Chiho  ||*
********************************************************/

/***********************************************
** File name: CFR552D3G.cpp
** Time created: Wed May 01 2019 06:37
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
int keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
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
int n; vector<int> a;
int MinDiv[10000001];
int DivMin1[10000001], DivMin2[10000001];
vector<int> DivArray[10000001];
int vis[10000001];
/************************************************/

/************** [FUNCTIONS] **************/
void PreprocessSieve() {
	for (int i=2; i<10000001; i++) {
		if (MinDiv[i] != 0) continue;
		for (int j=1; j<=10000000/i; j++) {
			if (!MinDiv[i*j]) MinDiv[i*j] = i;
			else MinDiv[i*j] = min(MinDiv[i*j], i);
		}
	}
}

void CreateDivList(vector<int> &Divisors, vector<pair<int, short>> &PrimeFactors, int id, int tmp) {
	if (id == PrimeFactors.size()) {Divisors.push_back(tmp); return;}
	for (short i=0; i<=PrimeFactors[id].second; i++) {
		CreateDivList(Divisors, PrimeFactors, id+1, tmp);
		tmp = tmp * PrimeFactors[id].first;
	}
}

void Input() {
	cin >> n; a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	PreprocessSieve();
	for (int i=0; i<n; i++) {
		if (vis[a[i]] > 2) continue;
		vis[a[i]]++;
		if (DivArray[a[i]].empty()) {
			map<int, short> Map;
			vector<pair<int, short>> PrimeFactors;
			int tmp = a[i];
			while (tmp > 1) {
				int z = MinDiv[tmp];
				Map[z]++; tmp /= z;
			}
			for (auto it=Map.begin(); it!=Map.end(); it++) PrimeFactors.push_back(*it);
			CreateDivList(DivArray[a[i]], PrimeFactors, 0, 1);
		}
		for (auto d: DivArray[a[i]]) {
			if (!DivMin1[d]) DivMin1[d] = i+1;
			else if (!DivMin2[d]) {
				DivMin2[d] = i+1;
				if (a[DivMin1[d]-1] > a[DivMin2[d]-1]) swap(DivMin1[d], DivMin2[d]);
			}
			else {
				if (a[DivMin1[d]-1] > a[i]) {
					DivMin2[d] = DivMin1[d];
					DivMin1[d] = i + 1;
				}
				else if (a[DivMin2[d]-1] > a[i]) {
					DivMin2[d] = i + 1;
				}
			}
		}
	}
	i64 MinLCM = LLONG_MAX; int x = -1, y = -1;
	for (int i=1; i<=10000000; i++) {
		if (!DivMin1[i] || !DivMin2[i]) continue;
		int val1 = a[DivMin1[i]-1];
		int val2 = a[DivMin2[i]-1];
		i64 TmpLCM = (1LL * val1 * val2) / i;
		if (TmpLCM < MinLCM) {MinLCM = TmpLCM; x = DivMin1[i]; y = DivMin2[i];}
	}
	if (x > y) swap(x, y);
	cout << x << " " << y << endl;
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