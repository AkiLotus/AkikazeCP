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
//vi HashMod(keymod, keymod + sizeof(keymod) / sizeof(i64));
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
//#undef MultiTest // Switch this off if submitting multi-test problems.

void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
i64 P, Q, s, t;
/************************************************/

/************** [FUNCTIONS] **************/
i64 modPow(i64 a, i64 b, i64 m) {
	if (b == 0) return (1 % m);
	if (b == 1) return (a % m);
	i64 tmp = modPow(a, b/2, m);
	if (b % 2 == 0) return ((tmp * tmp) % m);
	return ((((tmp * tmp) % m) * (a % m)) % m);
}

void Input() {
	cin >> P >> Q >> s >> t;
	s--; t--;
}

void Solve() {
	if (s == 0) s = 1;
	if (Q <= 100) {
		vi Digit; P %= Q; vi vis(Q, -1);
		do {
			//tracker1(P);
			vis[P] = Digit.size();
			Digit.pub((P * 10) / Q);
			P = (P * 10) % Q;
			//cout << "P = " << P << endl;
		} while (vis[P] == -1);
		i64 Init = vis[P]; s -= Init; t -= Init;
		i64 ans = 0;
		if (t < 0) {
			s += Init; t += Init;
			for (i64 i=s; i<=t; i++) ans += Digit[i];
			cout << (ans % Q) << endl; return;
		}
		if (s < 0) {
			for (i64 i=s+Init; i<Init; i++) ans += Digit[i];
			s = 0;
		}
		//tracker2(Init, Digit);
		pii st = mp(s / (Digit.size()-Init), s % (Digit.size()-Init));
		pii en = mp(t / (Digit.size()-Init), t % (Digit.size()-Init));
		//tracker2(st, en);
		i64 tmp = 0; for (i64 i=Init; i<Digit.size(); i++) tmp += Digit[i];
		//cout << "ans = " << ans << endl;
		ans += tmp * (max(en.fi-st.fi-1, 0LL));
		//cout << "ans = " << ans << endl;
		if (st.fi != en.fi) {
			for (i64 i=st.se+Init; i<Digit.size(); i++) ans += Digit[i];
			//cout << "ans = " << ans << endl;
			for (i64 i=Init; i<=en.se+Init; i++) ans += Digit[i];
			//cout << "ans = " << ans << endl;
		}
		else {
			for (i64 i=st.se+Init; i<=en.se+Init; i++) ans += Digit[i];
			//cout << "ans = " << ans << endl;
		}
		cout << (ans % Q) << endl; return;
	}
	if (t <= 100) {
		P %= Q; vi Digit; i64 ans = 0;
		while (Digit.size() < 128) {
			P *= 10;
			Digit.pub(P / Q);
			P %= Q;
		}
		for (i64 i=s; i<=t; i++) ans += Digit[i];
		cout << (ans % Q) << endl; return;
	}
	cout << (((((P % Q) * modPow(10, s, Q)) % Q) * 10) / Q) % Q << endl;
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
	freopen("frac.inp", "r", stdin);
	freopen("frac.out", "w", stdout);
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