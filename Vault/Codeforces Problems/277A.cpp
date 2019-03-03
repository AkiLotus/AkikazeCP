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
i64 n, m, ans = -1; vector<vi> mat, lang;
vb vis; bool allempty = true;

/** -----EXTENSIVE FUNCTIONS----- **/
void DFS(i64 z) {
	vis[z] = true;
	for (i64 i=0; i<n; i++) {
		if (mat[z][i] && ! vis[i]) DFS(i);
	}
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m; mat.resize(n, vi(n, 0));
	lang.resize(m, vi(0)); vis.resize(n, false);
	for (i64 i=0; i<n; i++) {
		i64 z; cin >> z;
		while (z--) {
			i64 l; cin >> l; l--;
			lang[l].pub(i); allempty = false;
		}
	}
}

void ProSolve() {
	for (i64 i=0; i<m; i++) {
		for (i64 x=0; x<lang[i].size(); x++) {
			for (i64 y=x+1; y<lang[i].size(); y++) {
				mat[lang[i][x]][lang[i][y]] = 1;
				mat[lang[i][y]][lang[i][x]] = 1;
			}
		}
	}
	if (allempty) {cout << n; return;}
	for (i64 i=0; i<n; i++) {
		if (!vis[i]) {
			ans++; DFS(i);
		}
	}
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