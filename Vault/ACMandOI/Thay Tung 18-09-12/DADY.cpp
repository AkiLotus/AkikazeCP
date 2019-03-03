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
#undef MultiTest // Switch this off if submitting multi-test problems.

void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
typedef pair<char, pii> pcp;
i64 n, m; vector<pcp> query;
map<i64, i64> Map; i64 N; vi StationList;
vector<map<i64, i64>> Tree;
/************************************************/

/************** [FUNCTIONS] **************/
void Update(i64 node, i64 st, i64 en, i64 pos, i64 val) {
	if (st > en || pos < st || en < pos) return;
	if (st == en && st == pos) {Tree[node][val]++; return;}
	Update(node*2, st, (st+en)/2, pos, val);
	Update(node*2+1, (st+en)/2+1, en, pos, val);
	Tree[node][val]++;
}

i64 GetMin(i64 node, i64 st, i64 en, i64 L, i64 R, i64 Token) {
	if (st > en || R < st || en < L) return LINF;
	if (L <= st && en <= R) {
		if (Tree[node].lower_bound(Token) == Tree[node].end()) return LINF;
		return Tree[node].lower_bound(Token)->fi;
	}
	i64 p1 = GetMin(node*2, st, (st+en)/2, L, R, Token);
	i64 p2 = GetMin(node*2+1, (st+en)/2+1, en, L, R, Token);
	return min(p1, p2);
}

void Input() {
	cin >> n >> m; query.rsz(m);
	for (i64 i=0; i<m; i++) {
		cin >> query[i].fi >> query[i].se.fi >> query[i].se.se;
		Map[query[i].se.fi]++;
	}
}

void Solve() {
	for (auto it=Map.begin(); it!=Map.end(); it++) StationList.pub(it->fi);
	Map.clear(); for (i64 i=0; i<StationList.size(); i++) Map[StationList[i]] = i;
	i64 N = StationList.size(); Tree.rsz(4*N);
	for (auto x: query) {
		if (x.fi == 'M') Update(1, 0, N-1, Map[x.se.fi], x.se.se);
		else {
			i64 ans = GetMin(1, 0, N-1, 0, Map[x.se.fi], x.se.se);
			if (ans == LINF) cout << "-1\n"; else cout << ans << endl;
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
	freopen("DADY.INP", "r", stdin);
	freopen("DADY.OUT", "w", stdout);
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