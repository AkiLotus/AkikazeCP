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
vs a(3), b(3); i64 First = 0, Second = 0; map<string, int> Map, Map1, Map2;
/************************************************/

/************** [FUNCTIONS] **************/
void count1(vs A) {
	for (auto x: A) {
		if (x == "XXX") {Map1[x]++; Map[x]++;}
		if (x == "000") {Map1[x]++; Map[x]++;}
	}
}

void count2(vs A) {
	for (auto x: A) {
		if (x == "XXX") {Map2[x]++; Map[x]++;}
		if (x == "000") {Map2[x]++; Map[x]++;}
	}
}

void Input() {
	for (i64 i=0; i<3; i++) {
		cin >> a[i]; b[i] = a[i];
		for (i64 j=0; j<3; j++) {
			First += (a[i][j] == 'X');
			Second += (a[i][j] == '0');
		}
	}
}

void Solve() {
	for (i64 i=0; i<3; i++) {
		for (i64 j=i+1; j<3; j++) {
			swap(b[i][j], b[j][i]);
		}
	}
	if (First - Second > 1 || First - Second < 0) {cout << "illegal"; return;}
	count1(a); count2(b);
	if (a[1][1] != '.' && ((a[0][0] == a[1][1] && a[1][1] == a[2][2]) || (a[0][2] == a[1][1] && a[1][1] == a[2][0]))) {
		if (a[1][1] == 'X') {
			if (First == Second) cout << "illegal";
			else cout << "the first player won";
		}
		else {
			if (First != Second) cout << "illegal";
			else cout << "the second player won"; 
		} return;
	}
	if (Map1.empty() && Map2.empty()) {
		if (First + Second == 9) cout << "draw";
		else if (First == Second) cout << "first";
		else cout << "second"; return;
	}
	if (Map1.size() == 1 && Map2.size() == 1 && Map1.begin()->se == 1 && Map2.begin()->se == 1) {
		if (Map1.begin()->fi != Map2.begin()->fi) cout << "illegal";
		else if (Map1.begin()->fi == "XXX") {
			if (First == Second) cout << "illegal";
			else cout << "the first player won";
		}
		else {
			if (First != Second) cout << "illegal";
			else cout << "the second player won"; 
		} return;
	}
	if (Map.size() == 2 || Map.begin()->se > 1) {cout << "illegal"; return;}
	if (Map.begin()->fi == "XXX")  {
		if (First == Second) cout << "illegal";
		else cout << "the first player won";
	}
	else {
		if (First != Second) cout << "illegal";
		else cout << "the second player won"; 
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