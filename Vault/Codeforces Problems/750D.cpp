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
#define i64 short
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
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
vi HashMod(keymod, keymod + sizeof(keymod) / sizeof(long long));
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
typedef pair<pii, pip> iiiii;
i64 n, offset = 250, o = 1; vi t; map<pii, pii> NextL, NextR;
bool vis[501][501][31][3][3], inQueue[501][501][31][3][3];
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	NextL[mp(0, +1)] = mp(-1, +1);
	NextL[mp(-1, +1)] = mp(-1, 0);
	NextL[mp(-1, 0)] = mp(-1, -1);
	NextL[mp(-1, -1)] = mp(0, -1);
	NextL[mp(0, -1)] = mp(+1, -1);
	NextL[mp(+1, -1)] = mp(+1, 0);
	NextL[mp(+1, 0)] = mp(+1, +1);
	NextL[mp(+1, +1)] = mp(0, +1);
	NextR[mp(0, +1)] = mp(+1, +1);
	NextR[mp(+1, +1)] = mp(+1, 0);
	NextR[mp(+1, 0)] = mp(+1, -1);
	NextR[mp(+1, -1)] = mp(0, -1);
	NextR[mp(0, -1)] = mp(-1, -1);
	NextR[mp(-1, -1)] = mp(-1, 0);
	NextR[mp(-1, 0)] = mp(-1, +1);
	NextR[mp(-1, +1)] = mp(0, +1);
	cin >> n; t.rsz(n);
	for (i64 i=0; i<n; i++) cin >> t[i];
}

void Solve() {
	queue<iiiii> Q; Q.push(mp(mp(offset, t[0]+offset), mp(1, mp(o+0, o+1))));
	for (i64 i=1; i<=t[0]; i++) vis[offset][i+offset][1][o+0][o+1] = true;
	while (!Q.empty()) {
		iiiii z = Q.front(); Q.pop();
		i64 x = z.fi.fi-offset, y = z.fi.se-offset, d = z.se.fi, a = z.se.se.fi-o, b = z.se.se.se-o;
		if (d == n) continue;
		i64 AL = NextL[mp(a, b)].fi, BL = NextL[mp(a, b)].se, AR = NextR[mp(a, b)].fi, BR = NextR[mp(a, b)].se;
		for (i64 i=1; i<=t[d]; i++) {
			if (!inQueue[x+AL*i+offset][y+BL*i+offset][d+1][o+AL][o+BL] && i == t[d]) {
				inQueue[x+AL*i+offset][y+BL*i+offset][d+1][o+AL][o+BL] = true;
				Q.push(mp(mp(x+AL*i+offset, y+BL*i+offset), mp(d+1, mp(o+AL, o+BL))));
			}
			if (!inQueue[x+AR*i+offset][y+BR*i+offset][d+1][o+AR][o+BR] && i == t[d]) {
				inQueue[x+AR*i+offset][y+BR*i+offset][d+1][o+AR][o+BR] = true;
				Q.push(mp(mp(x+AR*i+offset, y+BR*i+offset), mp(d+1, mp(o+AR, o+BR))));
			}
			if (!vis[x+AL*i+offset][y+BL*i+offset][d+1][o+AL][o+BL]) {
				vis[x+AL*i+offset][y+BL*i+offset][d+1][o+AL][o+BL] = true;
			}
			if (!vis[x+AR*i+offset][y+BR*i+offset][d+1][o+AR][o+BR]) {
				vis[x+AR*i+offset][y+BR*i+offset][d+1][o+AR][o+BR] = true;
			}
		}
	}
	long long ans = 0;
	for (i64 i=0; i<501; i++) {
		for (i64 j=0; j<501; j++) {
			bool flag = false;
			for (i64 x=0; x<31; x++) {
				for (i64 y=0; y<3; y++) {
					for (i64 z=0; z<3; z++) {
						if (vis[i][j][x][y][z]) {
							flag = true; break;
						}
					}
					if (flag) break;
				}
				if (flag) break;
			}
			ans += flag;
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