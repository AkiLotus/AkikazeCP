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
i64 n, m, l, r, x; vi a; vector<pii> Tree;
/************************************************/

/************** [FUNCTIONS] **************/
void STBuild(i64 node, i64 st, i64 en) {
	if (st > en) return;
	if (st == en) {Tree[node] = mp(st, st); return;}
	STBuild(node*2, st, (st+en)/2);
	STBuild(node*2+1, (st+en)/2+1, en);
	pii res = mp(Tree[node*2].fi, Tree[node*2].se);
	if (a[Tree[node*2+1].fi] < a[Tree[node*2].fi]) res.fi = Tree[node*2+1].fi;
	if (a[Tree[node*2+1].se] > a[Tree[node*2].se]) res.se = Tree[node*2+1].se;
	Tree[node] = res;
}

pii Get(i64 node, i64 st, i64 en, i64 L, i64 R) {
	if (st > en || st > R || L > en) return mp(-1LL, -1LL);
	if (L <= st && en <= R) return Tree[node];
	pii p1 = Get(node*2, st, (st+en)/2, L, R);
	pii p2 = Get(node*2+1, (st+en)/2+1, en, L, R);
	pii res = mp(p1.fi, p1.se);
	if (p1.fi == -1 || (p2.fi != -1 && a[p2.fi] < a[p1.fi])) res.fi = p2.fi;
	if (p1.se == -1 || (p2.se != -1 && a[p2.se] > a[p1.se])) res.se = p2.se;
	return res;
}

void Input() {
	cin >> n >> m; a.rsz(n); Tree.rsz(4*n);
	for (i64 i=0; i<n; i++) cin >> a[i];
}

void Solve() {
	STBuild(1, 0, n-1);
	while (m--) {
		cin >> l >> r >> x; l--; r--;
		pii z = Get(1, 0, n-1, l, r);
		if (a[z.fi] == x && a[z.se] == x) cout << "-1\n";
		else if (a[z.fi] != x) cout << z.fi + 1 << endl;
		else cout << z.se + 1 << endl;
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