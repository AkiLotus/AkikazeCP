/**
	Template by proptit_4t41
	Applied for C++11/C++14
	Add -std=c++14 to your IDE.
**/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define i64 long long
#define u64 unsigned long long
#define ld long double
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define MOD 1000000007LL
#define INF 1e9
#define LINF 1e18
#define EPS 1e-9
#define GOLD ((1+sqrt(5))/2)
#define REcheck cout << "RE here?\n"
#define tracker1(i) cout << "working at " << i << endl;
#define tracker2(i,j) cout << "working at " << i << "-" << j << endl;
#define tracker3(i,j,k) cout << "working at " << i << "-" << j << "-" << k << endl;
const long double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
//int T, cas = 0; // for multi-testcase problems
i64 N, M; vector<vector<char>> board;
vector<vector<bool>> visited;
vector<ppi> ans;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> N >> M; board.resize(N, vector<char>(M, '.'));
	visited.resize(N, vector<bool>(M, false));
	for (i64 i=0; i<N; i++) {
		for (i64 j=0; j<M; j++) cin >> board[i][j];
	}
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	for (i64 i=0; i<N; i++) {
		for (i64 j=0; j<M; j++) {
			if (!visited[i][j] && board[i][j] == 'x' && (i == 0 || board[i-1][j] == '.') && (j == 0 || board[i][j-1] == '.')) {
				i64 x1 = i, y1 = j, x2 = i, y2 = j;
				while (x1 >= 0 && x1 < N && y1 >= 0 && y1 < M && board[x1][y1] == 'x' &&
						x2 >= 0 && x2 < N && y2 >= 0 && y2 < M && board[x2][y2] == 'x') {
							x1++; y2++;
						}
				for (i64 a=i; a<x1; a++) {
					for (i64 b=j; b<y2; b++) visited[a][b] = true;
				}
				ans.pub(mp(mp(i, j), (x1-i))); continue;
			}
			if (!visited[i][j] && board[i][j] == 'x' && (i == 0 || board[i-1][j] == '.') && (j == M-1 || board[i][j+1] == '.')) {
				i64 x1 = i, y1 = j, x2 = i, y2 = j;
				while (x1 >= 0 && x1 < N && y1 >= 0 && y1 < M && board[x1][y1] == 'x' &&
						x2 >= 0 && x2 < N && y2 >= 0 && y2 < M && board[x2][y2] == 'x') {
							x1++; y2--;
						}
				for (i64 a=i; a<x1; a++) {
					for (i64 b=y2; b<j; b++) visited[a][b] = true;
				}
				ans.pub(mp(mp(i, y2+1), (x1-i))); continue;
			}
			if (!visited[i][j] && board[i][j] == 'x' && (i == N-1 || board[i+1][j] == '.') && (j == 0 || board[i][j-1] == '.')) {
				i64 x1 = i, y1 = j, x2 = i, y2 = j;
				while (x1 >= 0 && x1 < N && y1 >= 0 && y1 < M && board[x1][y1] == 'x' &&
						x2 >= 0 && x2 < N && y2 >= 0 && y2 < M && board[x2][y2] == 'x') {
							x1--; y2++;
						}
				for (i64 a=x1; a<i; a++) {
					for (i64 b=j; b<y2; b++) visited[a][b] = true;
				}
				ans.pub(mp(mp(x1+1, j), (y2-j))); continue;
			}
			if (!visited[i][j] && board[i][j] == 'x' && (i == N-1 || board[i+1][j] == '.') && (j == M-1 || board[i][j+1] == '.')) {
				i64 x1 = i, y1 = j, x2 = i, y2 = j;
				while (x1 >= 0 && x1 < N && y1 >= 0 && y1 < M && board[x1][y1] == 'x' &&
						x2 >= 0 && x2 < N && y2 >= 0 && y2 < M && board[x2][y2] == 'x') {
							x1--; y2--;
						}
				for (i64 a=x1; a<i; a++) {
					for (i64 b=y2; b<j; b++) visited[a][b] = true;
				}
				ans.pub(mp(mp(x1+1, y2+1), (i-x1))); continue;
			}
		}
	}
	if (ans.size() == 1) cout << ans[0].fi.fi+1 << " " << ans[0].fi.se+1 << " " << ans[0].se << endl << ans[0].fi.fi+1 << " " << ans[0].fi.se+1 << " " << ans[0].se;
	else cout << ans[0].fi.fi+1 << " " << ans[0].fi.se+1 << " " << ans[0].se << endl << ans[1].fi.fi+1 << " " << ans[1].fi.se+1 << " " << ans[1].se;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
