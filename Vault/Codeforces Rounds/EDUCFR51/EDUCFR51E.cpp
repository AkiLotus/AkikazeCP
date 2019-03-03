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
const long long Mod = 998244353LL, INF = 1e9, LINF = 1e18;
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
string a, l, r; i64 na, nl, nr;
vi Tree(4444444, 0), Lazy(4444444, 0);
vi TreeCharL(4444444, 0), TreeCharR(4444444, 0);
/************************************************/

/************** [FUNCTIONS] **************/
void BuildCharL(i64 node, i64 st, i64 en) {
	if (st > en) return;
	if (st == en) {TreeCharL[node] = a[st] - '0'; return;}
	BuildCharL(node*2, st, (st+en)/2);
	BuildCharL(node*2+1, (st+en)/2+1, en);
	TreeCharL[node] = max(TreeCharL[node*2], TreeCharL[node*2+1]);
}

i64 GetCharL(i64 node, i64 st, i64 en, i64 L, i64 R) {
	if (st > en || en < L || R < st) return -LINF;
	if (L <= st && en <= R) return TreeCharL[node];
	i64 p1 = GetCharL(node*2, st, (st+en)/2, L, R);
	i64 p2 = GetCharL(node*2+1, (st+en)/2+1, en, L, R);
	return max(p1, p2);
}

void BuildCharR(i64 node, i64 st, i64 en) {
	if (st > en) return;
	if (st == en) {TreeCharR[node] = a[st] - '0'; return;}
	BuildCharR(node*2, st, (st+en)/2);
	BuildCharR(node*2+1, (st+en)/2+1, en);
	TreeCharR[node] = max(TreeCharR[node*2], TreeCharR[node*2+1]);
}

i64 GetCharR(i64 node, i64 st, i64 en, i64 L, i64 R) {
	if (st > en || en < L || R < st) return -LINF;
	if (L <= st && en <= R) return TreeCharR[node];
	i64 p1 = GetCharR(node*2, st, (st+en)/2, L, R);
	i64 p2 = GetCharR(node*2+1, (st+en)/2+1, en, L, R);
	return max(p1, p2);
}

void Update(i64 node, i64 st, i64 en, i64 L, i64 R, i64 x) {
	if (st > en || en < L || R < st) return;
	if (Lazy[node] > 0) {
		Tree[node] += (R - L + 1) * Lazy[node]; Tree[node] %= Mod;
		if (st != en) {
			Lazy[node*2] += Lazy[node];
			Lazy[node*2] %= Mod;
			Lazy[node*2+1] += Lazy[node];
			Lazy[node*2+1] %= Mod;
		}
		Lazy[node] = 0;
	}
	if (L <= st && en <= R) {
		Tree[node] += (R - L + 1) * x; Tree[node] %= Mod;
		if (st != en) {
			Lazy[node*2] += x; Lazy[node*2] %= Mod;
			Lazy[node*2+1] += x; Lazy[node*2+1] %= Mod;
		}
		return;
	}
	Update(node*2, st, (st+en)/2, L, R, x);
	Update(node*2+1, (st+en)/2+1, en, L, R, x);
	Tree[node] = (Tree[node*2] + Tree[node*2+1]) % Mod;
}

i64 Get(i64 node, i64 st, i64 en, i64 L, i64 R) {
	if (st > en || en < L || R < st) return 0;
	if (Lazy[node] > 0) {
		Tree[node] += (R - L + 1) * Lazy[node]; Tree[node] %= Mod;
		if (st != en) {
			Lazy[node*2] += Lazy[node];
			Lazy[node*2] %= Mod;
			Lazy[node*2+1] += Lazy[node];
			Lazy[node*2+1] %= Mod;
		}
		Lazy[node] = 0;
	}
	if (L <= st && en <= R) return Tree[node];
	i64 p1 = Get(node*2, st, (st+en)/2, L, R);
	i64 p2 = Get(node*2+1, (st+en)/2+1, en, L, R);
	return ((p1 + p2) % Mod);
}

bool equalLengthValidL(i64 i) {
	if (i + nl - 1 < 0 || i + nl - 1 >= na) return false;
	if (nl > 1 && a[i] == '0') return false;
	i64 top = 0, bot = nl - 1, firstDifferent = nl;
	while (top <= bot) {
		i64 mid = (top + bot) / 2;
		if (GetCharL(1, 0, nl-1, 0, mid) > 0) {firstDifferent = mid; bot = mid - 1;}
		else {top = mid + 1;}
	}
	if (firstDifferent == nl) return true;
	return (l[firstDifferent] <= a[i+firstDifferent]);
}

bool equalLengthValidR(i64 i) {
	if (i + nr - 1 < 0 || i + nr - 1 >= na) return false;
	if (nr > 1 && a[i] == '0') return false;
	i64 top = 0, bot = nr - 1, firstDifferent = nr;
	while (top <= bot) {
		i64 mid = (top + bot) / 2;
		tracker3(top, mid, bot);
		if (GetCharR(1, 0, nr-1, 0, mid) > 0) {firstDifferent = mid; bot = mid - 1;}
		else {top = mid + 1;}
	}
	tracker1(firstDifferent);
	if (firstDifferent == nl) return true;
	return (a[i+firstDifferent] <= r[firstDifferent]);
}

void Input() {
	cin >> a >> l >> r; na = a.size();
	nl = l.size(); nr = r.size();
	BuildCharL(1, 0, nl-1); BuildCharR(1, 0, nr-1);
}

void Solve() {
	vi Closest(na, na), Farthest(na, -1);
	for (i64 i=0; i<na; i++) {
		if (equalLengthValidL(i)) Closest[i] = i + nl - 1;
		else if (i + nl - 2 >= 0 && i + nl - 2 < na && (nl == 1 || a[i] != '0')) Closest[i] = i + nl - 2;
		if (equalLengthValidR(i)) {REcheck; Farthest[i] = i + nr - 1;}
		else if (a[i] == '0' && nl == 1 && l == "0") Farthest[i] = i;
		else if (i + nr < na && i + nr >= 0 && a[i] != 0) Farthest[i] = i + nr;
		tracker3(i, Closest[i], Farthest[i]);
	}
	for (i64 i=0; i<na; i++) {
		i64 val = 1;
		if (i > 0) val = Get(1, 0, na-1, i-1, i-1);
		tracker2(i, val);
		i64 L = Closest[i], R = Farthest[i];
		if (L == na || R == -1) continue;
		if (L > R) continue;
		tracker2(L, R); REcheck;
		Update(1, 0, na-1, L, R, val);
	}
	cout << Get(1, 0, na-1, na-1, na-1);
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