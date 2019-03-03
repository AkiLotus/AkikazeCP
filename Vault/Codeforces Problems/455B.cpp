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
struct Node {
	vi Adj;
	i64 Par, Lvl; bool Leaf, Win, Lose;
	Node() {
		Adj.clear(); Adj.rsz(26, -1);
		Par = -1; Lvl = 0;
		Leaf = false;
		Win = false; Lose = false;
	}
	Node(i64 Parent, i64 Level) {
		Adj.clear(); Adj.rsz(26, -1);
		Par = Parent; Lvl = Level;
		Leaf = false;
		Win = false; Lose = false;
	}
};

i64 n, k; vs a; vector<Node> Trie(1);
/************************************************/

/************** [FUNCTIONS] **************/
void GenerateTrie() {
	for (auto s: a) {
		i64 N = s.size(), pos = 0;
		for (i64 i=0; i<N; i++) {
			if (Trie[pos].Adj[s[i]-'a'] != -1) {
				pos = Trie[pos].Adj[s[i]-'a'];
				continue;
			}
			i64 newID = Trie.size();
			Trie[pos].Adj[s[i]-'a'] = newID;
			Trie[pos].Leaf = false;
			Trie.pub(Node(pos, i+1));
			if (i == N-1) Trie[newID].Leaf = true;
			else pos = newID;
		}
	}
}

void DFS_FindingPath(i64 z, i64 lvl) {
	if (Trie[z].Leaf) {
		Trie[z].Lose = true;
		return;
	}
	for (i64 i=0; i<26; i++) {
		if (Trie[z].Adj[i] == -1) continue;
		DFS_FindingPath(Trie[z].Adj[i], lvl+1);
	}
	for (i64 i=0; i<26; i++) {
		i64 t = Trie[z].Adj[i];
		if (t == -1) continue;
		if (!Trie[t].Win) Trie[z].Win = true;
		if (!Trie[t].Lose) Trie[z].Lose = true;
	}
}

void Input() {
	cin >> n >> k; a.rsz(n);
	for (i64 i=0; i<n; i++) cin >> a[i];
}

void Solve() {
	GenerateTrie();
	DFS_FindingPath(0, 0);
	if (!Trie[0].Win) cout << "Second";
	else if (Trie[0].Lose) cout << "First";
	else if (k % 2 == 0) cout << "Second";
	else cout << "First";
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
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