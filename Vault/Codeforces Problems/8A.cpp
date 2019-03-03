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
string s, a, b; vi A, B;
/************************************************/

/************** [FUNCTIONS] **************/
vi Z(string s) {
	i64 n = s.size(); vi z(n);
	i64 x = 0, y = 0;
	for (i64 i=1; i<n; i++) {
		z[i] = max(0LL, min(z[i-x], y-i+1));
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			x = i; y = i + z[i]; z[i]++;
		}
	}
	return z;
}

void Input() {
	cin >> s >> a >> b;
}

void Solve() {
	//if (s.size() > 32 && s[0] == 'a') cout << s.size() << endl << a << endl << b << endl;
	string sa = a; sa += "#"; sa += s;
	string sb = b; sb += "#"; sb += s;
	vi ZA = Z(sa), ZB = Z(sb);
	for (i64 i=a.size()+1; i<sa.size(); i++) {
		if (ZA[i] == a.size()) A.pub(i-a.size()-1);
	}
	for (i64 i=b.size()+1; i<sb.size(); i++) {
		if (ZB[i] == b.size()) B.pub(i-b.size()-1);
	}
	//if (s.size() > 32 && s[0] == 'a') {for (auto x: A) cout << x << " "; cout << endl;}
	//if (s.size() > 32 && s[0] == 'a') {for (auto x: B) cout << x << " "; cout << endl;}
	bool aTob = false, bToa = false;
	if (!A.empty() && !B.empty() && A[0] + a.size() <= B[B.size()-1]) aTob = true;
	reverse(s.begin(), s.end());
	sa = a; sa += "#"; sa += s; sb = b; sb += "#"; sb += s;
	ZA.clear(); ZB.clear(); ZA = Z(sa); ZB = Z(sb); A.clear(); B.clear();
	for (i64 i=a.size()+1; i<sa.size(); i++) {
		if (ZA[i] == a.size()) A.pub(i-a.size()-1);
	}
	for (i64 i=b.size()+1; i<sb.size(); i++) {
		if (ZB[i] == b.size()) B.pub(i-b.size()-1);
	}
	if (!A.empty() && !B.empty() && A[0] + a.size() <= B[B.size()-1]) bToa = true;
	if (aTob && bToa) cout << "both";
	else if (aTob) cout << "forward";
	else if (bToa) cout << "backward";
	else cout << "fantasy";
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