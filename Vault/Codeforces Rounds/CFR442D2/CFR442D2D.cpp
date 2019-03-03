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

/** -----IDEAS/ALGORITHMS----- **/


/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
i64 n, m, k, x1, y1, x2, y2, ans = 0;
char board[1024][1024];
vector<vector<bool>> visited(1024, vector<bool>(1024, false));
vector<vector<i64>> sec(1024, vector<i64>(1024, 0));
queue<pii> pending;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n >> m >> k;
	for (i64 i=1; i<=n; i++) {
		for (i64 j=1; j<=m; j++) {
			 cin >> board[i][j];
		}
	}
	cin >> x1 >> y1 >> x2 >> y2;
	visited[x1][y1] = true;
	pending.push(mp(x1,y1));
}

void ProSolve() {
	while (!pending.empty()) {
		pii z = pending.front(); pending.pop();
		if (z.fi == x2 && z.se == y2) {
			cout << sec[x2][y2];
			return;
		}
		for (int i=1; i<=k; i++) {
			if (z.fi-i < 1 || board[z.fi-i][z.se] != '.') break;
			if (!visited[z.fi-i][z.se]) {
				visited[z.fi-i][z.se] = true;
				sec[z.fi-i][z.se] = sec[z.fi][z.se] + 1;
				pending.push(mp(z.fi-i, z.se));
			}
		}
		for (int i=1; i<=k; i++) {
			if (z.fi+i > n || board[z.fi+i][z.se] != '.') break;
			if (!visited[z.fi+i][z.se]) {
				visited[z.fi+i][z.se] = true;
				sec[z.fi+i][z.se] = sec[z.fi][z.se] + 1;
				pending.push(mp(z.fi+i, z.se));
			}
		}
		for (int i=1; i<=k; i++) {
			if (z.se-i < 1 || board[z.fi][z.se-i] != '.') break;
			if (!visited[z.fi][z.se-i]) {
				visited[z.fi][z.se-i] = true;
				sec[z.fi][z.se-i] = sec[z.fi][z.se] + 1;
				pending.push(mp(z.fi, z.se-i));
			}
		}
		for (int i=1; i<=k; i++) {
			if (z.se+i > m || board[z.fi][z.se+i] != '.') break;
			if (!visited[z.fi][z.se+i]) {
				visited[z.fi][z.se+i] = true;
				sec[z.fi][z.se+i] = sec[z.fi][z.se] + 1;
				pending.push(mp(z.fi, z.se+i));
			}
		}
	}
	cout << "-1";
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
