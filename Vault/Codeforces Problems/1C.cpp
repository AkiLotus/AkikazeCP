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
const long double PI = 3.141592653589793116, EPS = 1e-6, GOLD = ((1+sqrt(5))/2);
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
ld xa, ya, xb, yb, xc, yc, xo, yo, R;
i64 edge = 0;
/************************************************/

/************** [FUNCTIONS] **************/
void calculateCenter() {
	ld a1, b1, c1, a2, b2, c2;
	a1 = (xb - xa); b1 = (yb - ya);
	a2 = (xb - xc); b2 = (yb - yc);
	c1 = a1 * (xa + xb) / 2.0L + b1 * (ya + yb) / 2.0L;
	c2 = a2 * (xb + xc) / 2.0L + b2 * (yb + yc) / 2.0L;
	
	ld D = a1 * b2 - a2 * b1;
	ld Dx = c1 * b2 - c2 * b1;
	ld Dy = a1 * c2 - a2 * c1;
	
	xo = Dx / D; yo = Dy / D;
}

ld findAngle(ld x1, ld y1, ld x2, ld y2) {
	pair<ld, ld> vec1 = mp(x1 - xo, y1 - yo);
	pair<ld, ld> vec2 = mp(x2 - xo, y2 - yo);
	ld dotProduct = vec1.fi * vec2.fi + vec1.se * vec2.se;
	if (abs(dotProduct / R / R) - 1 <= EPS && abs(dotProduct / R / R) - 1 >= -EPS) return PI;
	return acos(dotProduct / R / R);
}

bool valid(i64 n, vector<ld> Angle) {
	vector<ld> avail(1, 0.0L); ld deg = 0;
	for (i64 i=0; i<n; i++) {
		deg += (PI * 2.0L) / n;
		avail.pub(deg);
	}
	bool ok1 = false, ok2 = false;
	for (auto x: avail) {
		if (x - Angle[0] <= EPS && x - Angle[0] >= -EPS) {
			ok1 = true; break;
		}
	}
	for (auto x: avail) {
		if (x - Angle[1] <= EPS && x - Angle[1] >= -EPS) {
			ok2 = true; break;
		}
	}
	return (ok1 && ok2);
}

void Input() {
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
}

void Solve() {
	cout << fixed << setprecision(12); calculateCenter();
	R = sqrt((xo - xa) * (xo - xa) + (yo - ya) * (yo - ya));
	vector<ld> Angle;
	Angle.pub(findAngle(xa, ya, xb, yb));
	Angle.pub(findAngle(xa, ya, xc, yc));
	Angle.pub(findAngle(xb, yb, xc, yc));
	sort(Angle.begin(), Angle.end());
	for (i64 i=3; i<=100; i++) {
		if (valid(i, Angle)) {edge = i; break;}
	}
	cout << R * R * sin(2.0L * PI / edge) / 2.0L * edge;
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