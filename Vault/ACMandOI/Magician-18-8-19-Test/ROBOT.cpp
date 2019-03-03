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

//#undef OImode // Switch this off if submitting OI problems.
//#undef MultiTest // Switch this off if submitting multi-test problems.

void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
i64 n, m, u, v, c; vi col; vector<vector<vector<vi>>> Adj;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> n >> m; Adj.clear(); col.clear();
	Adj.rsz(n, vector<vector<vi>>(3, vector<vi>(n, vi(3, 3)))); col.rsz(n);
	for (i64 i=0; i<n; i++) {cin >> col[i]; col[i]--;}
	while (m--) {
		cin >> u >> v >> c; u--; v--; c--;
		Adj[u][0][v][1] = (c + 0) % 3;
		Adj[u][1][v][2] = (c + 1) % 3;
		Adj[u][2][v][0] = (c + 2) % 3;
	}
}

void Solve() {
	vector<vi> visA(n, vi(3, -1)), visB(n, vi(3, -1));
	queue<i64> QA, QB; QA.push(0); QB.push(1); visA[0][0] = 0; visB[0][1] = 0;
	vector<vb> colA(n*4, vb(3, false)); colA[0][col[0]] = true;
	vector<vb> colB(n*4, vb(3, false)); colB[0][col[1]] = true;
	for (i64 i=1; i<n*4; i++) {
		vi A, B;
		while (!QA.empty()) {
			i64 z = QA.front(); QA.pop();
			for (i64 t=0; t<n; t++) {
				if (visA[t][i % 3] >= 0) continue;
				if (Adj[z][i % 3][t][(i + 1) % 3] == 3) continue;
				if (colB[i-1][Adj[z][i % 3][t][(i + 1) % 3]]) continue;
				visA[t][i % 3] = i; colA[i][col[t]] = true; A.pub(t);
			}
		}
		while (!QB.empty()) {
			i64 z = QB.front(); QB.pop();
			for (i64 t=0; t<n; t++) {
				if (visB[t][i % 3] >= 0) continue;
				if (Adj[z][i % 3][t][(i + 1) % 3] == 3) continue;
				if (colA[i-1][Adj[z][i % 3][t][(i + 1) % 3]]) continue;
				visB[t][i % 3] = i; colB[i][col[t]] = true; B.pub(t);
			}
		}
		tracker2(A, B);
		for (auto x: A) QA.push(x); for (auto x: B) QB.push(x);
	}
	tracker2(visA, visB);
	i64 ans = LINF;
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<3; j++) {
			if (visA[i][j] == visB[i][j]) {
				ans = min(ans, visA[i][j]);
			}
		}
	}
	if (ans == LINF) cout << "-1\n"; else cout << ans << endl;
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
	freopen("ROBOT.INP", "r", stdin);
	freopen("ROBOT.OUT", "w", stdout);
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