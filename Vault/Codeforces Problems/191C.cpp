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
i64 n, k, a, b; vector<vi> adj, pos; vi cnt, Node, Level, firstSign;
map<pii, i64> id; vector<pii> DFSorder, pathCnt;
vector<vi> SpT_MinPos, SpT_MaxPos; vi Log2(200001);
/************************************************/

/************** [FUNCTIONS] **************/
void DFS(i64 z, i64 last) {
	if (last != -1) Level[z] = Level[last] + 1;
	firstSign[z] = DFSorder.size(); pos[z].pub(DFSorder.size());
	DFSorder.pub(mp(z, Level[z]));
	for (auto t: adj[z]) {
		if (t == last) continue;
		DFS(t, z); pos[z].pub(DFSorder.size());
		DFSorder.pub(mp(z, Level[z]));
	}
}

i64 LCA_MinID(i64 u, i64 v) {
	i64 en1a = SpT_MinPos[u][Log2[v-u+1]], en1b = SpT_MinPos[v+1-(1LL << Log2[v-u+1])][Log2[v-u+1]];
	if (DFSorder[en1a].se == DFSorder[en1b].se) return min(en1a, en1b);
	else if (DFSorder[en1a].se < DFSorder[en1b].se) return en1a; return en1b;
}

i64 DFS_Summation(i64 z, i64 last, i64 val) {
	for (auto t: adj[z]) {
		if (t == last) continue;
		DFS_Summation(t, z, val);
		Node[z] += Node[t];
	}
	if (last != -1) cnt[id[mp(z,last)]] = Node[z];
}

void Input() {
	cin >> n; adj.rsz(n); cnt.rsz(n-1, 0); pos.rsz(n);
	Level.rsz(n, 0); firstSign.rsz(n, -1); Node.rsz(n, 0);
	for (i64 i=0; i<n-1; i++) {
		cin >> a >> b; a--; b--;
		adj[a].pub(b); adj[b].pub(a);
		id[mp(a,b)] = i; id[mp(b,a)] = i;
	}
}

void Solve() {
	DFS(0, -1); pathCnt.rsz(DFSorder.size()-1); cin >> k; i64 ET = DFSorder.size();
	for (i64 i=1; i<200001; i++) {
		for (i64 j=17; j>=0; j--) {
			if ((1LL << j) <= i) {
				Log2[i] = j; break;
			}
		}
	}
	SpT_MinPos.rsz(ET); SpT_MaxPos.rsz(ET);
	for (i64 j=0; j<18; j++) {
		for (i64 i=0; i<ET; i++) {
			if (i + (1LL << j) - 1 >= ET) continue;
			if (j == 0) SpT_MinPos[i].pub(i);
			else if (DFSorder[SpT_MinPos[i][j-1]].se <= DFSorder[SpT_MinPos[i+(1LL << (j-1))][j-1]].se) SpT_MinPos[i].pub(SpT_MinPos[i][j-1]);
			else SpT_MinPos[i].pub(SpT_MinPos[i+(1LL << (j-1))][j-1]);
			if (j == 0) SpT_MaxPos[i].pub(i);
			else if (DFSorder[SpT_MaxPos[i][j-1]].se < DFSorder[SpT_MaxPos[i+(1LL << (j-1))][j-1]].se) SpT_MaxPos[i].pub(SpT_MaxPos[i][j-1]);
			else SpT_MaxPos[i].pub(SpT_MaxPos[i+(1LL << (j-1))][j-1]);
		}
	}
	for (i64 i=0; i<pathCnt.size(); i++) pathCnt[i].se = id[mp(DFSorder[i].fi, DFSorder[i+1].fi)];
	while (k--) {
		cin >> a >> b; a--; b--;
		if (firstSign[a] > firstSign[b]) swap(a, b);
		i64 st = firstSign[a], en = firstSign[b], mid = DFSorder[LCA_MinID(st, en)].fi;
		Node[mid] -= 2; Node[a]++; Node[b]++;
	}
	DFS_Summation(0, -1, 0);
	for (i64 i=1; i<pathCnt.size(); i++) pathCnt[i].fi += pathCnt[i-1].fi;
	for (auto x: pathCnt) cnt[x.se] += x.fi;
	for (auto x: cnt) cout << x << " ";
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
	#ifndef Akikaze
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
