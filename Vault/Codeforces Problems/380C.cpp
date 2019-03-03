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
string s; i64 n, q, l, r; vi ans, Tree, Lazy;
vector<vector<pii>> queryLeft; stack<i64> S; map<i64, i64> Map;
/************************************************/

/************** [FUNCTIONS] **************/
void Update(i64 node, i64 st, i64 en, i64 L, i64 R, i64 val) {
	if (st > en || en < L || R < st) return;
	if (Lazy[node] != 0) {
		Tree[node] += Lazy[node];
		if (st != en) {Lazy[node*2] += Lazy[node]; Lazy[node*2+1] += Lazy[node];}
		Lazy[node] = 0;
	}
	if (L <= st && en <= R) {
		Tree[node] += val;
		if (st != en) {Lazy[node*2] += val; Lazy[node*2+1] += val;}
		return;
	}
	Update(node*2, st, (st+en)/2, L, R, val);
	Update(node*2+1, (st+en)/2+1, en, L, R, val);
	Tree[node] = max(Tree[node*2], Tree[node*2+1]);
}

i64 GetMax(i64 node, i64 st, i64 en, i64 L, i64 R) {
	if (st > en || en < L || R < st) return -LINF;
	if (Lazy[node] != 0) {
		Tree[node] += Lazy[node];
		if (st != en) {Lazy[node*2] += Lazy[node]; Lazy[node*2+1] += Lazy[node];}
		Lazy[node] = 0;
	}
	if (L <= st && en <= R) return Tree[node];
	i64 p1 = GetMax(node*2, st, (st+en)/2, L, R);
	i64 p2 = GetMax(node*2+1, (st+en)/2+1, en, L, R);
	return max(p1, p2);
}

void Input() {
	cin >> s >> q; n = s.size();
	ans.rsz(q); queryLeft.rsz(n);
	Tree.rsz(4*n, 0LL); Lazy.rsz(4*n, 0LL);
	for (i64 i=0; i<n; i++) Map[i] = -1;
	for (i64 i=0; i<q; i++) {
		cin >> l >> r; l--; r--;
		queryLeft[l].pub(mp(r, i));
	}
}

void Solve() {
	for (i64 i=0; i<n; i++) {
		if (s[i] == '(') S.push(i);
		else if (!S.empty()) {
			Map[S.top()] = i;
			S.pop();
		}
	}
	for (i64 L=n-1; L>=0; L--) {
		if (Map[L] != -1) Update(1, 0, n-1, Map[L], n-1, 1);
		for (auto R: queryLeft[L]) ans[R.se] = GetMax(1, 0, n-1, L, R.fi);
	}
	for (auto x: ans) cout << x*2 << endl;
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