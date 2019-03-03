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
int R, C, ans = INF;
char Map[64][64];
vector<vector<int>> levels(64, vector<int>(64, 0));
vector<vector<int>> flood(64, vector<int>(64, INF));
vector<vector<bool>> visited(64, vector<bool>(64, false));
vector<vector<bool>> flooded(64, vector<bool>(64, false));
queue<pii> water;
queue<pii> painter;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> R >> C;
	for (int i=1; i<=R; i++) {
		for (int j=1; j<=C; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == '*') {
				water.push(mp(i,j)); flood[i][j] = 0;
			}
			if (Map[i][j] == 'S') {
				painter.push(mp(i,j)); visited[i][j] = true;
			}
		}
	}
}

void ProSolve() {
	while (!water.empty()) {
		pii z = water.front(); water.pop();
		//tracker2(z.fi, z.se);
		int level = flood[z.fi][z.se];
		if (z.fi-1 > 0 && !flooded[z.fi-1][z.se] && Map[z.fi-1][z.se] != 'D' && Map[z.fi-1][z.se] != 'X' && flood[z.fi-1][z.se] > level) {
			flood[z.fi-1][z.se] = level + 1;
			water.push(mp(z.fi-1, z.se)); flooded[z.fi-1][z.se] = true;
		}
		if (z.fi+1 <= R && !flooded[z.fi+1][z.se] && Map[z.fi+1][z.se] != 'D' && Map[z.fi+1][z.se] != 'X' && flood[z.fi+1][z.se] > level) {
			flood[z.fi+1][z.se] = level + 1;
			water.push(mp(z.fi+1, z.se)); flooded[z.fi+1][z.se] = true;
		}
		if (z.se-1 > 0 && !flooded[z.fi][z.se-1] && Map[z.fi][z.se-1] != 'D' && Map[z.fi][z.se-1] != 'X' && flood[z.fi][z.se-1] > level) {
			flood[z.fi][z.se-1] = level + 1;
			water.push(mp(z.fi, z.se-1)); flooded[z.fi][z.se-1] = true;
		}
		if (z.se+1 <= C && !flooded[z.fi][z.se+1] && Map[z.fi][z.se+1] != 'D' && Map[z.fi][z.se+1] != 'X' && flood[z.fi][z.se+1] > level) {
			flood[z.fi][z.se+1] = level + 1;
			water.push(mp(z.fi, z.se+1)); flooded[z.fi][z.se+1] = true;
		}
	}
	//cout << "-------\n";
	while (!painter.empty() && ans == INF) {
		pii z = painter.front(); painter.pop();
		int level = levels[z.fi][z.se];
		//tracker3(z.fi,z.se,level);
		if (Map[z.fi][z.se] == 'D') {
			ans = level; break;
		}
		if (z.fi-1 > 0 && Map[z.fi-1][z.se] != 'X' && !visited[z.fi-1][z.se] && flood[z.fi-1][z.se] > level+1) {
			levels[z.fi-1][z.se] = level + 1;
			painter.push(mp(z.fi-1, z.se)); visited[z.fi-1][z.se] = true;
		}
		if (z.fi+1 <= R && Map[z.fi+1][z.se] != 'X' && !visited[z.fi+1][z.se] && flood[z.fi+1][z.se] > level+1) {
			levels[z.fi+1][z.se] = level + 1;
			painter.push(mp(z.fi+1, z.se)); visited[z.fi+1][z.se] = true;
		}
		if (z.se-1 > 0 && Map[z.fi][z.se-1] != 'X' && !visited[z.fi][z.se-1] && flood[z.fi][z.se-1] > level+1) {
			levels[z.fi][z.se-1] = level + 1;
			painter.push(mp(z.fi, z.se-1)); visited[z.fi][z.se-1] = true;
		}
		if (z.se+1 <= C && Map[z.fi][z.se+1] != 'X' && !visited[z.fi][z.se+1] && flood[z.fi][z.se+1] > level+1) {
			levels[z.fi][z.se+1] = level + 1;
			painter.push(mp(z.fi, z.se+1)); visited[z.fi][z.se+1] = true;
		}
	}
	if (ans != INF) cout << ans;
	else cout << "KAKTUS";
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
