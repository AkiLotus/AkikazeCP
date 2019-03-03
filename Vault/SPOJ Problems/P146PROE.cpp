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
i64 n, m; vector<vector<char>> board;
vector<vi> onePos;
bool flag = true; i64 ans = LINF;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n >> m; onePos.resize(n, vi(0));
	board.resize(n, vector<char>(m, '0'));
	for (i64 i=0; i<n; i++) {
		i64 cnt = 0;
		for (i64 j=0; j<m; j++) {
			cin >> board[i][j];
			if (board[i][j] == '1') {
				cnt++;
				onePos[i].pub(j);
				onePos[i].pub(j-m);
				onePos[i].pub(j+m);
			}
		}
		sort(onePos[i].begin(), onePos[i].end());
		if (cnt == 0) flag = false;
	}
}

void ProSolve() {
	if (!flag) {cout << "-1"; return;}
	for (i64 j=0; j<m; j++) {
		i64 tmp = 0;
		for (i64 i=0; i<n; i++) {
			if (board[i][j] == '1') continue;
			i64 pos2 = lower_bound(onePos[i].begin(), onePos[i].end(), j) - onePos[i].begin();
			i64 pos1 = pos2 - 1;
			i64 zazz = min(onePos[i][pos2] - j, j - onePos[i][pos1]);
			tmp += zazz;
		}
		ans = min(ans, tmp);
	}
	cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}