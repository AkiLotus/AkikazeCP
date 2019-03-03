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
i64 n, k; vi a; vector<vector<pii>> A;
/************************************************/

/************** [FUNCTIONS] **************/
vector<pii> factorization(i64 z) {
	vector<pii> res;
	for (i64 i=2; i<=sqrt(z); i++) {
		i64 cnt = 0;
		while (z % i == 0) {z /= i; cnt++;}
		if (cnt) res.pub(mp(i, cnt));
	}
	if (z > 1) res.pub(mp(z, 1LL));
	return res;
}

i64 calc(i64 Max, i64 mask) {
	map<i64, i64> Map; i64 res = 1;
	for (i64 i=0; i<n; i++) {
		if ((mask & (1LL << i)) == 0) continue;
		for (auto x: A[i]) Map[x.fi] = max(Map[x.fi], x.se);
	}
	for (auto it=Map.begin(); it!=Map.end(); it++) {
		i64 d = it->fi, c = it->se;
		for (i64 x=0; x<c; x++) {
			if (Max / d < res) return 0;
			res *= d;
		}
	}
	return (Max / res);
}

void Input() {
	cin >> n >> k;
	a.clear(); A.clear();
	a.rsz(n); A.rsz(n);
	for (i64 i=0; i<n; i++) {
		cin >> a[i];
		A[i] = factorization(a[i]);
	}
}

void Solve() {
	i64 ans = 0, top = 1, bot = LINF;
	while (top <= bot) {
		i64 mid = (top + bot) / 2, cnt = mid;
		for (i64 i=1; i<(1LL << n); i++) {
			i64 bitcnt = cntbit(i);
			if (bitcnt % 2 > 0) cnt -= calc(mid, i);
			else cnt += calc(mid, i);
		}
		if (cnt >= k) {
			if (cnt == k) ans = mid;
			bot = mid - 1;
		}
		else top = mid + 1;
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
	freopen("DEL.INP", "r", stdin);
	freopen("DEL.OUT", "w", stdout);
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