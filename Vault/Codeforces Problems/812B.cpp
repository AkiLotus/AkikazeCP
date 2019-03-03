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
i64 n, m, light = 0, ans = LINF;
vector<vi> build; vi Left, Right, cnt;

/** -----EXTENSIVE FUNCTIONS----- **/
void recurse(i64 lvl, i64 pos, i64 rem, i64 tim) {
	//tracker3(lvl, pos, tim);
	if (rem == 0) {
		ans = min(ans, tim); return;
	}
	if (Left[lvl] != -1) {
		if (pos == 0) {
			if (lvl != 0 && rem != cnt[lvl]) {
				recurse(lvl-1, 0, rem-cnt[lvl], tim+2*Right[lvl]+1);
				recurse(lvl-1, m-1, rem-cnt[lvl], tim+m+1+1);
			}
			else ans = min(ans, tim+Right[lvl]);
		}
		else {
			if (lvl != 0 && rem != cnt[lvl]) {
				recurse(lvl-1, 0, rem-cnt[lvl], tim+m+1+1);
				recurse(lvl-1, m-1, rem-cnt[lvl], tim+2*(m+1-Left[lvl])+1);
			}
			else ans = min(ans, tim+(m+1-Left[lvl]));
		}
	}
	else if (lvl != 0) {
		if (pos == 0) {
			recurse(lvl-1, 0, rem, tim+1);
			recurse(lvl-1, m-1, rem, tim+m+1+1);
		}
		else {
			recurse(lvl-1, m-1, rem, tim+1);
			recurse(lvl-1, 0, rem, tim+m+1+1);
		}
	}
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n >> m; Left.resize(n, -1); Right = Left;
	cnt.resize(n, 0);
	build.resize(n, vi(m+2));
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m+2; j++) {
			char c; cin >> c;
			build[i][j] = int(c) - 48;
			light += build[i][j];
			cnt[i] += build[i][j];
			if (build[i][j] == 1) {
				if (Left[i] == -1) Left[i] = j;
				Right[i] = j;
			}
		}
	}
}

void ProSolve() {
	recurse(n-1, 0, light, 0);
	cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}