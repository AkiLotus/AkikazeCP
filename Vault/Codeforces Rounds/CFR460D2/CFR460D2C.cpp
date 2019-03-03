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
i64 n, m, k, ans = 0; vector<vector<char>> room;
vector<vi> dp1, dp2;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n >> m >> k;
	room.resize(n, vector<char>(m, '.'));
	dp1.resize(n, vi(m, 0)); dp2.resize(n, vi(m, 0));
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			cin >> room[i][j];
			if (j == 0) {
				if (room[i][j] == '.') dp1[i][j] = 1;
				continue;
			}
			if (room[i][j] == '.') dp1[i][j] = dp1[i][j-1] + 1;
			else dp1[i][j] = 0;
		}
	}
	for (i64 j=0; j<m; j++) {
		for (i64 i=0; i<n; i++) {
			if (i == 0) {
				if (room[i][j] == '.') dp2[i][j] = 1;
				continue;
			}
			if (room[i][j] == '.') dp2[i][j] = dp2[i-1][j] + 1;
			else dp2[i][j] = 0;
		}
	}
}

void ProSolve() {
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			if (dp1[i][j] >= k) ans++;
			if (dp2[i][j] >= k) ans++;
		}
	}
	if (k == 1) cout << ans/2;
	else cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}