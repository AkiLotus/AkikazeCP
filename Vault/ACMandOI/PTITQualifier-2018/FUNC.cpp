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
i64 k, r, p, q, M; vector<vi> unit(2, vi(2, 0));
/************************************************/

/************** [FUNCTIONS] **************/
i64 modMul(i64 a, i64 b) {
	if (b == 0) return 0;
	if (b == 1) return a;
	i64 tmp = modMul(a, b/2);
	if (b % 2 == 0) return ((tmp + tmp) % M);
	return (((tmp + tmp) % M + a) % M);
}

vector<vi> MatMul(vector<vi> a, vector<vi> b) {
	vector<vi> res(2, vi(2, 0));
	for (i64 k=0; k<2; k++) {
		for (i64 i=0; i<2; i++) {
			for (i64 j=0; j<2; j++) {
				res[i][j] += modMul(a[i][k], b[k][j]);
				res[i][j] %= M;
			}
		}
	}
	return res;
}

vector<vi> MatPow(vector<vi> a, i64 k) {
	if (k == 0) return unit;
	if (k == 1) return a;
	vector<vi> tmp = MatPow(a, k/2);
	if (k % 2 == 0) return MatMul(tmp, tmp);
	return MatMul(MatMul(tmp, tmp), a);
}

void Input() {
	
}

void Solve() {
	while (cin >> k >> r >> p >> q >> M) {
		vector<vi> Mat(2, vi(2, 0)), Base(2, vi(2, 0));
		i64 GCD = __gcd(p, q); p /= GCD; q /= GCD;
		Mat[0][1] = 1; Mat[1][0] = 1; Mat[1][1] = r;
		Base[0][1] = p; Base[1][0] = p; Base[1][1] = q;
		vector<vi> ResultCluster1 = MatMul(Base, MatPow(Mat, k-2));
		vector<vi> ResultCluster2 = MatMul(Base, MatPow(Mat, k-1));
		if (k == 1) cout << p << " " << q << endl;
		else cout << ResultCluster1[1][1] << " " << ResultCluster2[1][1] << endl;
	}
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	ControlIO(argc, argv);
	#ifndef MultiTest
		unit[0][0] = 1; unit[1][1] = 1;
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
	freopen("FUNC.INP", "r", stdin);
	freopen("FUNC.OUT", "w", stdout);
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