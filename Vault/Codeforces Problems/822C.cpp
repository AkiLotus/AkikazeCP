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
i64 n, q; vector<ppi> a;
/************************************************/

/************** [FUNCTIONS] **************/
bool rightsort(ppi a, ppi b) {
	if (a.fi.se < b.fi.se) return true;
	if (a.fi.se == b.fi.se && a.fi.fi < b.fi.fi) return true;
	if (a.fi.se == b.fi.se && a.fi.fi == b.fi.fi && a.se < b.se) return true;
	return false;
}

void Input() {
	cin >> n >> q; a.rsz(n);
	for (i64 i=0; i<n; i++) cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
}

void Solve() {
	sort(a.begin(), a.end(), rightsort); i64 ans = LINF;
	vector<ppi> aLeft = a; sort(aLeft.begin(), aLeft.end());
	vector<multiset<i64>> M(216512); i64 petr = 0;
	for (i64 i=0; i<n; i++) M[aLeft[i].fi.se-aLeft[i].fi.fi+1].insert(aLeft[i].se);
	for (auto x: a) {
		while (petr < n && aLeft[petr].fi.fi <= x.fi.se) {
			M[aLeft[petr].fi.se-aLeft[petr].fi.fi+1].erase(M[aLeft[petr].fi.se-aLeft[petr].fi.fi+1].find(aLeft[petr].se)); petr++;
		}
		if (q - (x.fi.se - x.fi.fi + 1) < 0) continue;
		if (!M[q - (x.fi.se - x.fi.fi + 1)].empty()) ans = min(ans, x.se + *M[q - (x.fi.se - x.fi.fi + 1)].begin());
	}
	if (ans != LINF) cout << ans; else cout << "-1";
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
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