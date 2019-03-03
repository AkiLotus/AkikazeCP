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
//#pragma comment(linker, "/stack:227420978")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
i64 X, Y, H, V; pii h[100003], v[100003]; i64 Tree[810000];
/************************************************/

/************** [FUNCTIONS] **************/
void DiscretizationX() {
	vi A(2, 0); A[1] = X; unordered_map<i64, i64> Map; Map[0]++; X++;
	for (i64 i=0; i<V; i++) {
		if (!Map[v[i].fi]) A.pub(v[i].fi); Map[v[i].fi]++;
		if (!Map[v[i].se]) A.pub(v[i].se); Map[v[i].se]++;
	}
	sort(A.begin(), A.end()); Map.clear();
	for (i64 i=0; i<A.size(); i++) Map[A[i]] = i;
	X = Map[X];
	for (i64 i=0; i<V; i++) {
		v[i].fi = Map[v[i].fi];
		v[i].se = Map[v[i].se];
	}
}

void DiscretizationY() {
	vi A(2, 0); A[1] = Y; unordered_map<i64, i64> Map; Map[0]++; Y++;
	for (i64 i=0; i<H; i++) {
		if (!Map[h[i].fi]) A.pub(h[i].fi); Map[h[i].fi]++;
		if (!Map[h[i].se]) A.pub(h[i].se); Map[h[i].se]++;
	}
	sort(A.begin(), A.end()); Map.clear();
	for (i64 i=0; i<A.size(); i++) Map[A[i]] = i;
	Y = Map[Y];
	for (i64 i=0; i<H; i++) {
		h[i].fi = Map[h[i].fi];
		h[i].se = Map[h[i].se];
	}
}

i64 Get(i64 node, i64 st, i64 en, i64 L, i64 R) {
	if (st > en || R < st || en < L) return 0;
	if (L <= st && en <= R) return Tree[node];
	i64 p1 = Get(node*2, st, (st+en)/2, L, R);
	i64 p2 = Get(node*2+1, (st+en)/2+1, en, L, R);
	return (p1 + p2);
}

void Inc(i64 node, i64 st, i64 en, i64 i) {
	if (st > en || i < st || en < i) return;
	if (st == en && st == i) {Tree[node]++; return;}
	Inc(node*2, st, (st+en)/2, i);
	Inc(node*2+1, (st+en)/2+1, en, i);
	Tree[node] = Tree[node*2] + Tree[node*2+1];
}

void Input() {
	cin >> X >> Y >> H >> V;
	for (i64 i=0; i<H; i++) cin >> h[i].fi >> h[i].se;
	for (i64 i=0; i<V; i++) cin >> v[i].fi >> v[i].se;
}

void Solve() {
	sort(h, h+H); sort(v, v+V);
	DiscretizationX(); DiscretizationY();
	i64 ans = 1;
	for (i64 i=0; i<H; i++) {
		pii x = h[i];
		i64 a = x.fi, b = x.se;
		i64 Total = Get(1, 0, 200010, b, 200010);
		ans += (Total + 1);
		Inc(1, 0, 200010, b);
	}
	for (i64 i=0; i<810000; i++) Tree[i] = 0;
	for (i64 i=0; i<V; i++) {
		pii x = v[i];
		i64 a = x.fi, b = x.se;
		i64 Total = Get(1, 0, 200010, b, 200010);
		ans += (Total + 1); ans += H;
		Inc(1, 0, 200010, b);
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