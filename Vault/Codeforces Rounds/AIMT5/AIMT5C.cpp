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
i64 n; vector<ppp> A;
/************************************************/

/************** [FUNCTIONS] **************/
bool intersect(ppp x, ppp y) {
	if (x.se.fi < y.fi.fi) return false;
	if (y.se.fi < x.fi.fi) return false;
	if (x.se.se < y.fi.se) return false;
	if (y.se.se < x.fi.se) return false;
	return true;
}

void Input() {
	cin >> n; A.rsz(n);
	for (i64 i=0; i<n; i++) cin >> A[i].fi.fi >> A[i].fi.se >> A[i].se.fi >> A[i].se.se;
}

void Solve() {
	vector<ppp> Left(n, A[0]), Right(n, A[n-1]);
	for (i64 i=1; i<n; i++) {
		if (Left[i-1] == mp(mp(LINF, LINF), mp(-LINF, -LINF))) {Left[i] = Left[i-1]; continue;};
		if (!intersect(Left[i-1], A[i])) {Left[i] =  mp(mp(LINF, LINF), mp(-LINF, -LINF)); continue;}
		Left[i] = Left[i-1];
		Left[i].fi.fi = max(Left[i].fi.fi, A[i].fi.fi); Left[i].fi.se = max(Left[i].fi.se, A[i].fi.se);
		Left[i].se.fi = min(Left[i].se.fi, A[i].se.fi); Left[i].se.se = min(Left[i].se.se, A[i].se.se);
	}
	for (i64 i=n-2; i>=0; i--) {
		if (Right[i+1] == mp(mp(LINF, LINF), mp(-LINF, -LINF))) {Right[i] = Right[i+1]; continue;};
		if (!intersect(Right[i+1], A[i])) {Right[i] =  mp(mp(LINF, LINF), mp(-LINF, -LINF)); continue;}
		Right[i] = Right[i+1];
		Right[i].fi.fi = max(Right[i].fi.fi, A[i].fi.fi); Right[i].fi.se = max(Right[i].fi.se, A[i].fi.se);
		Right[i].se.fi = min(Right[i].se.fi, A[i].se.fi); Right[i].se.se = min(Right[i].se.se, A[i].se.se);
	}
	//cout << Left << endl << Right << endl;
	for (i64 i=0; i<n; i++) {
		ppp L = mp(mp(-LINF, -LINF), mp(LINF, LINF)), R = L;
		if (i > 0) {
			if (Left[i-1] == mp(mp(LINF, LINF), mp(-LINF, -LINF))) continue;
			L.fi.fi = max(L.fi.fi, Left[i-1].fi.fi); L.fi.se = max(L.fi.se, Left[i-1].fi.se);
			L.se.fi = min(L.se.fi, Left[i-1].se.fi); L.se.se = min(L.se.se, Left[i-1].se.se);
		}
		if (i < n-1) {
			if (Right[i+1] == mp(mp(LINF, LINF), mp(-LINF, -LINF))) continue;
			R.fi.fi = max(R.fi.fi, Right[i+1].fi.fi); R.fi.se = max(R.fi.se, Right[i+1].fi.se);
			R.se.fi = min(R.se.fi, Right[i+1].se.fi); R.se.se = min(R.se.se, Right[i+1].se.se);
		}
		//tracker2(L, R);
		if (intersect(L, R)) {
			ppp Z = L;
			Z.fi.fi = max(Z.fi.fi, R.fi.fi); Z.fi.se = max(Z.fi.se, R.fi.se);
			Z.se.fi = min(Z.se.fi, R.se.fi); Z.se.se = min(Z.se.se, R.se.se);
			cout << Z.fi.fi << " " << Z.fi.se; return;
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