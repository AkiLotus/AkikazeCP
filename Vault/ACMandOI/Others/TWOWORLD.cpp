// Template by proptit_4t41
// Applied for C++11/C++14
// Add -std=c++14 to your IDE.

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

// custom typedef here


// global variables here
int r, c;
char board[1024][1024];
bool visited[1024][1024];
int mask[1024][1024];

// functions here


int main() {
	freopen("TWOWORLD.INP", "r", stdin);
	freopen("TWOWORLD.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	cin >> r >> c;
	for (int i=1; i<=r; i++) {visited[i][0] = true; visited[i][c+1] = true;}
	for (int i=1; i<=c; i++) {visited[0][i] = true; visited[r+1][i] = true;}
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			cin >> board[i][j];
		}
	}
	int binCount = 0, decCount = 0;
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			if (visited[i][j]) continue;
			visited[i][j] = true;
			int sign = 1, cc;
			if (board[i][j] == '0') {
				sign = -1; cc = ++binCount;
			}
			else cc = ++decCount;
			mask[i][j] = cc * sign;
			queue<pii> Q; Q.push(mp(i,j));
			while (!Q.empty()) {
				pii tmp = Q.front(); Q.pop();
				if (!visited[tmp.fi-1][tmp.se] && board[tmp.fi-1][tmp.se] == board[tmp.fi][tmp.se]) {
					visited[tmp.fi-1][tmp.se] = true; mask[tmp.fi-1][tmp.se] = cc * sign;
					Q.push(mp(tmp.fi-1, tmp.se));
				}
				if (!visited[tmp.fi+1][tmp.se] && board[tmp.fi+1][tmp.se] == board[tmp.fi][tmp.se]) {
					visited[tmp.fi+1][tmp.se] = true; mask[tmp.fi+1][tmp.se] = cc * sign;
					Q.push(mp(tmp.fi+1, tmp.se));
				}
				if (!visited[tmp.fi][tmp.se-1] && board[tmp.fi][tmp.se-1] == board[tmp.fi][tmp.se]) {
					visited[tmp.fi][tmp.se-1] = true; mask[tmp.fi][tmp.se-1] = cc * sign;
					Q.push(mp(tmp.fi, tmp.se-1));
				}
				if (!visited[tmp.fi][tmp.se+1] && board[tmp.fi][tmp.se+1] == board[tmp.fi][tmp.se]) {
					visited[tmp.fi][tmp.se+1] = true; mask[tmp.fi][tmp.se+1] = cc * sign;
					Q.push(mp(tmp.fi, tmp.se+1));
				}
			}
		}
	}
	int m; cin >> m;
	while (m--) {
		int r1, r2, c1, c2; cin >> r1 >> c1 >> r2 >> c2;
		if (mask[r1][c1] != mask[r2][c2]) cout << "Neither\n";
		else if (mask[r1][c1] < 0) cout << "Binary\n";
		else cout << "Decimal\n";
	}
	return 0;
}
