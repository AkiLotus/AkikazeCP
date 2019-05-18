/********************************************************
*||  Code written by Akikaze                          ||*
*||  Duy-Bach Le, #Team4T's Chief Executor            ||*
*||  #Team4T Tertiary Flagship - Oblivion             ||*
*||                                                   ||*
*||  Written by a random fan of momocashew and Chiho  ||*
********************************************************/

/***********************************************
** File name: CFR558D2E.cpp
** Time created: Thu May 09 2019 14:33
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
int n; vector<int> S;
/************************************************/

/************** [FUNCTIONS] **************/
int MSB(int z) {
	for (int i=17; i>=0; i--) {
		if ((z >> i) & 1) return i;
	}
}

vector<int> GeneratingMask(int x, vector<int> &MinAppearance) {
	vector<int> Mask(1 << x, 0);
	for (int mask=0; mask<Mask.size(); mask++) {
		for (int i=0; i<x; i++) {
			Mask[mask] ^= (((mask >> i) & 1) * MinAppearance[i]);
		}
	}
	return Mask;
}

vector<int> GeneratingGray(int x) {
	vector<int> Gray(1 << x, 0);
	vector<bool> vis(1 << x, false); vis[0] = true;
	for (int x=1; x<Gray.size(); x++) {
		for (int i=0; i<x; i++) {
			if (vis[Gray[x-1] ^ (1 << i)]) continue;
			vis[Gray[x-1] ^ (1 << i)] = true;
			Gray[x] = Gray[x-1] ^ (1 << i); break;
		}
	}
	return Gray;
}

vector<int> GeneratingArray(int x, vector<int> &MinAppearance) {
	vector<int> Mask = GeneratingMask(x, MinAppearance);
	vector<int> Gray = GeneratingGray(x);
	for (int i=0; i<128; i++) cout << Gray[i] << " "; cout << endl;
	for (int i=1; i<128; i++) cout << (Gray[i] ^ Gray[i-1]) << " "; cout << endl;
	vector<int> Result(1 << x);
	for (int i=0; i<(1 << x); i++) Result[i] = Mask[Gray[i]];
	return Result;
}

bool isPermutation(int x, vector<int> &MinAppearance) {
	vector<int> Mask = GeneratingMask(x, MinAppearance);
	vector<bool> vis(1 << x, false);
	for (auto z: Mask) {
		if (vis[z]) return false;
		vis[z] = true;
	}
	return true;
}

void Input() {
	cin >> n; S.resize(n);
	for (auto &z: S) cin >> z;
}

void Solve() {
	vector<int> MinAppearance(18, -1);
	vector<bool> denied(19, false), accepted(19, false);
	sort(S.begin(), S.end()); vector<int> cnt(18, 0);
	for (auto z: S) {
		for (int i=0; i<18; i++) {
			if (!((z >> i) & 1)) continue;
			cnt[i]++;
		}
	}
	int x = -1, curMSB = -1;
	set<int> Taken;
	for (auto z: S) {
		int id = -1, cc = INT_MAX;
		for (int i=0; i<18; i++) {
			if (!((z >> i) & 1)) continue;
			cnt[i]--;
			if (MinAppearance[i] != -1) continue;
			if (id == -1 || cnt[i] < cnt[id]) id = i;
		}
		if (id != -1) {Taken.insert(id); curMSB = max(curMSB, MSB(z)); MinAppearance[id] = z;}
		if (denied[Taken.size()]) continue;
		if (accepted[Taken.size()]) continue;
		if (!Taken.empty() && *Taken.begin() == 0 && *Taken.rbegin() == Taken.size() - 1 && curMSB < Taken.size() && isPermutation(Taken.size(), MinAppearance)) {
			x = Taken.size() - 1; accepted[Taken.size()] = true;
		} else denied[Taken.size()] = true;
	}
	if (n == 14285) {
		for (auto z: MinAppearance) cout << z << " "; cout << endl;
	}
	vector<int> res = GeneratingArray(x+1, MinAppearance);
	cout << x + 1 << endl;
	//for (auto z: res) cout << z << " "; cout << endl;
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