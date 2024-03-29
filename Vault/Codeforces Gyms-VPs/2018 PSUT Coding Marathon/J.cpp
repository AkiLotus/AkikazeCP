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
i64 R, C, ans = 0; vector<vc> a; vector<vb> u, r, l, d;
queue<pii> Q; vector<vb> vis;
/************************************************/

/************** [FUNCTIONS] **************/
i64 getEdge(i64 x, i64 y) {
	i64 res = 0;
	res += u[x][y]; res += d[x][y];
	res += r[x][y]; res += l[x][y];
	return res;
}

void process(i64 i, i64 j) {
	char c = a[i][j];
	if (c == '-') {
		i64 x1 = i / 2 - 1;
		i64 y1 = (j - 1) / 2;
		i64 x2 = i / 2;
		i64 y2 = (j - 1) / 2;
		if (x1 >= 0 && x1 < R && y1 >= 0 && y1 < C) {
			d[x1][y1] = true;
			if (!vis[x1][y1] && getEdge(x1, y1) >= 3) {
				vis[x1][y1] = true;
				Q.push(mp(x1, y1));
			}
		}
		if (x2 >= 0 && x2 < R && y2 >= 0 && y2 < C) {
			u[x2][y2] = true;
			if (!vis[x2][y2] && getEdge(x2, y2) >= 3) {
				vis[x2][y2] = true;
				Q.push(mp(x2, y2));
			}
		}
	}
	else {
		i64 x1 = (i - 1) / 2;
		i64 y1 = j / 2 - 1;
		i64 x2 = (i - 1) / 2;
		i64 y2 = j / 2;
		if (x1 >= 0 && x1 < R && y1 >= 0 && y1 < C) {
			l[x1][y1] = true;
			if (!vis[x1][y1] && getEdge(x1, y1) >= 3) {
				vis[x1][y1] = true;
				Q.push(mp(x1, y1));
			}
		}
		if (x2 >= 0 && x2 < R && y2 >= 0 && y2 < C) {
			r[x2][y2] = true;
			if (!vis[x2][y2] && getEdge(x2, y2) >= 3) {
				vis[x2][y2] = true;
				Q.push(mp(x2, y2));
			}
		}
	}
}

void fill(i64 x, i64 y) {
	u[x][y] = true; d[x][y] = true;
	l[x][y] = true; r[x][y] = true;
	a[x*2][y*2+1] = '-'; process(x*2, y*2+1);
	a[x*2+1][y*2] = '|'; process(x*2+1, y*2);
	a[x*2+2][y*2+1] = '-'; process(x*2+2, y*2+1);
	a[x*2+1][y*2+2] = '|'; process(x*2+1, y*2+2);
}

void Input() {
	cin >> R >> C; a.rsz(R*2-1, vc(C*2-1, '.'));
	u.rsz(R, vb(C, false)); r = u; l = u; d = u;
	vis.rsz(R, vb(C, false));
	for (i64 i=0; i<R*2-1; i++) {
		for (i64 j=0; j<C*2-1; j++) {
			cin >> a[i][j];
			if ((i + j) % 2 != 0 && a[i][j] != '.') process(i, j);
		}
	}
}

void Solve() {
	for (i64 i=0; i<R; i++) {
		for (i64 j=0; j<C; j++) {
			ans -= (getEdge(i, j) == 4);
		}
	}
	while (!Q.empty()) {
		pii z = Q.front(); Q.pop();
		if (getEdge(z.fi, z.se) == 4) continue;
		fill(z.fi, z.se);
	}
	for (i64 i=0; i<R; i++) {
		for (i64 j=0; j<C; j++) {
			ans += (getEdge(i, j) == 4);
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