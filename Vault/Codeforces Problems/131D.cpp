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
i64 T, N, L, R; map<i64, i64> Ans; i64 intercept = -1;
vector<vi> Adj; map<pii, i64> Map; map<i64, pii> Map1; vi vis; bool doneCycle = false;
/************************************************/

/************** [FUNCTIONS] **************/
void DFS_Cycle(i64 z, i64 last) {
	vis[z] = 2;
	for (auto t: Adj[z]) {
		if (vis[t] == 1) continue;
		if (t == last) continue;
		if (vis[t] == 0) DFS_Cycle(t, z);
		else if (vis[t] == 2) {
			intercept = t;
			Ans[Map[mp(z,t)]]++;
			return;
		}
		if (intercept != -1 && !doneCycle) {
			Ans[Map[mp(z,t)]]++;
			if (z == intercept) doneCycle = true;
			return;
		}
		if (intercept != -1 && doneCycle) return;
	}
	if (intercept != -1 && doneCycle) return;
	vis[z] = 1;
}

void Input() {
	cin >> N; Adj.clear();
	intercept = -1; doneCycle = false;
	Map.clear(); Adj.rsz(N); Ans.clear();
	vis.clear(); vis.rsz(N, 0LL);
	for (i64 i=1; i<=N; i++) {
		cin >> L >> R; L--; R--;
		Adj[L].pub(R); Adj[R].pub(L);
		Map[mp(L,R)] = i; Map[mp(R,L)] = i;
		Map1[i] = mp(L, R);
	}
}

void Solve() {
	DFS_Cycle(0, -1); vi Dist(N, LINF); queue<i64> Q;
	vis.clear(); vis.rsz(N, 0);
	for (auto it=Ans.begin(); it!=Ans.end(); it++) {
		i64 z = it->fi;
		if (!vis[Map1[z].fi]) {Dist[Map1[z].fi] = 0; Q.push(Map1[z].fi); vis[Map1[z].fi] = 1;}
		if (!vis[Map1[z].se]) {Dist[Map1[z].se] = 0; Q.push(Map1[z].se); vis[Map1[z].se] = 1;}
	}
	while (!Q.empty()) {
		i64 z = Q.front(); Q.pop();
		for (auto t: Adj[z]) {
			if (vis[t]) continue;
			vis[t] = 1;
			Dist[t] = Dist[z] + 1;
			Q.push(t);
		}
	}
	for (auto x: Dist) cout << x << " ";
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