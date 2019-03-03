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
#define i64 int
#define i16 short
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
typedef pair<pii, pii> ppp;
typedef pair<ld, ld> pdd;
typedef pair<pair<i16, i16>, i16> pps;
const pdd Null = mp(-1e18, 1e18);
i64 n; ppp Segments[505];
pdd Intersect[505][505]; bool vis[8080][8080];
priority_queue< pair< ld, pps > , vector< pair< ld, pps > > , greater< pair< ld, pps > > > DoubleArea, Tmp;
/************************************************/

/************** [FUNCTIONS] **************/
void Process(ppp x, ppp y, i64 i, i64 j) {
	// Assume that i < j
	pii vecX = mp(x.se.fi - x.fi.fi, x.se.se - x.fi.se);
	pii vecY = mp(y.se.fi - y.fi.fi, y.se.se - y.fi.se);
	i64 ax = vecX.se, bx = -vecX.fi, cx = ax * x.fi.fi + bx * x.fi.se;
	i64 ay = vecY.se, by = -vecY.fi, cy = ay * y.fi.fi + by * y.fi.se;
	
	i64 D = ax * by - ay * bx;
	i64 Dx = cx * by - cy * bx;
	i64 Dy = ax * cy - ay * cx;
	
	if (D == 0) return;
	
	ld A = (ld)Dx / D, B = (ld)Dy / D;
	
	Intersect[i][j] = mp(A, B);
}

void TriangleProcess(i64 i, i64 j, i64 k) {
	// Assume that i < j < k
	if (Intersect[i][j] == Null) return;
	if (Intersect[i][k] == Null) return;
	if (Intersect[j][k] == Null) return;
	
	pdd A = Intersect[i][j], B = Intersect[j][k], C = Intersect[i][k];
	i64 I = 0, J = 0, K = 0;
	
	pii vecI = mp(Segments[i].se.fi - Segments[i].fi.fi, Segments[i].se.se - Segments[i].fi.se);
	pii vecJ = mp(Segments[j].se.fi - Segments[j].fi.fi, Segments[j].se.se - Segments[j].fi.se);
	pii vecK = mp(Segments[k].se.fi - Segments[k].fi.fi, Segments[k].se.se - Segments[k].fi.se);
	i64 ai = vecI.se, bi = -vecI.fi, ci = ai * Segments[i].fi.fi + bi * Segments[i].fi.se;
	i64 aj = vecJ.se, bj = -vecJ.fi, cj = aj * Segments[j].fi.fi + bj * Segments[j].fi.se;
	i64 ak = vecK.se, bk = -vecK.fi, ck = ak * Segments[k].fi.fi + bk * Segments[k].fi.se;
	
	if (ai * B.fi + bi * B.se + ci < 0) I = 1;
	if (aj * C.fi + bj * C.se + cj < 0) J = 1;
	if (ak * A.fi + bk * A.se + ck < 0) K = 1;
	
	ld dArea = fabs(A.fi * (B.se - C.se) + B.fi * (C.se - A.se) * C.fi * (A.se - B.se));
	Tmp.push(mp(dArea, mp(mp((i16)i*8+I, (i16)j*8+J), (i16)k*8+K)));
}

void Input() {
	
}

void Solve() {
	cin >> n;
	while (n > 0) {
		i64 ans = 0;
		for (i64 i=0; i<505; i++) {
			for (i64 j=0; j<505; j++) {
				Intersect[i][j] = Null;
			}
		}
		for (i64 i=0; i<8080; i++) {
			for (i64 j=0; j<8080; j++) {
				vis[i][j] = false;
			}
		}
		for (i64 i=0; i<n; i++) {
			cin >> Segments[i].fi.fi >> Segments[i].fi.se;
			cin >> Segments[i].se.fi >> Segments[i].se.se;
		}
		
		for (i64 i=0; i<n; i++) {
			for (i64 j=i+1; j<n; j++) {
				Process(Segments[i], Segments[j], i, j);
			}
		}
		
		for (i64 i=0; i<n; i++) {
			for (i64 j=i+1; j<n; j++) {
				for (i64 k=j+1; k<n; k++) {
					TriangleProcess(i, j, k);
					while (!Tmp.empty()) {
						pair< ld, pps> z = Tmp.top(); Tmp.pop();
						i64 I = z.se.fi.fi, J = z.se.fi.se, K = z.se.se;
						if (vis[I][J]) continue;
						vis[I][J] = true; DoubleArea.push(z);
					}
					vis[i*8+0][j*8+0] = false; vis[i*8+0][j*8+1] = false;
					vis[i*8+1][j*8+0] = false; vis[i*8+1][j*8+1] = false;
				}
			}
		}
		
		//for (auto x: Intersect) cout << x << endl;
		
		while (!DoubleArea.empty()) {
			pair< ld, pps> z = DoubleArea.top(); DoubleArea.pop();
			i64 i = z.se.fi.fi, j = z.se.fi.se, k = z.se.se;
			if (vis[i][j] || vis[j][k] || vis[i][k]) continue;
			vis[i][j] = true; vis[j][k] = true; vis[i][k] = true; ans++;
		}
		
		cout << ans << endl;
		
		cin >> n;
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