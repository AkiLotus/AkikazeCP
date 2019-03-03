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
i64 n, t; vi a, Tree;
/************************************************/

/************** [FUNCTIONS] **************/
void Increment(i64 node, i64 st, i64 en, i64 i) {
	if (st > en || en < i || i < st) return;
	if (st == en && st == i) {Tree[node]++; return;}
	Increment(node*2, st, (st+en)/2, i);
	Increment(node*2+1, (st+en)/2+1, en, i);
	Tree[node] = Tree[node*2] + Tree[node*2+1];
}

i64 GetSum(i64 node, i64 st, i64 en, i64 L, i64 R) {
	if (st > en || R < st || en < L) return 0;
	if (L <= st && en <= R) return Tree[node];
	i64 p1 = GetSum(node*2, st, (st+en)/2, L, R);
	i64 p2 = GetSum(node*2+1, (st+en)/2+1, en, L, R);
	return (p1 + p2);
}

void Input() {
	cin >> n >> t; a.rsz(n+1); Tree.rsz(6*n, 0);
	for (i64 i=1; i<=n; i++) cin >> a[i];
}

void Solve() {
	vector<pii> ps(n+1, mp(0LL, 0LL));
	for (i64 i=1; i<=n; i++) {
		ps[i].fi = ps[i-1].fi + a[i];
		ps[i].se = i;
	}
	sort(ps.begin(), ps.end());
	//for (auto x: ps) cout << x << " "; cout << endl;
	i64 petr = -1, ans = n * (n + 1) / 2;
	for (i64 i=0; i<n+1; i++) {
		while (petr + 1 <= n && ps[petr+1].fi <= ps[i].fi - t) {
			petr++; Increment(1, 0, n, ps[petr].se);
		}
		if (ps[i].se != 0) ans -= GetSum(1, 0, n, 0, ps[i].se-1);
		//tracker3(i, petr, ans);
	}
	cout << ans;
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