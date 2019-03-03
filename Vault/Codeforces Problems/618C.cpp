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
i64 n; vector<ppi> a;
/************************************************/

/************** [FUNCTIONS] **************/
ld angle(pii vec) {
	ld dotProduct = vec.se;
	ld productLen = 1.0L;
	productLen *= sqrt((ld)(vec.fi * vec.fi + vec.se * vec.se));
	return acos(dotProduct / productLen);
}

bool cw(ppi x, ppi y) {
	pii va = mp(x.fi.fi - a[0].fi.fi, x.fi.se - a[0].fi.se);
	pii vb = mp(y.fi.fi - a[0].fi.fi, y.fi.se - a[0].fi.se);
	if (va.fi == 0 && vb.fi == 0) {
		if (va.se * vb.se < 0) return (va.se > vb.se);
		return (abs(va.se) < abs(vb.se));
	}
	if (va.fi == 0) {
		if (vb.fi > 0) return (va.se > 0);
		return true;
	}
	if (vb.fi == 0) {
		if (va.fi > 0) return (vb.se < 0);
		return false;
	}
	if (va.fi * vb.fi < 0) return (va.fi > vb.fi);
	if (va.fi > 0) {
		if (va.se == 0 && vb.se == 0) return (va.fi < vb.fi);
		if (va.se == 0) return (vb.se < 0);
		if (vb.se == 0) return (va.se > 0);
		if (va.se * vb.se < 0) return (va.se > vb.se);
		if (fabs(angle(va) - angle(vb)) <= EPS) return (va.fi < vb.fi);
		return (angle(va) < angle(vb));
	}
	if (va.fi < 0) {
		if (va.se == 0 && vb.se == 0) return (va.fi > vb.fi);
		if (va.se == 0) return (vb.se > 0);
		if (vb.se == 0) return (va.se < 0);
		if (va.se * vb.se < 0) return (va.se < vb.se);
		if (va.se > 0) return (va.fi < vb.fi);
		if (fabs(angle(va) - angle(vb)) <= EPS) return (va.fi > vb.fi);
		return (angle(va) > angle(vb));
	}
	return false;
}

bool similar(ppi x, ppi y) {
	pii va = mp(x.fi.fi - a[0].fi.fi, x.fi.se - a[0].fi.se);
	pii vb = mp(y.fi.fi - a[0].fi.fi, y.fi.se - a[0].fi.se);
	i64 gcda = __gcd(va.fi, va.se); va.fi /= gcda; va.se /= gcda;
	i64 gcdb = __gcd(vb.fi, vb.se); vb.fi /= gcdb; vb.se /= gcdb;
	pii vc = vb; vc.fi = -vc.fi; vc.se = -vc.se;
	return (va == vb || va == vc);
}

void Input() {
	cin >> n; a.rsz(n);
	for (i64 i=0; i<n; i++) {
		cin >> a[i].fi.fi >> a[i].fi.se;
		a[i].se = i + 1;
	}
}

void Solve() {
	sort(a.begin()+1, a.end(), cw);
	cout << a[0].se << " " << a[1].se << " ";
	for (i64 i=2; i<n; i++) {
		if (!similar(a[i], a[1])) {
			cout << a[i].se; return;
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