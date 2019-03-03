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
i64 n, m, k;
queue<pii> Q;
vector<vector<char>> board;
vector<vector<bool>> visited;
vector<vector<bool>> visited2;
vector<vector<bool>> passable;
vector<vector<i64>> MartianDP;
vector<vector<i64>> EPFLDP;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> n >> m >> k;
	board.resize(n, vector<char>(m, '.'));
	passable.resize(n, vector<bool>(m, false));
	MartianDP.resize(n, vector<i64>(m, LINF));
	EPFLDP.resize(n, vector<i64>(m, LINF));
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) cin >> board[i][j];
	}
	while (k--) {
		i64 r, c; cin >> r >> c;
		passable[r][c] = true;
	}
	MartianDP[0][0] = 0; EPFLDP[0][0] = 0;
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	visited.resize(n, vector<bool>(m, false));
	Q.push(mp(0LL, 0LL)); visited[0][0] = true;
	while (!Q.empty()) {
		pii a = Q.front(); Q.pop();
		if (a.fi-1 >= 0 && !visited[a.fi-1][a.se] && board[a.fi-1][a.se] == '.') {
			MartianDP[a.fi-1][a.se] = min(MartianDP[a.fi][a.se]+1, MartianDP[a.fi-1][a.se]);
			visited[a.fi-1][a.se] = true; Q.push(mp(a.fi-1, a.se));
		}
		if (a.fi+1 < n && !visited[a.fi+1][a.se] && board[a.fi+1][a.se] == '.') {
			MartianDP[a.fi+1][a.se] = min(MartianDP[a.fi][a.se]+1, MartianDP[a.fi+1][a.se]);
			visited[a.fi+1][a.se] = true; Q.push(mp(a.fi+1, a.se));
		}
		if (a.se-1 >= 0 && !visited[a.fi][a.se-1] && board[a.fi][a.se-1] == '.') {
			MartianDP[a.fi][a.se-1] = min(MartianDP[a.fi][a.se]+1, MartianDP[a.fi][a.se-1]);
			visited[a.fi][a.se-1] = true; Q.push(mp(a.fi, a.se-1));
		}
		if (a.se+1 < m && !visited[a.fi][a.se+1] && board[a.fi][a.se+1] == '.') {
			MartianDP[a.fi][a.se+1] = min(MartianDP[a.fi][a.se]+1, MartianDP[a.fi][a.se+1]);
			visited[a.fi][a.se+1] = true; Q.push(mp(a.fi, a.se+1));
		}
	}
	visited2.resize(n, vector<bool>(m, false));
	Q.push(mp(0LL, 0LL)); visited[0][0] = true;
	while (!Q.empty()) {
		pii a = Q.front(); Q.pop();
		if (a.fi-1 >= 0 && !visited2[a.fi-1][a.se] && (board[a.fi-1][a.se] == '.' || passable[a.fi-1][a.se])) {
			EPFLDP[a.fi-1][a.se] = min(EPFLDP[a.fi][a.se]+1, EPFLDP[a.fi-1][a.se]);
			visited2[a.fi-1][a.se] = true; Q.push(mp(a.fi-1, a.se));
		}
		if (a.fi+1 < n && !visited2[a.fi+1][a.se] && (board[a.fi+1][a.se] == '.' || passable[a.fi+1][a.se])) {
			EPFLDP[a.fi+1][a.se] = min(EPFLDP[a.fi][a.se]+1, EPFLDP[a.fi+1][a.se]);
			visited2[a.fi+1][a.se] = true; Q.push(mp(a.fi+1, a.se));
		}
		if (a.se-1 >= 0 && !visited2[a.fi][a.se-1] && (board[a.fi][a.se-1] == '.' || passable[a.fi][a.se-1])) {
			EPFLDP[a.fi][a.se-1] = min(EPFLDP[a.fi][a.se]+1, EPFLDP[a.fi][a.se-1]);
			visited2[a.fi][a.se-1] = true; Q.push(mp(a.fi, a.se-1));
		}
		if (a.se+1 < m && !visited2[a.fi][a.se+1] && (board[a.fi][a.se+1] == '.' || passable[a.fi][a.se+1])) {
			EPFLDP[a.fi][a.se+1] = min(EPFLDP[a.fi][a.se]+1, EPFLDP[a.fi][a.se+1]);
			visited2[a.fi][a.se+1] = true; Q.push(mp(a.fi, a.se+1));
		}
	}
	if (EPFLDP[n-1][m-1] == LINF) cout << "NO";
	else if (MartianDP[n-1][m-1] - EPFLDP[n-1][m-1] > 5) cout << "YES";
	else cout << "NO";
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
