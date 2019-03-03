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
typedef pair<pii, pii> ppp;
i64 n, ans = 0; vector<ppp> Segments;
map<pii, set<i64>> Map;
/************************************************/

/************** [FUNCTIONS] **************/
void Process(ppp x, ppp y, i64 i, i64 j) {
	pii vecX = mp(x.se.fi - x.fi.fi, x.se.se - x.fi.se);
	pii vecY = mp(y.se.fi - y.fi.fi, y.se.se - y.fi.se);
	i64 ax = vecX.se, bx = -vecX.fi, cx = ax * x.fi.fi + bx * x.fi.se;
	i64 ay = vecY.se, by = -vecY.fi, cy = ay * y.fi.fi + by * y.fi.se;
	
	i64 D = ax * by - ay * bx;
	i64 Dx = cx * by - cy * bx;
	i64 Dy = ax * cy - ay * cx;
	
	if (D == 0) return;
	if (Dx % D != 0 || Dy % D != 0) return;
	
	i64 A = Dx / D, B = Dy / D;
	
	if (A < min(x.fi.fi, x.se.fi) || A > max(x.fi.fi, x.se.fi)) return;
	if (A < min(y.fi.fi, y.se.fi) || A > max(y.fi.fi, y.se.fi)) return;
	if (B < min(x.fi.se, x.se.se) || B > max(x.fi.se, x.se.se)) return;
	if (B < min(y.fi.se, y.se.se) || B > max(y.fi.se, y.se.se)) return;
	
	Map[mp(A, B)].insert(i); Map[mp(A, B)].insert(j);
}

void Input() {
	cin >> n; Segments.rsz(n);
	for (i64 i=0; i<n; i++) {
		cin >> Segments[i].fi.fi >> Segments[i].fi.se;
		cin >> Segments[i].se.fi >> Segments[i].se.se;
		ans += (__gcd(abs(Segments[i].fi.fi - Segments[i].se.fi), abs(Segments[i].fi.se - Segments[i].se.se)) + 1);
	}
}

void Solve() {
	for (i64 i=0; i<n; i++) {
		for (i64 j=i+1; j<n; j++) {
			Process(Segments[i], Segments[j], i, j);
		}
	}
	for (auto it=Map.begin(); it!=Map.end(); it++) {
		ans -= it->se.size(); ans++;
	}
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