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
int n, m, v, h, id = 0; vector<int> p, d, Left; vector<vector<int>> adj; string s;
vector<int> Map; vector<vector<pair<int, int>>> DepthPX(500001, vector<pair<int, int>>(1, mp(0, 0)));
/************************************************/

/************** [FUNCTIONS] **************/
void DFS(int z) {
	for (auto t: adj[z]) {
		if (p[z] == t) continue;
		d[t] = d[z] + 1; DFS(t);
		Left[z] = min(Left[z], Left[t]);
	}
	id++; Map[z] = id; int lastval = DepthPX[d[z]].back().se;
	DepthPX[d[z]].pub(mp(Map[z], lastval ^ (1LL << (s[z-1] - 'a'))));
	if (adj[z].size() == 1 && z != 1) Left[z] = Map[z];
}

void Input() {
	cin >> n >> m; p.rsz(n+1, -1); adj.rsz(n+1);
	d.rsz(n+1, 1); Left.rsz(n+1, INF); Map.rsz(n+1);
	for (int i=2; i<=n; i++) {
		cin >> p[i];
		adj[i].pub(p[i]);
		adj[p[i]].pub(i);
	}
	cin >> s;
}

void Solve() {
	DFS(1);
	while (m--) {
		cin >> v >> h;
		int st = lower_bound(DepthPX[h].begin(), DepthPX[h].end(), mp(Left[v], (int)-INF)) - DepthPX[h].begin();
		int en = lower_bound(DepthPX[h].begin(), DepthPX[h].end(), mp(Map[v], (int)+INF)) - DepthPX[h].begin() - 1;
		if (st > en) {cout << "Yes\n"; continue;}
		int Xor = DepthPX[h][en].se; if (st > 0) Xor ^= DepthPX[h][st-1].se;
		if (cntbit(Xor) < 2) cout << "Yes\n"; else cout << "No\n";
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