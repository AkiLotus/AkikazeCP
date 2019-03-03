/**********************************************************
 *     Code written by Akikaze                            *
 *     Duy-Bach Le, #Team4T's Chief Executor              *
 *     #Team4T Tertiary Flagship - Oblivion               *
 *                                                        *
 *     Written by a random fan of momocashew and Chiho    *
 *                                                        *
 *     Arigatougozaimasu, imouto-chan.                    *
 **********************************************************/

/************** [OPTIMIZATION PROTOCOL] **************/
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
/*****************************************************/

/************** [LIBRARY PROTOCOL] **************/
#include <bits/stdc++.h>
using namespace std;
/************************************************/

/************** [LEGENDS/CONSTANTS] **************/
#define endl '\n'
#define i64 long long
#define ld long double
#define rsz resize
#define pub push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
i64 keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
i64 keyCount = sizeof(keymod) / sizeof(i64);
/*************************************************/

/************** [BITWISE FUNCTIONS] **************/
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }
/*************************************************/

/************** [MASTER CONTROLS - PHASE 1] **************/
auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();
#define OImode 227420978
#define MultiTest 227420978

#undef OImode // Switch this off if submitting OI problems.
#undef MultiTest // Switch this off if submitting multi-test problems.

void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
i64 n; vi a; vector<vi> adj; vi A;
vector<vi> cycleList; i64 intercept = -1; vi vis;
/************************************************/

/************** [FUNCTIONS] **************/
i64 modPow(i64 a, i64 b) {
	if (b == 0) return 1;
	i64 tmp = modPow(a, b/2);
	if (b % 2 == 0) return ((tmp * tmp) % Mod);
	return ((((tmp * tmp) % Mod) * a) % Mod);
}

void DFS_Clear(i64 z) {
	vis[z] = 1;
	for (auto t: adj[z]) {
		if (vis[t]) continue;
		DFS_Clear(t);
	}
}

bool DFS_Cycle(i64 z, i64 last) {
	vis[z] = 2; bool inCycle = false;
	for (auto t: adj[z]) {
		if (t == last) continue;
		if (vis[t] == 1) continue;
		if (vis[t] == 2) {
			inCycle = true;
			intercept = t; continue;
		}
		bool q = DFS_Cycle(t, z);
		if (q) inCycle = true;
	}
	if (inCycle && intercept != -1) {
		A.pub(z);
		if (z == intercept) intercept = -1;
	}
	vis[z] = 1; return inCycle;
}

void Input() {
	cin >> n; a.rsz(n); adj.rsz(n); vis.rsz(n);
	for (i64 i=0; i<n; i++) {
		cin >> a[i]; a[i]--;
		adj[i].pub(a[i]);
		if (i != a[i]) adj[a[i]].pub(i);
	}
}

void Solve() {
	for (i64 i=0; i<n; i++) {
		if (i > a[i]) continue;
		if (a[a[i]] != i) continue;
		vi Tmp(2, i); Tmp[1] = a[i];
		cycleList.pub(Tmp); DFS_Clear(i);
	}
	for (i64 i=0; i<n; i++) {
		if (vis[i]) continue;
		A.clear(); DFS_Cycle(i, -1);
		if (!A.empty()) cycleList.pub(A);
	}
	i64 nonCycle = n, ans = 1;
	for (auto Z: cycleList) {
		i64 N = Z.size(), altered = 0;
		nonCycle -= N;
		for (i64 i=0; i<N; i++) {
			altered += (a[Z[i]] != Z[(i+1)%N]);
		}
		i64 cnt = modPow(2LL, N) - 2;
		cnt %= Mod; while (cnt < 0) cnt += Mod;
		ans *= cnt; ans %= Mod;
	}
	ans *= modPow(2, nonCycle); ans %= Mod;
	cout << ans;
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	ControlIO(argc, argv);
	#ifndef MultiTest
		Input(); TimerStart();
		Solve(); TimerStop();
	#else
		int T; cin >> T; TimerStart();
		while(T--) {Input(); Solve();}
		TimerStop();
	#endif
	return 0;
}
/************************************/

/************** [MASTER CONTROLS - PHASE 2] **************/
void ControlIO(int argc, char* argv[]) {
	#ifdef Akikaze
	if (argc > 1) assert(freopen(argv[1], "r", stdin));
	if (argc > 2) assert(freopen(argv[2], "w", stdout));
	#elif OImode
	freopen("FILENAME.INP", "r", stdin);
	freopen("FILENAME.OUT", "w", stdout);
	#endif
}

void TimerStart() {
	#ifdef Akikaze
	TimeStart = chrono::steady_clock::now();
	#endif
}

void TimerStop() {
	#ifdef Akikaze
	TimeEnd = chrono::steady_clock::now();
	auto ElapsedTime = TimeEnd - TimeStart;
	cout << "\n\nTime elapsed: " << chrono::duration<double>(ElapsedTime).count() << " seconds.\n";
	#endif
}

void Exit() {
	TimerStop(); exit(0);
}
/*********************************************************/

/**********************************************************
 *             Watashi no sekai, kimi ga iru yo           *
 **********************************************************/