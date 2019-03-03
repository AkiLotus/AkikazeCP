/**
	Template by Akikaze (秋風) - formerly proptit_4t41.
	Code written by a random fan of momocashew and Chiho.
**/

#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define endl '\n'
#define i64 long long
#define ld long double
#define pub push_back
#define mp make_pair
#define fi first
#define se second
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/


/** -----GLOBAL VARIABLES----- **/
i64 N, M, ans = 0; vector<vi> adj(100007, vi(0)); vi lists;
vb vis(100007, false); map<pii, i64> Map; map<i64, i64> Mp;

/** -----EXTENSIVE FUNCTIONS----- **/
void DFS(i64 z) {
	vis[z] = true;
	for (i64 i=0; i<adj[z].size(); i++) {
		if (!vis[adj[z][i]]) DFS(adj[z][i]);
	}
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> N >> M;
	while (M--) {
		i64 A, B; cin >> A >> B; A--; B--;
		if (Mp[A] == 0) {
			lists.pub(A); Mp[A]++;
		}
		if (Mp[B] == 0) {
			lists.pub(B); Mp[B]++;
		}
		if (A != B && Map[mp(A,B)] == 0 && Map[mp(B,A)] == 0) {
			adj[A].pub(B); adj[B].pub(A);
		}
		Map[mp(A,B)]++; Map[mp(B,A)]++;
	}
}

void ProSolve() {
	for (i64 i=0; i<lists.size(); i++) {
		if (!vis[lists[i]]) {
			ans++; DFS(lists[i]);
		}
	}
	ans += (N - lists.size());
	cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main() {
			#ifdef Akikaze
			//freopen("FILE.INP", "r", stdin);
			//freopen("FILE.OUT", "w", stdout);
			#endif
	VarInput();
			#ifdef Akikaze
			auto TIME1 = chrono::steady_clock::now();
			#endif
	ProSolve();
			#ifdef Akikaze
			auto TIME2 = chrono::steady_clock::now();
			auto DIFF = TIME2 - TIME1;
			cout << "\n\nTime elapsed: " << fixed << setprecision(18) << chrono::duration<double>(DIFF).count() << " seconds.";
			#endif
	return 0;
}