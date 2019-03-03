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
typedef pair<pii, pii> ppp;
i64 N, M, S, T, Speed, arg1, arg2; vector<ppp> cmd;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> N >> M >> S >> T >> Speed;
	for (i64 i=0; i<N; i++) {
		cin >> arg1 >> arg2;
		cmd.pub(mp(mp(arg1, i+1), mp(0LL, arg2)));
	}
	for (i64 i=0; i<M; i++) {
		cin >> arg1 >> arg2;
		cmd.pub(mp(mp(arg1, i+1), mp(1LL, arg2)));
	}
	cmd.pub(mp(mp(T, M+1), mp(1LL, 0LL)));
}

void Solve() {
	sort(cmd.begin(), cmd.end());
	set<pip> Files; i64 Last = 0; vi Transferred;
	for (auto Q: cmd) {
		i64 Time = Q.fi.fi, ID = Q.fi.se;
		i64 Type = Q.se.fi, Arg = Q.se.se;
		//cout << "Info: " << Time << ", " << ID << ", " << Type << ", " << Arg << ", " << S << endl;
		while (!Files.empty() && Last < Time) {
			i64 FileID = Files.begin()->se.se, Size = Files.begin()->se.fi;
			//tracker3(FileID, Size, Last);
			//cout << "FileSet: "; for (auto it=Files.begin(); it!=Files.end(); it++) cout << (*it) << " "; cout << endl;
			if (Size > S) {Files.erase(Files.begin()); continue;}
			i64 FlushTime = Size / Speed + (Size % Speed > 0);
			//cout << "FlushTime = " << FlushTime << endl;
			Files.erase(Files.begin());
			if (Last + FlushTime <= Time) {Last += FlushTime; S -= Size; Transferred.pub(FileID); continue;}
			i64 UsedTime = Time - Last; Size -= Speed * UsedTime; S -= Speed * UsedTime;
			Files.insert(mp(0LL, mp(Size, FileID))); Last = Time;
		}
		if (Last < Time) Last = Time; //cout << endl;
		if (Type == 1) {Speed = Arg; continue;}
		Files.insert(mp(1LL, mp(Arg, ID)));
	}
	cout << Transferred.size() << endl;
	for (auto x: Transferred) cout << x << " ";
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