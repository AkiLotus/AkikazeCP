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
i64 n, m, a, b, QA, QB, QC, QD; vector<vi> adj;
vi A; vector<vi> Table; vi Dist, d, C; vb vis;
/************************************************/

/************** [FUNCTIONS] **************/
void DFS(i64 z, i64 last) {
	if (z != 0) d[z] = d[last] + 1;
	for (auto t: adj[z]) {
		if (t == last) continue;
		DFS(t, z); Table[t].pub(z);
	}
}

void Preprocess() {
	Dist.rsz(n, 0); vis.rsz(n, false);
	Table.rsz(n); d.rsz(n, 0); DFS(0, -1);
	for (i64 j=1; j<17; j++) {
		for (i64 i=0; i<n; i++) {
			if (Table[i].size() < j) continue;
			if (Table[Table[i][j-1]].size() < j) continue;
			Table[i].pub(Table[Table[i][j-1]][j-1]);
		}
	}
}

i64 LCA(i64 x, i64 y) {
	if (x == y) return x;
	if (d[x] == d[y]) {
		i64 id = 0;
		for (i64 i=min(Table[x].size(), Table[y].size()-1); i>=0; i--) {
			if (Table[x][i] != Table[y][i]) {id = i; break;}
		}
		return LCA(Table[x][id], Table[y][id]);
	}
	if (d[x] < d[y]) {
		i64 mul = 1, id = 0;
		while (d[x] < d[y] - mul * 2) {
			mul *= 2; id++;
		}
		return LCA(x, Table[y][id]);
	}
	if (d[x] > d[y]) {
		i64 mul = 1, id = 0;
		while (d[y] < d[x] - mul * 2) {
			mul *= 2; id++;
		}
		return LCA(Table[x][id], y);
	}
}

bool parentChild(i64 x, i64 y, bool strict) {
	if (!strict) {if (d[x] < d[y]) swap(x, y);}
	while (d[x] > d[y]) {
		i64 id = 0;
		for (i64 i=Table[x].size(); i>=0; i--) {
			if (d[x] - (1LL << i) >= d[y]) {
				id = i; break;
			}
		}
		x = Table[x][id];
	}
	return (x == y);
}

void Input() {
	cin >> n >> m; adj.rsz(n); A.pub(0);
	for (i64 i=1; i<n; i++) {
		cin >> a >> b; a--; b--;
		adj[a].pub(b); adj[b].pub(a);
	}
}

void Solve() {
	Preprocess();
	while (m--) {
		cin >> QA >> QB >> QC >> QD;
		QA--; QB--; QC--; QD--;
		i64 Z1 = LCA(QA, QB), Z2 = LCA(QC, QD);
		if (LCA(Z1, Z2) != Z1 && LCA(Z1, Z2) != Z2) {cout << "0\n"; continue;}
		if (Z1 == Z2) {
			i64 ans = 1;
			if (parentChild(QA, QC, false)) ans += min(d[QA], d[QC]) - d[Z1];
			if (parentChild(QA, QD, false)) ans += min(d[QA], d[QD]) - d[Z1];
			if (parentChild(QB, QC, false)) ans += min(d[QB], d[QC]) - d[Z1];
			if (parentChild(QB, QD, false)) ans += min(d[QB], d[QD]) - d[Z1];
			cout << ans << endl; continue;
		}
		i64 Not = LCA(Z1, Z2), CommonUp = Z1;
		if (Not == Z1) CommonUp = Z2;
		i64 ans = 0;
		i64 z1 = LCA(QA, QC);
		if (parentChild(z1, CommonUp, true)) {
			if (parentChild(QA, QC, false)) ans = max(ans, 1LL);
			else ans = max(ans, d[z1] - d[CommonUp] + 1);
		}
		i64 z2 = LCA(QA, QD);
		if (parentChild(z2, CommonUp, true)) {
			if (parentChild(QA, QD, false)) ans = max(ans, 1LL);
			else ans = max(ans, d[z2] - d[CommonUp] + 1);
		}
		i64 z3 = LCA(QB, QC);
		if (parentChild(z3, CommonUp, true)) {
			if (parentChild(QB, QC, false)) ans = max(ans, 1LL);
			else ans = max(ans, d[z3] - d[CommonUp] + 1);
		}
		i64 z4 = LCA(QB, QD);
		if (parentChild(z4, CommonUp, true)) {
			if (parentChild(QB, QD, false)) ans = max(ans, 1LL);
			else ans = max(ans, d[z4] - d[CommonUp] + 1);
		}
		cout << ans << endl;
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