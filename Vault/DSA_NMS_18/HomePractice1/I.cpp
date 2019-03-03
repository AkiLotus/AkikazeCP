/**
	Template by Akikaze (秋風) - formerly proptit_4t41.
	Code written by a random fan of momocashew and Chiho.
**/

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
i64 n, ans = LINF; vector<vi> C; vi permu, mn; vb vis;

/** -----GLOBAL VARIABLES----- **/


/** -----EXTENSIVE FUNCTIONS----- **/
void Try_(i64 pos, i64 num, i64 last, i64 sum) {
	if (pos == n-2) {
		sum += C[num][0];
		ans = min(ans, sum);
		return;
	}
	if (sum >= ans) return;
	i64 tmp = 0;
	for (i64 i=0; i<n; i++) {
		if (vis[i]) continue;
		tmp += mn[i];
	}
	if (sum + tmp >= ans) return;
	vis[num] = true; permu[pos] = num;
	for (i64 i=1; i<n; i++) {
		if (vis[i]) continue;
		Try_(pos+1, i, num, sum+C[i][num]);
	}
	vis[num] = false; permu[pos] = -1;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n; C.resize(n, vi(n, 0)); mn.resize(n, LINF);
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<n; j++) {
			cin >> C[i][j];
			if (i != j) mn[i] = min(mn[i], C[i][j]);
		}
	}
}

void ProSolve() {
	permu.resize(n-1, -1); vis.resize(n, false); vis[0] = true;
	for (i64 i=1; i<n; i++) Try_(0, i, 0, C[0][i]);
	if (ans == LINF) cout << "0"; else cout << ans;
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