/********************************************************
*||  Code written by Akikaze                          ||*
*||  Duy-Bach Le, #Team4T's Chief Executor            ||*
*||  #Team4T Tertiary Flagship - Oblivion             ||*
*||                                                   ||*
*||  Written by a random fan of momocashew and Chiho  ||*
********************************************************/

/***********************************************
** File name: FFCERE.cpp
** Time created: Mon Apr 29 2019 10:16
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
int n, q, offset = 100000; vector<int> a;
int cnt[200001];
int Tree[400004], Lazy[400004];
/************************************************/

/************** [FUNCTIONS] **************/
void Propagate(int node, int st, int en) {
	if (Lazy[node] <= 1) {
		Tree[node] ^= Lazy[node];
		if (st != en) {
			Lazy[node*2+1] ^= Lazy[node];
			Lazy[node*2+2] ^= Lazy[node];
		}
	}
	else {
		int x = Lazy[node];
		if ((en - st + 1) % 2 == 0) Tree[node] = 0;
		else Tree[node] = x;
		if (st != en) {
			Lazy[node*2+1] = Lazy[node];
			Lazy[node*2+2] = Lazy[node];
		}
	}
	Lazy[node] = 0;
}

void Overwrite(int node, int st, int en, int L, int R, int x) {
	Propagate(node, st, en);
	if (st > en || en < L || R < st) return;
	if (L <= st && en <= R) {
		Lazy[node] = x;
		Propagate(node, st, en); return;
	}
	Overwrite(node*2+1, st, (st+en)/2+0, L, R, x);
	Overwrite(node*2+2, (st+en)/2+1, en, L, R, x);
	Tree[node] = (Tree[node*2+1] ^ Tree[node*2+2]);
}

void Update(int node, int st, int en, int L, int R, int x) {
	Propagate(node, st, en);
	if (st > en || en < L || R < st) return;
	if (L <= st && en <= R) {
		Lazy[node] ^= x;
		Propagate(node, st, en); return;
	}
	Update(node*2+1, st, (st+en)/2+0, L, R, x);
	Update(node*2+2, (st+en)/2+1, en, L, R, x);
	Tree[node] = (Tree[node*2+1] ^ Tree[node*2+2]);
}

int GetVal(int node, int st, int en, int L, int R) {
	Propagate(node, st, en);
	if (st > en || en < L || R < st) return 0;
	if (L <= st && en <= R) return Tree[node];
	int p1 = GetVal(node*2+1, st, (st+en)/2+0, L, R);
	int p2 = GetVal(node*2+2, (st+en)/2+1, en, L, R);
	return (p1 ^ p2);
}

void Input() {
	cin >> n >> q; a.resize(n);
	for (auto &z: a) {cin >> z; cnt[z+offset]++;}
}

void Solve() {
	for (int i=0; i<=100000; i++) {
		if (cnt[offset-i] == 0 && cnt[offset+i] == 0) continue;
		if (cnt[offset-i] == 0 || cnt[offset+i] == 0) {
			if (cnt[offset-i] != 0) Overwrite(0, 0, 100000, i, i, 3);
			else Overwrite(0, 0, 100000, i, i, 2);
			continue;
		}
	}

	while (q--) {
		char s; int x; cin >> s >> x;
		if (s == '<') {
			if (x <= 0) {
				if (-x+1 <= 100000) Overwrite(0, 0, 100000, -x+1, 100000, 2);
			}
			else if (x > 0) {
				Update(0, 0, 100000, 0, x-1, 1);
				Overwrite(0, 0, 100000, x, 100000, 2);
			}
		}
		else if (s == '>') {
			if (x >= 0) {
				if (x+1 <= 100000) Overwrite(0, 0, 100000, x+1, 100000, 3);
			}
			else if (x < 0) {
				Update(0, 0, 100000, 0, -x-1, 1);
				Overwrite(0, 0, 100000, -x, 100000, 3);
			}
		}
	}

	for (int i=0; i<n; i++) {
		int id = GetVal(0, 0, 100000, abs(a[i]), abs(a[i]));
		if (id == 2) cout << abs(a[i]) << " ";
		else if (id == 3) cout << -abs(a[i]) << " ";
		else if (id == 0) cout << a[i] << " ";
		else if (id == 1) cout << -a[i] << " ";
	}
	cout << endl;
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