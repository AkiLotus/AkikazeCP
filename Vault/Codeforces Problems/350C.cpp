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
i64 n, x, y; vector<pii> UR, DR, UL, DL;
/************************************************/

/************** [FUNCTIONS] **************/
string toStr(i64 z) {
	if (z == 0) return "0";
	string res = "";
	while (z) {
		res.insert(0, 1, char(48+z%10));
		z /= 10;
	}
	return res;
}

void Input() {
	cin >> n;
	while (n--) {
		cin >> x >> y;
		if (x >= 0 && y >= 0) UR.pub(mp(abs(x), abs(y)));
		if (x >= 0 && y < 0) DR.pub(mp(abs(x), abs(y)));
		if (x < 0 && y >= 0) UL.pub(mp(abs(x), abs(y)));
		if (x < 0 && y < 0) DL.pub(mp(abs(x), abs(y)));
	}
}

void Solve() {
	sort(UR.begin(), UR.end()); sort(DR.begin(), DR.end());
	sort(UL.begin(), UL.end()); sort(DL.begin(), DL.end());
	vector<string> Commands;
	for (auto x: UR) {
		if (x.fi == 0) {
			string cmd1 = "1 ", cmd2 = "1 ";
			cmd1 += toStr(x.se); cmd2 += toStr(x.se);
			cmd1 += " U"; cmd2 += " D";
			Commands.pub(cmd1); Commands.pub("2");
			Commands.pub(cmd2); Commands.pub("3");
		}
		else if (x.se == 0) {
			string cmd1 = "1 ", cmd2 = "1 ";
			cmd1 += toStr(x.fi); cmd2 += toStr(x.fi);
			cmd1 += " R"; cmd2 += " L";
			Commands.pub(cmd1); Commands.pub("2");
			Commands.pub(cmd2); Commands.pub("3");
		}
		else {
			string cmd1a = "1 ", cmd2a = "1 ";
			cmd1a += toStr(x.se); cmd2a += toStr(x.se);
			cmd1a += " U"; cmd2a += " D";
			string cmd1b = "1 ", cmd2b = "1 ";
			cmd1b += toStr(x.fi); cmd2b += toStr(x.fi);
			cmd1b += " R"; cmd2b += " L";
			Commands.pub(cmd1a); Commands.pub(cmd1b); Commands.pub("2");
			Commands.pub(cmd2a); Commands.pub(cmd2b); Commands.pub("3");
		}
	}
	for (auto x: DR) {
		if (x.fi == 0) {
			string cmd1 = "1 ", cmd2 = "1 ";
			cmd1 += toStr(x.se); cmd2 += toStr(x.se);
			cmd1 += " D"; cmd2 += " U";
			Commands.pub(cmd1); Commands.pub("2");
			Commands.pub(cmd2); Commands.pub("3");
		}
		else if (x.se == 0) {
			string cmd1 = "1 ", cmd2 = "1 ";
			cmd1 += toStr(x.fi); cmd2 += toStr(x.fi);
			cmd1 += " R"; cmd2 += " L";
			Commands.pub(cmd1); Commands.pub("2");
			Commands.pub(cmd2); Commands.pub("3");
		}
		else {
			string cmd1a = "1 ", cmd2a = "1 ";
			cmd1a += toStr(x.se); cmd2a += toStr(x.se);
			cmd1a += " D"; cmd2a += " U";
			string cmd1b = "1 ", cmd2b = "1 ";
			cmd1b += toStr(x.fi); cmd2b += toStr(x.fi);
			cmd1b += " R"; cmd2b += " L";
			Commands.pub(cmd1a); Commands.pub(cmd1b); Commands.pub("2");
			Commands.pub(cmd2a); Commands.pub(cmd2b); Commands.pub("3");
		}
	}
	for (auto x: UL) {
		if (x.fi == 0) {
			string cmd1 = "1 ", cmd2 = "1 ";
			cmd1 += toStr(x.se); cmd2 += toStr(x.se);
			cmd1 += " U"; cmd2 += " D";
			Commands.pub(cmd1); Commands.pub("2");
			Commands.pub(cmd2); Commands.pub("3");
		}
		else if (x.se == 0) {
			string cmd1 = "1 ", cmd2 = "1 ";
			cmd1 += toStr(x.fi); cmd2 += toStr(x.fi);
			cmd1 += " L"; cmd2 += " R";
			Commands.pub(cmd1); Commands.pub("2");
			Commands.pub(cmd2); Commands.pub("3");
		}
		else {
			string cmd1a = "1 ", cmd2a = "1 ";
			cmd1a += toStr(x.se); cmd2a += toStr(x.se);
			cmd1a += " U"; cmd2a += " D";
			string cmd1b = "1 ", cmd2b = "1 ";
			cmd1b += toStr(x.fi); cmd2b += toStr(x.fi);
			cmd1b += " L"; cmd2b += " R";
			Commands.pub(cmd1a); Commands.pub(cmd1b); Commands.pub("2");
			Commands.pub(cmd2a); Commands.pub(cmd2b); Commands.pub("3");
		}
	}
	for (auto x: DL) {
		if (x.fi == 0) {
			string cmd1 = "1 ", cmd2 = "1 ";
			cmd1 += toStr(x.se); cmd2 += toStr(x.se);
			cmd1 += " D"; cmd2 += " U";
			Commands.pub(cmd1); Commands.pub("2");
			Commands.pub(cmd2); Commands.pub("3");
		}
		else if (x.se == 0) {
			string cmd1 = "1 ", cmd2 = "1 ";
			cmd1 += toStr(x.fi); cmd2 += toStr(x.fi);
			cmd1 += " L"; cmd2 += " R";
			Commands.pub(cmd1); Commands.pub("2");
			Commands.pub(cmd2); Commands.pub("3");
		}
		else {
			string cmd1a = "1 ", cmd2a = "1 ";
			cmd1a += toStr(x.se); cmd2a += toStr(x.se);
			cmd1a += " D"; cmd2a += " U";
			string cmd1b = "1 ", cmd2b = "1 ";
			cmd1b += toStr(x.fi); cmd2b += toStr(x.fi);
			cmd1b += " L"; cmd2b += " R";
			Commands.pub(cmd1a); Commands.pub(cmd1b); Commands.pub("2");
			Commands.pub(cmd2a); Commands.pub(cmd2b); Commands.pub("3");
		}
	}
	cout << Commands.size() << endl;
	for (auto x: Commands) cout << x << endl;
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