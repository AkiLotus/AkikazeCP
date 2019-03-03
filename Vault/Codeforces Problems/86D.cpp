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
i64 n, t, bucketSize; vi A, Ans; vector<vector<ppi>> Query; vi cnt(1000007, 0);
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> n >> t; A.rsz(n); Ans.rsz(t);
	bucketSize = sqrt(n); Query.rsz((n-1)/bucketSize+1);
	for (i64 i=0; i<n; i++) cin >> A[i];
	for (i64 i=0; i<t; i++) {
		i64 l, r; cin >> l >> r; l--; r--;
		i64 LeftBucket = l / bucketSize, RightBucket = r / bucketSize;
		if (LeftBucket != RightBucket) {Query[LeftBucket].pub(mp(mp(r, l), i)); continue;}
		for (i64 x=l; x<=r; x++) {
			cnt[A[x]]++;
			Ans[i] += (cnt[A[x]] * 2 - 1) * A[x];
		}
		for (i64 x=l; x<=r; x++) cnt[A[x]]--;
	}
}

void Solve() {
	for (i64 x=0; x<=(n-1)/bucketSize; x++) {
		i64 Last = x * bucketSize + bucketSize - 1;
		i64 StretchedSum = 0; sort(Query[x].begin(), Query[x].end());
		for (auto z: Query[x]) {
			i64 L = z.fi.se, R = z.fi.fi, Q = z.se;
			for (i64 i=Last+1; i<=R; i++) {
				cnt[A[i]]++;
				StretchedSum += (cnt[A[i]] * 2 - 1) * A[i];
			}
			Last = R; Ans[Q] = StretchedSum;
			for (i64 i=L; i<(x+1)*bucketSize; i++) {
				cnt[A[i]]++;
				Ans[Q] += (cnt[A[i]] * 2 - 1) * A[i];
			}
			for (i64 i=L; i<(x+1)*bucketSize; i++) cnt[A[i]]--;
		}
		for (i64 i=(x+1)*bucketSize; i<=Last; i++) cnt[A[i]]--;
	}
	for (auto x: Ans) cout << x << endl;
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