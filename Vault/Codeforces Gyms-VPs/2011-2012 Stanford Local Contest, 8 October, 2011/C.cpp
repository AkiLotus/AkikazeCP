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
i64 n, q, u, v, w, d; vector<vector<pii>> child, Adj;
vector<vi> parentExp, distExp; vi Level, Log2(100001);
map<i64, i64> MapVertex; set<i64> Cycle;
map<i64, i64> Ans; i64 intercept = -1;
map<pii, i64> Map, Mp; vi vis; bool doneCycle = false;
vi List
/************************************************/

/************** [FUNCTIONS] **************/
void DFS_Cycle(i64 z, i64 last) {
	vis[z] = 2;
	for (auto T: Adj[z]) {
		i64 t = T.fi;
		if (vis[t] == 1) continue;
		if (t == last) continue;
		if (vis[t] == 0) DFS_Cycle(t, z);
		else if (vis[t] == 2) {
			intercept = t;
			Ans[Map[mp(z,t)]]++;
			MapVertex[z] = n; MapVertex[t] = n;
			Cycle.insert(z); Cycle.insert(t);
			return;
		}
		if (intercept != -1 && !doneCycle) {
			Ans[Map[mp(z,t)]]++;
			MapVertex[z] = n; MapVertex[t] = n;
			Cycle.insert(z); Cycle.insert(t);
			if (z == intercept) doneCycle = true;
			return;
		}
		if (intercept != -1 && doneCycle) return;
	}
	if (intercept != -1 && doneCycle) return;
	vis[z] = 1;
}

void DFS(i64 z) {
	for (auto x: child[z]) {
		Level[x] = Level[z] + 1;
		DFS(x);
	}
}

void DFS_FindChildren(i64 z, i64 last) {
	for (auto T: Adj[z]) {
		i64 t = T.fi;
		if (t == last) continue;
		child[z].pub(t); DFS_FindChildren(t, z);
	}
}

void Input() {
	cin >> n;
}

void Solve() {
	while (n--) {
		Adj.clear(); Adj.rsz(n);
		child.clear(); child.rsz(n+1);
		Level.clear(); Level.rsz(n+1, 0LL);
		parentExp.clear(); parentExp.rsz(n+1, vi(20));
		distExp.clear(); distExp.rsz(n+1, vi(20));
		Map.clear(); Mp.clear(); Ans.clear(); vis.clear(); vis.rsz(n, 0LL);
		intercept = -1; doneCycle = false; MapVertex.clear();
		for (i64 i=0; i<n; i++) MapVertex[i] = i;
		for (i64 i=0; i<n; i++) {
			cin >> u >> v >> d;
			Adj[u].pub(mp(v, d));
			Adj[v].pub(mp(u, d));
			Map[mp(u,v)] = i; Map[mp(v,u)] = i;
			Mp[mp(u,v)] = d; Mp[mp(v,u)] = d;
		}
		
		DFS_Cycle(0, -1);
		
		for (auto it=Cycle.begin(); it!=Cycle.end(); it++) {
			i64 M = *it;
			for (auto z: Adj[M]) {
				i64 N = z.fi;
				DFS_FindChildren(N, M);
			}
		}
		
		
		for (i64 i=0; i<N; i++) {
			i64 z = child[i].size();
			for (i64 j=0; j<z; j++) {
				parentExp[child[i][j]][0] = i;
				distExp[child[i][j]][0] = Mp[mp(i, child[i][j])];
			}
		}
		
		DFS(n);
		
		for (i64 k=1; k<20; k++) {
			for (i64 i=0; i<n; i++) {
				if (Level[i] < (1LL << k)) continue;
				parentExp[i][k] = parentExp[parentExp[i][k-1]][k-1];
				distExp[i][k] = distExp[i][k-1] + distExp[parentExp[i][k-1]][k-1];
			}
		}
		
		cin >> q;
		while (q--) {
			i64 Distance = 0;
			cin >> v >> w; if (Level[v] < Level[w]) swap(v, w);
			//cout << "preprocess:\n";
			while (Level[v] > Level[w]) {
				i64 step = Log2[Level[v]-Level[w]];
				//tracker3(v, w, step);
				v = parentExp[v][step]; Distance += distExp[v][step];
			}
			//cout << "tracing-back:\n";
			while (MapVertex[v] != MapVertex[w]) {
				i64 k = 0;
				while (MapVertex[parentExp[v][k]] != MapVertex[parentExp[w][k]]) k++;
				//tracker3(v, w, k);
				if (k > 0) k--; v = parentExp[v][k]; w = parentExp[w][k];
				Distance += distExp[v][step]; Distance += distExp[w][step];
			}
			
			Distance += d(v, w);
			
			cout << Distance << endl;
		}
		
		cin >> n;
	}
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	ControlIO(argc, argv);
	#ifndef MultiTest
		for (i64 i=1; i<100001; i++) {
			for (i64 j=19; j>=0; j--) {
				if ((1LL << j) <= i) {Log2[i] = j; break;}
			}
		}
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