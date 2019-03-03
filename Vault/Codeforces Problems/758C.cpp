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
i64 n, m, k, x, y; vector<vi> Map;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> n >> m >> k >> x >> y;
	Map.rsz(n+1, vi(m+1, 0LL));
}

void Solve() {
	if (n == 1) {
		i64 cycle = m, Rem = k % m;
		i64 Min = k / m, Max = Min + (Rem > 0);
		if (y <= Rem) cout << Max << " " << Min << " " << Max << endl;
		else cout << Max << " " << Min << " " << Min << endl; return;
	}
	i64 cycle = (n - 1) * m * 2;
	i64 cnt = k / cycle, Rem = k % cycle;
	i64 Min = LINF, Max = -LINF, Sergei = 0;
	for (i64 i=1; i<n; i++) {
		if (Rem == 0) break;
		for (i64 j=1; j<=m; j++) {
			if (Rem == 0) break;
			Map[i][j]++; Rem--;
		}
	}
	for (i64 i=n; i>1; i--) {
		if (Rem == 0) break;
		for (i64 j=1; j<=m; j++) {
			if (Rem == 0) break;
			Map[i][j]++; Rem--;
		}
	}
	for (i64 i=1; i<=n; i++) {
		for (i64 j=1; j<=m; j++) {
			if (i == 1 || i == n) {
				Min = min(Min, cnt + Map[i][j]);
				Max = max(Max, cnt + Map[i][j]);
				if (i == x && j == y) Sergei = cnt + Map[i][j];
			}
			else {
				Min = min(Min, cnt * 2 + Map[i][j]);
				Max = max(Max, cnt * 2 + Map[i][j]);
				if (i == x && j == y) Sergei = cnt * 2 + Map[i][j];
			}
		}
	}
	cout << Max << " " << Min << " " << Sergei << endl;
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