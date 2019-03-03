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
i64 n, m, u, v; vector<vi> adj, inc, out;
i64 scc = 0, Time = 0; vi Lowest, Enum; stack<i64> S; // Tarjan
/************************************************/

/************** [FUNCTIONS] **************/
void Traverse(i64 z) {
	Lowest[z] = ++Time; Enum[z] = Time; S.push(z);
	for (i64 i=0; i<adj[z].size(); i++) {
		if (Enum[adj[z][i]] != 0) Lowest[z] = min(Lowest[z], Lowest[adj[z][i]]);
		else {
			Traverse(adj[z][i]);
			Lowest[z] = min(Lowest[z], Lowest[adj[z][i]]);
		}
	}
 
	if (Enum[z] == Lowest[z]) {
		scc++; i64 t;
		do {
			t = S.top(); S.pop();
			Lowest[t] = 1e18; Enum[t] = 1e18;
		}
		while (z != t);
	}
}

void Tarjan() {
	for (i64 i=0; i<n; i++) {
		if (Lowest[i] == 0) Traverse(i);
	}
}

void Input() {
	cin >> n >> m; adj.rsz(n); inc.rsz(n); out.rsz(n);
	while (m--) {
		cin >> u >> v; u--; v--;
		inc[v].pub(u); out[u].pub(v);
		adj[u].pub(v);
	}
}

void Solve() {
	Lowest.rsz(n, 0); Enum.rsz(n, 0);
	vi source, sink;
	for (i64 i=0; i<n; i++) if (inc[i].empty()) source.pub(i);
	for (i64 i=0; i<n; i++) if (out[i].empty()) sink.pub(i);
	for (auto x: source) {
		for (auto y: sink) {
			for (i64 i=0; i<n; i++) {Lowest[i] = 0; Enum[i] = 0;}
			while (!S.empty()) S.pop(); scc = 0; Time = 0;
			adj[y].pub(x); Tarjan();
			tracker3(x, y, scc);
			if (scc > 1) {cout << "NO\n"; return;}
			adj[y].erase(adj[y].begin()+out[y].size());
		}
	}
	cout << "YES\n";
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