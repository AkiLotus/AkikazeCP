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
i64 n, q; vi a, A;
vector<vi> SpTable; vi Log2(200009);
vector<vi> Tree, Lazy;
/************************************************/

/************** [FUNCTIONS] **************/
void BuildSpT() {
	for (i64 i=1; i<200009; i++) {
		for (i64 j=17; j>=0; j--) {
			if ((1LL << j) <= i) {
				Log2[i] = j;
				break;
			}
		}
	}
	for (i64 j=0; j<18; j++) {
		for (i64 i=0; i<n; i++) {
			if (i + (1LL << j) >= n) continue;
			if (j == 0) {
				if (A[i] != 0) SpTable[i].pub(A[i]);
				else SpTable[i].pub(LINF);
			}
			else SpTable[i].pub(min(SpTable[i][j-1], SpTable[i+(1LL<<(j-1))][j-1]));
		}
	}
}

i64 getMin(i64 l, i64 r) {
	i64 x = Log2[r-l+1];
	return min(SpTable[l][x], SpTable[r+1-(1LL<<x)][x]);
}

void Input() {
	cin >> n >> q; a.rsz(n); SpTable.rsz(n);
	for (i64 i=0; i<n; i++) cin >> a[i];
	A = a;
}

void Solve() {
	vector<vi> Pos(q+1); set<i64> Zero;
	for (i64 i=0; i<n; i++) {
		if (a[i]) Pos[a[i]].pub(i);
		else Zero.insert(i);
	}
	if (Zero.size() == n) {
		cout << "YES\n";
		for (i64 i=0; i<n; i++) cout << q << " ";
		return;
	}
	BuildSpT();
	for (i64 x=q; x>0; x--) {
		if (Pos[x].size() < 2) continue;
		//tracker1(x);
		for (i64 i=1; i<Pos[x].size(); i++) {
			i64 l = Pos[x][i-1] + 1, r = Pos[x][i] - 1;
			//tracker2(l, r);
			if (l > r) continue;
			i64 Min = getMin(l, r);
			if (Min < x) {cout << "NO"; return;}
			vi eliminated;
			auto petr1 = Zero.lower_bound(l);
			auto petr2 = Zero.upper_bound(r);
			for (auto it=petr1; it!=petr2; it++) {
				a[*it] = x; eliminated.pub(*it);
			}
			for (auto X: eliminated) Zero.erase(X);
			//cout << a << endl;
		}
		//cout << a << endl;
	}
	//cout << a << endl;
	if (*max_element(a.begin(), a.end()) != q) {
		if (*min_element(A.begin(), A.end()) > 0) {cout << "NO"; return;}
		i64 z = 0; while (A[z] != 0) z++; a[z] = q;
	}
	//cout << a << endl;
	i64 Min = a[0], z = 0;
	while (a[z] == 0) Min = a[++z];
	//cout << a << endl;
	for (i64 i=0; i<z; i++) if (!a[i]) a[i] = Min;
	for (i64 i=z; i<n; i++) {
		if (a[i]) continue;
		a[i] = a[i-1];
	}
	cout << "YES\n";
	for (auto x: a) cout << x << " ";
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