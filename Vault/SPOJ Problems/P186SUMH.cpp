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
i64 N, M, q, x, y; string S;
vi Mul, Inv, Tree;
/************************************************/

/************** [FUNCTIONS] **************/
void STBuild(i64 node, i64 st, i64 en) {
	if (st > en) return;
	if (st == en) {Tree[node] = ((S[st] == '1') * Mul[(N-1-st)%4]) % 5; return;}
	STBuild(node*2, st, (st+en)/2); STBuild(node*2+1, (st+en)/2+1, en);
	Tree[node] = (Tree[node*2] + Tree[node*2+1]) % 5;
}

i64 STGet(i64 node, i64 st, i64 en, i64 l, i64 r) {
	if (st > en || r < st || en < l) return 0;
	if (l <= st && en <= r) return Tree[node];
	i64 p1 = STGet(node*2, st, (st+en)/2, l, r);
	i64 p2 = STGet(node*2+1, (st+en)/2+1, en, l, r);
	return ((p1 + p2) % 5);
}

void STUpdate(i64 node, i64 st, i64 en, i64 i) {
	if (st > en || en < i || i < st) return;
	if (st == en && st == i) {
		if (S[i] == '0') Tree[node] += Mul[(N-1-st)%4]; else Tree[node] -= Mul[(N-1-st)%4];
		Tree[node] += 25; Tree[node] %= 5; return;
	}
	STUpdate(node*2, st, (st+en)/2, i); STUpdate(node*2+1, (st+en)/2+1, en, i);
	Tree[node] = (Tree[node*2] + Tree[node*2+1]) % 5;
}

void Input() {
	cin >> S >> M; N = S.size(); Tree.rsz(4*N);
	Mul.pub(1); Inv.pub(1); Mul.pub(2); Inv.pub(3);
	Mul.pub(4); Inv.pub(4); Mul.pub(3); Inv.pub(2);
}

void Solve() {
	STBuild(1, 0, N-1);
	while (M--) {
		cin >> q >> x >> y;
		if (q == 0) cout << (STGet(1, 0, N-1, x, y) * Inv[(N - y - 1) % 4]) % 5 << endl;
		else if (S[x] - '0' != y) {STUpdate(1, 0, N-1, x); S[x] = char(48+y);}
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