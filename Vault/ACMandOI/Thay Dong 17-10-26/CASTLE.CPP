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
int m, n, ccc = 0;
vector<vector<int>> board;
vector<vector<int>> cellNo;
vector<vector<bool>> visited;
vector<vector<bool>> N, E, W, S;
vector<ld> cellArea;
vector<vector<ld>> area;
vector<vector<vector<pii>>> adj;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> m >> n;
	board.resize(m, vector<int>(n, 0));
	area.resize(m, vector<ld>(n, 0));
	visited.resize(m, vector<bool>(n, 0));
	N.resize(m, vector<bool>(n, 0)); E.resize(m, vector<bool>(n, 0)); W.resize(m, vector<bool>(n, 0)); S.resize(m, vector<bool>(n, 0));
	adj.resize(m, vector<vector<pii>>(n, vector<pii>(0)));
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			cin >> board[i][j];
			N[i][j] = true; E[i][j] = true; W[i][j] = true; S[i][j] = true;
			if (board[i][j] % 2 == 0) W[i][j] = false; if (((int)board[i][j] / 2) % 2 == 0) N[i][j] = false;
			if (((int)((int)board[i][j] / 2) / 2) % 2 == 0) E[i][j] = false; if (((int)((int)((int)board[i][j] / 2) / 2) / 2) % 2 == 0) S[i][j] = false;
			//tracker2(i,j);
			//cout << "N = " << N[i][j] << endl;
			//cout << "E = " << E[i][j] << endl;
			//cout << "W = " << W[i][j] << endl;
			//cout << "S = " << S[i][j] << endl;
			ld dim1 = 1.0, dim2 = 1.0;
			if (N[i][j]) dim1 -= 0.1; if (S[i][j]) dim1 -= 0.1; if (W[i][j]) dim2 -= 0.1; if (E[i][j]) dim2 -= 0.1;
			area[i][j] = dim1 * dim2;
			//cout << "Adj list: " << endl;
			if (!N[i][j] && i-1 >= 0) {
				//cout << i-1 << " " << j << endl;
				adj[i][j].pub(mp(i-1, j));
			}
			if (!E[i][j] && j+1 < n) {
				//cout << i << " " << j+1 << endl;
				adj[i][j].pub(mp(i, j+1));
			}
			if (!W[i][j] && j-1 >= 0) {
				//cout << i << " " << j-1 << endl;
				adj[i][j].pub(mp(i, j-1));
			}
			if (!S[i][j] && i+1 < m) {
				//cout << i+1 << " " << j << endl;
				adj[i][j].pub(mp(i+1, j));
			}
		}
	}
}

void ProSolve() {
	cellNo.resize(m, vector<int>(n, 0));
	cellArea.resize(m*n+1, 0);
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			if (!visited[i][j]) {
				cellNo[i][j] = ++ccc; cellArea[ccc] += area[i][j];
				visited[i][j] = true;
				queue<pii> Q; Q.push(mp(i,j));
				while (!Q.empty()) {
					pii tmp = Q.front(); Q.pop();
					for (i64 i=0; i<adj[tmp.fi][tmp.se].size(); i++) {
						pii qq = adj[tmp.fi][tmp.se][i];
						if (!visited[qq.fi][qq.se]) {
							visited[qq.fi][qq.se] = true;
							cellNo[qq.fi][qq.se] = ccc;
							cellArea[ccc] += area[qq.fi][qq.se];
							Q.push(qq);
						}
					}
				}
			}
		}
	}
	/*for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) cout << cellNo[i][j] << " ";
		cout << endl;
	}*/
	ld task2 = *max_element(cellArea.begin()+1, cellArea.begin()+ccc+1), task3 = task2;
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			if (N[i][j] && i-1 >= 0) {
				ld dim1c = 1.0, dim1x = 1.0;
				if (E[i][j]) dim1c -= 0.1; if (W[i][j]) dim1c -= 0.1;
				if (E[i-1][j]) dim1x -= 0.1; if (W[i-1][j]) dim1x -= 0.1;
				ld newArea = cellArea[cellNo[i][j]] + cellArea[cellNo[i-1][j]] + (dim1c + dim1x) * 0.1;
				if (cellNo[i][j] == cellNo[i-1][j]) newArea = cellArea[cellNo[i][j]] + (dim1c + dim1x) * 0.1;
				task3 = max(task3, newArea);
			}
			if (S[i][j] && i+1 < m) {
				ld dim1c = 1.0, dim1x = 1.0;
				if (E[i][j]) dim1c -= 0.1; if (W[i][j]) dim1c -= 0.1;
				if (E[i+1][j]) dim1x -= 0.1; if (W[i+1][j]) dim1x -= 0.1;
				ld newArea = cellArea[cellNo[i][j]] + cellArea[cellNo[i+1][j]] + (dim1c + dim1x) * 0.1;
				if (cellNo[i][j] == cellNo[i+1][j]) newArea = cellArea[cellNo[i][j]] + (dim1c + dim1x) * 0.1;
				task3 = max(task3, newArea);
			}
			if (E[i][j] && j+1 < n) {
				ld dim1c = 1.0, dim1x = 1.0;
				if (N[i][j]) dim1c -= 0.1; if (S[i][j]) dim1c -= 0.1;
				if (N[i][j+1]) dim1x -= 0.1; if (S[i][j+1]) dim1x -= 0.1;
				ld newArea = cellArea[cellNo[i][j]] + cellArea[cellNo[i][j+1]] + (dim1c + dim1x) * 0.1;
				if (cellNo[i][j] == cellNo[i][j+1]) newArea = cellArea[cellNo[i][j]] + (dim1c + dim1x) * 0.1;
				task3 = max(task3, newArea);
			}
			if (W[i][j] && j-1 >= 0) {
				ld dim1c = 1.0, dim1x = 1.0;
				if (N[i][j]) dim1c -= 0.1; if (S[i][j]) dim1c -= 0.1;
				if (N[i][j-1]) dim1x -= 0.1; if (S[i][j-1]) dim1x -= 0.1;
				ld newArea = cellArea[cellNo[i][j]] + cellArea[cellNo[i][j-1]] + (dim1c + dim1x) * 0.1;
				if (cellNo[i][j] == cellNo[i][j-1]) newArea = cellArea[cellNo[i][j]] + (dim1c + dim1x) * 0.1;
				task3 = max(task3, newArea);
			}
		}
	}
	cout << ccc << endl;
	cout << fixed << setprecision(2) << task2 << endl;
	cout << fixed << setprecision(2) << task3;
}

/** -----MAIN FUNCTION----- **/
int main() {
	freopen("CASTLE.INP", "r", stdin);
	freopen("CASTLE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
