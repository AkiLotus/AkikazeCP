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
i64 n, k; vi a, LargerPrevious, LargerNext;
map<i64, i64> Last;
/************************************************/

/************** [FUNCTIONS] **************/
void FindLargerPrevious() {
	stack<i64> S;
	for (i64 i=n-1; i>=0; i--) {
		while (!S.empty() && a[S.top()] < a[i]) {
			LargerPrevious[S.top()] = i;
			S.pop();
		}
		S.push(i);
	}
}

void FindLargerNext() {
	stack<i64> S;
	for (i64 i=0; i<n; i++) {
		while (!S.empty() && a[S.top()] < a[i]) {
			LargerNext[S.top()] = i;
			S.pop();
		}
		S.push(i);
	}
}

void Input() {
	cin >> n >> k; a.rsz(n);
	LargerPrevious.rsz(n, -1); LargerNext.rsz(n, n);
	for (i64 i=0; i<n; i++) {cin >> a[i]; Last[a[i]] = -LINF;}
}

void Solve() {
	i64 ans = 0;
	FindLargerPrevious(); FindLargerNext();
	vi AppearanceCount(n, 0);
	for (i64 i=0; i<n; i++) {
		i64 L = LargerPrevious[i] + 1, R = LargerNext[i] - 1; tracker2(L, R);
		AppearanceCount[L]++; if (R < n-1) AppearanceCount[R+1]--;
		for (i64 x=k; x<=R-L+1; x+=(k-1)) {
			i64 l = i - (x - 1), r = i;
			i64 intL = max(l, L), intR = min(r, R);
			ans += (max(intR - intL + 1, 0LL) * a[i]) % Mod; ans %= Mod;
		}
	}
	for (i64 i=1; i<n; i++) AppearanceCount[i] += AppearanceCount[i-1];
	tracker2(AppearanceCount, ans);
	for (i64 i=0; i<n; i++) {
		i64 j = i; while (j + 1 < n && a[j+1] == a[i]) j++;
		i64 count = AppearanceCount[i] - 1;
		for (i64 x=k; x<=j-i+1; x+=(k-1)) {
			ans -= (((((j-i+1) - x + 1) * a[i]) % Mod) * count) % Mod; ans %= Mod;
		}
	}
	while (ans < 0) ans += Mod;
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