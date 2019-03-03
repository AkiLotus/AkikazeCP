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
const long long Mod = 1000007LL, INF = 1e9, LINF = 1e18;
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
i64 n, m, k; vi ftrl29(200003, 1), ftrl34483(200003, 1);
i64 Mod29 = 29LL, Mod34483 = 34483LL;
/************************************************/

/************** [FUNCTIONS] **************/
i64 modPow(i64 a, i64 b, i64 M) {
	if (b == 0) return 1;
	if (b == 1) return (a % M);
	i64 tmp = modPow(a, b/2, M);
	if (b % 2 == 0) return ((tmp * tmp) % M);
	return ((((tmp * tmp) % M) * a) % M);
}

i64 nCr29(i64 n, i64 r) {
	if (n == r || r == 0) return 1;
	i64 divisorCount = 0, M = 29, tmp = n;
	while (tmp > 0) {divisorCount += tmp / M; tmp /= M;}
	tmp = n - r;
	while (tmp > 0) {divisorCount -= tmp / M; tmp /= M;}
	tmp = r;
	while (tmp > 0) {divisorCount -= tmp / M; tmp /= M;}
	if (divisorCount > 0) return 0;
	i64 numer = ftrl29[n];
	i64 denom = (ftrl29[n-r] * ftrl29[r]) % Mod29;
	return ((numer * modPow(denom, Mod29-2, Mod29)) % Mod29);
}

i64 nCr34483(i64 n, i64 r) {
	if (n == r || r == 0) return 1;
	i64 divisorCount = 0, M = 34483, tmp = n;
	while (tmp > 0) {divisorCount += tmp / M; tmp /= M;}
	tmp = n - r;
	while (tmp > 0) {divisorCount -= tmp / M; tmp /= M;}
	tmp = r;
	while (tmp > 0) {divisorCount -= tmp / M; tmp /= M;}
	if (divisorCount > 0) return 0;
	i64 numer = ftrl34483[n];
	i64 denom = (ftrl34483[n-r] * ftrl34483[r]) % Mod34483;
	return ((numer * modPow(denom, Mod34483-2, Mod34483)) % Mod34483);
}

void Input() {
	cin >> n >> m >> k;
	for (i64 i=1; i<200003; i++) {
		i64 z = i; while (z % Mod29 == 0) z /= Mod29;
		ftrl29[i] = (ftrl29[i-1] * z) % Mod29;
	};
	for (i64 i=1; i<200003; i++) {
		i64 z = i; while (z % Mod34483 == 0) z /= Mod34483;
		ftrl34483[i] = (ftrl34483[i-1] * z) % Mod34483;
	}
}

void Solve() {
	i64 ans29 = 0, ans34483 = 0;
	for (i64 i=0; i<=n; i++) {
		//tracker2(i, k);
		//tracker2(nCr29(n+k-1, n-1), nCr29(n, i));
		//tracker2(nCr34483(n+k-1, n-1), nCr34483(n, i));
		ans29 += nCr29(n+k-1, n-1) * nCr29(n, i) * (1 - 2 * (i % 2));
		ans29 %= Mod29; while (ans29 < 0) ans29 += Mod29;
		ans34483 += nCr34483(n+k-1, n-1) * nCr34483(n, i) * (1 - 2 * (i % 2));
		ans34483 %= Mod34483; while (ans34483 < 0) ans34483 += Mod34483;
		//tracker3(i, ans29, ans34483);
		k -= (m + 1);
		if (k < 0) break;
	}
	i64 ans = 0;
	for (i64 i=0; i<1000007LL; i++) {
		if (i % Mod29 == ans29 && i % Mod34483 == ans34483) {
			ans = i; break;
		}
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