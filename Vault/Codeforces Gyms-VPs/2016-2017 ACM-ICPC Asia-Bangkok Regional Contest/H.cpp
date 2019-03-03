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
#define i64 short int
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
//#undef MultiTest // Switch this off if submitting multi-test problems.

void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
typedef pair<pii, pii> ppp;
i64 K, M, N; vi E, P;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> K >> M >> N; E.clear(); P.clear();
	E.rsz(N); P.rsz(N);
	for (i64 i=0; i<N; i++) cin >> E[i];
	for (i64 i=0; i<N; i++) cin >> P[i];
}

void Solve() {
	queue<ppp> Q; i64 ans = 0; map<ppp, i64> Map;
	Q.push(mp(mp((i64)100, (i64)0), mp((i64)0, (i64)0)));
	Map[mp(mp((i64)100, (i64)0), mp((i64)0, (i64)0))]++;
	while (!Q.empty()) {
		ppp RR = Q.front(); Q.pop();
		i64 e = RR.fi.fi, p = RR.fi.se, cnt = RR.se.fi, mask = RR.se.se;
		ans = max(ans, cnt);
		if (e <= K) continue;
		i64 e1 = e - K, p1 = max(0, p - M), cnt1 = cnt+1;
		if (!Map[mp(mp(e1, p1), mp(cnt1, mask))]) {
			Map[mp(mp(e1, p1), mp(cnt1, mask))]++;
			Q.push(mp(mp(e1, p1), mp(cnt1, mask)));
		}
		for (i64 x=0; x<N; x++) {
			i64 mask1 = mask | ((i64)1 << x);
			if (mask1 == mask) continue;
			i64 e2 = min(100, e1 + E[x]), p2 = p1 + P[x];
			if (p2 >= 100) continue;
			if (!Map[mp(mp(e2, p2), mp(cnt1, mask1))]) {
				Map[mp(mp(e2, p2), mp(cnt1, mask1))]++;
				Q.push(mp(mp(e2, p2), mp(cnt1, mask1)));
			}
		}
	}
	cout << ans << endl;
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