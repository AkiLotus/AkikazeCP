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
i64 n;
/************************************************/

/************** [FUNCTIONS] **************/
string ParseStr(vi z) {
	string res = "";
	for (auto x: z) res += char(65 + x);
	return res;
}

void calc(vi A, vi B, i64 x, vi &Res) {
	//tracker3(A, B, x);
	vi Default(x); i64 N = A.size();
	for (i64 i=0; i<x; i++) Default[i] = -1;
	for (i64 i=x; i<N; i++) {
		if ((A[i] + B[i-x]) % 26 != B[i]) {
			Res = Default; return;
		}
	}
	for (i64 i=0; i<min(x, N); i++) {
		Res[i] = B[i] - A[i];
		//tracker2(i, Res[i]);
		while (Res[i] < 0) Res[i] += 26;
	}
}

bool lensort(vector<vi> a, vector<vi> b) {
	return (a[0].size() > b[0].size());
}

void Input() {
	cin >> n;
}

void Solve() {
	while (n > 0) {
		vector<vector<vi>> a(n, vector<vi>(2));
		for (i64 i=0; i<n; i++) {
			string A, B; cin >> A >> B;
			i64 N = A.size(); a[i][0].rsz(N); a[i][1] = a[i][0];
			for (i64 x=0; x<N; x++) {
				a[i][0][x] = A[x] - 'A';
				a[i][1][x] = B[x] - 'A';
			}
		}
		
		sort(a.begin(), a.end(), lensort);
		
		string str = "Impossible";
		
		for (i64 x=1; x<=100; x++) {
			bool flag = true;
			vi Default(x);
			for (i64 i=0; i<x; i++) Default[i] = -1;
			vi Res = Default;
			for (auto z: a) {
				vi A = z[0], B = z[1], Tmp = Default;
				if (A.size() < x) {
					if (Res == Default) {flag = false; break;}
					Tmp = Res;
				}
				calc(A, B, x, Tmp);
				if (Tmp == Default) {flag = false; break;}
				if (Res == Default) Res = Tmp;
				else if (Res != Tmp) {flag = false; break;}
			}
			if (flag) {str = ParseStr(Res); break;}
		}
		
		cout << str << endl;
		
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