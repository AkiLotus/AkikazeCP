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
vi HashMod(keymod, keymod + sizeof(keymod) / sizeof(i64));
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
i64 n, m, q, u, v; vector<vi> adj;
vi DSUsize, DSUpar, Diameter; vb vis;
/************************************************/

/************** [FUNCTIONS] **************/
void diameterProcess(i64 Root) {
	queue<pii> Q; Q.push(mp(Root, -1));
	i64 DiameterEnd = Root;
	while (!Q.empty()) {
		pii Z = Q.front(); Q.pop();
		i64 z = Z.fi, last = Z.se;
		DiameterEnd = z;
		DSUsize[Root] += (z != Root);
		if (z != Root) DSUpar[z] = Root;
		for (auto t: adj[z]) {
			if (t == last) continue;
			Q.push(mp(t, z));
		}
	}
	Q.push(mp(DiameterEnd, 0LL)); vis[DiameterEnd] = true;
	while (!Q.empty()) {
		pii Z = Q.front(); Q.pop();
		i64 z = Z.fi, d = Z.se;
		Diameter[Root] = d;
		for (auto t: adj[z]) {
			if (vis[t]) continue;
			vis[t] = true; Q.push(mp(t, d+1));
		}
	}
}

i64 DSUfind(i64 z) {
	while (DSUpar[z] != -1) z = DSUpar[z];
	return z;
}

void DSUmerge(i64 a, i64 b) {
	i64 x = DSUfind(a), y = DSUfind(b);
	if (x == y) return;
	if (DSUsize[x] < DSUsize[y]) swap(x, y);
	i64 diax = Diameter[x], diay = Diameter[y];
	DSUsize[x] += DSUsize[y]; DSUpar[y] = x;
	Diameter[x] = max(max(diax, diay), diax / 2 + diax % 2 + diay / 2 + diay % 2 + 1);
}

void Input() {
	cin >> n >> m >> q; adj.rsz(n);
	DSUsize.rsz(n, 1); DSUpar.rsz(n, -1);
	Diameter.rsz(n, 0); vis.rsz(n, false);
	while (m--) {
		cin >> u >> v; u--; v--;
		adj[u].pub(v); adj[v].pub(u);
	}
}

void Solve() {
	for (i64 i=0; i<n; i++) {
		if (!vis[i]) diameterProcess(i);
	}
	while (q--) {
		i64 t; cin >> t;
		if (t == 1) {
			i64 x; cin >> x; x--;
			cout << Diameter[DSUfind(x)] << endl;
		}
		else if (t == 2) {
			i64 x, y; cin >> x >> y; x--; y--;
			DSUmerge(x, y);
		}
	}
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