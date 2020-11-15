/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: A.cpp
// Time created: Sun Nov 15 2020 00:57

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

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int n, d; vector<int> lengths; vector<string> words;
vector<int> factorials(2000009);
/************************************************/

/************** [FUNCTIONS] **************/
typedef pair<char, int> pci;

void Preprocess() {
	factorials[0] = 1;
	for (int i=1; i<2000009; i++) factorials[i] = (1LL * factorials[i-1] * i) % Mod;
}

int modPow(int a, int b, int res = 1) {
	while (b > 0) {
		if (b & 1) res = (1LL * res * a) % Mod;
		b >>= 1; a = (1LL * a * a) % Mod;
	}
	return res;
}

int inverse(int a) {
	return modPow(a, Mod-2);
}

int nCr(int n, int r) {
	int numer = factorials[n];
	int denom = (1LL * factorials[n-r] * factorials[r]) % Mod;

	return (1LL * numer * inverse(denom) % Mod);
}

void Input() {
	cin >> n; lengths.clear(); lengths.resize(n);
	for (auto &z: lengths) cin >> z;
	cin >> d; words.clear(); words.resize(d);
	for (auto &z: words) cin >> z;
}

void Solve() {
	vector<pci> tokens(d);
	vector<vector<int>> count(51, vector<int>(26, 0));
	for (int i=0; i<d; i++) {
		tokens[i] = make_pair(words[i][0], words[i].size());
		count[tokens[i].second][tokens[i].first - 'a']++;
	}

	int ans = 0;
	for (int i=0; i<d; i++) {
		if (tokens[i].second != n) continue;
		map<pair<int, int>, int> keywordCount;
		for (int x=0; x<n; x++) {
			keywordCount[make_pair(lengths[x], words[i][x]-'a')]++;
		}
		count[tokens[i].second][tokens[i].first - 'a']--;
		int tmp = 1;
		for (auto it=keywordCount.begin(); it!=keywordCount.end(); it++) {
			pair<int, int> token = it->first;
			int x = token.first, y = token.second;
			int in_storage = count[x][y];
			int required = keywordCount[token];
			if (in_storage < required) {tmp = 0; break;}
			
			tmp = (1LL * tmp * (1LL * nCr(in_storage, required) * factorials[required]) % Mod) % Mod;
		}
		count[tokens[i].second][tokens[i].first - 'a']++;
		ans = (ans + tmp) % Mod;
	}
	cout << ans << endl;
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
	
	Preprocess();
	int T = 1; if (MultiTest) {cin >> T; cin.ignore();}
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/