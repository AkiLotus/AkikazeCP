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
typedef pair<pii, pii> ppp;
i64 N, M, I, F, O; vector<vector<ppi>> Stages;
vector<ppp> Shows; i64 MaxTime = 0; map<i64, i64> Map;
/************************************************/

/************** [FUNCTIONS] **************/
void Discretization() {
	vi A(1, 0); Map[0]++;
	for (i64 i=0; i<N; i++) {
		for (i64 j=0; j<Stages[i].size(); j++) {
			ppi x = Stages[i][j];
			i64 I = x.fi.fi, F = x.fi.se, O = x.se;
			if (!Map[I]) A.pub(I); Map[I]++;
			if (!Map[F]) A.pub(F); Map[F]++;
		}
	}
	MaxTime = A.size(); Map.clear(); sort(A.begin(), A.end());
	for (i64 i=0; i<MaxTime; i++) Map[A[i]] = i;
	for (i64 i=0; i<N; i++) {
		for (i64 j=0; j<Stages[i].size(); j++) {
			ppi x = Stages[i][j];
			i64 I = x.fi.fi, F = x.fi.se, O = x.se;
			I = Map[I]; F = Map[F];
			Stages[i][j] = mp(mp(I, F), O);
			Shows.pub(mp(mp(I, F), mp(O, i)));
		}
	}
}

void Input() {
	cin >> N; Stages.rsz(N);
	for (i64 i=0; i<N; i++) {
		cin >> M; Stages[i].rsz(M);
		for (i64 j=0; j<M; j++) {
			cin >> I >> F >> O;
			Stages[i][j] = mp(mp(I, F), O);
		}
	}
}

void Solve() {
	Discretization();
	vector<vi> dp((1LL << N), vi(MaxTime, -LINF)); dp[0][0] = 0;
	for (i64 i=0; i<(1LL << N); i++) {
		for (i64 j=0; j<MaxTime; j++) {
			if (dp[i][j] == -LINF) continue;
			if (j < MaxTime-1) dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
			for (auto x: Shows) {
				i64 I = x.fi.fi, F = x.fi.se;
				i64 O = x.se.fi, id = x.se.se;
				if (I < j) continue;
				dp[i | (1LL << id)][F] = max(dp[i | (1LL << id)][F], dp[i][j] + O);
			}
		}
	}
	if (dp[(1LL << N)-1][MaxTime-1] == -LINF) cout << "-1";
	else cout << dp[(1LL << N)-1][MaxTime-1];
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