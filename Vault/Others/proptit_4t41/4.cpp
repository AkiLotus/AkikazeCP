#include<bits/stdc++.h>
using namespace std;

struct data {
	int x, y, z;
};

int A, B, C;
char board[32][32][32];
int dp[32][32][32];
vector<data> adj[32][32][32];
bool visited[32][32][32];
int d, e, f, m, n, p;

void generate() {
	for (int i=0; i<A; i++) {
		for (int j=0; j<B; j++) {
			for (int k=0; k<C; k++) {
				if (board[i][j][k] == '#') continue;
				if (i-1 >= 0 && board[i-1][j][k] != '#') {
					data psp; psp.x = i-1; psp.y = j; psp.z = k;
					adj[i][j][k].push_back(psp);
				}
				if (i+1 < A && board[i+1][j][k] != '#') {
					data psp; psp.x = i+1; psp.y = j; psp.z = k;
					adj[i][j][k].push_back(psp);
				}
				if (j-1 >= 0 && board[i][j-1][k] != '#') {
					data psp; psp.x = i; psp.y = j-1; psp.z = k;
					adj[i][j][k].push_back(psp);
				}
				if (j+1 < B && board[i][j+1][k] != '#') {
					data psp; psp.x = i; psp.y = j+1; psp.z = k;
					adj[i][j][k].push_back(psp);
				}
				if (k-1 >= 0 && board[i][j][k-1] != '#') {
					data psp; psp.x = i; psp.y = j; psp.z = k-1;
					adj[i][j][k].push_back(psp);
				}
				if (k+1 < C && board[i][j][k+1] != '#') {
					data psp; psp.x = i; psp.y = j; psp.z = k+1;
					adj[i][j][k].push_back(psp);
				}
			}
		}
	}
}

int main()
{
	int T; cin >> T;
	while (T-- > 0) {
		for (int i=0; i<32; i++) {
			for (int j=0; j<32; j++) {
				for (int k=0; k<32; k++) {
					board[i][j][k] = '\0';
					dp[i][j][k] = 0;
					visited[i][j][k] = false;
					adj[i][j][k].clear();
				}
			}
		}
		cin >> A >> B >> C;
		for (int i=0; i<A; i++) {
			for (int j=0; j<B; j++) {
				for (int k=0; k<C; k++) {
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S') {
						d = i; e = j; f = k;
					}
					if (board[i][j][k] == 'E') {
						m = i; n = j; p = k;
					}
				}
			}
		}
		generate();
		data init, dest;
		init.x = d; init.y = e; init.z = f; dest.x = m; dest.y = n; dest.z = p;
		queue<data> Q;
		if (d != m || e != n || f != p) Q.push(init);
		while (!Q.empty()) {
			data qq = Q.front(); Q.pop();
			if (visited[qq.x][qq.y][qq.z]) continue;
			visited[qq.x][qq.y][qq.z] = true;
			for (int i=0; i<adj[qq.x][qq.y][qq.z].size(); i++) {
				data xxx = adj[qq.x][qq.y][qq.z][i];
				if (visited[xxx.x][xxx.y][xxx.z]) continue;
				if (dp[xxx.x][xxx.y][xxx.z] == 0) dp[xxx.x][xxx.y][xxx.z] = dp[qq.x][qq.y][qq.z] + 1;
				else dp[xxx.x][xxx.y][xxx.z] = min(dp[xxx.x][xxx.y][xxx.z], dp[qq.x][qq.y][qq.z] + 1);
				Q.push(xxx);
			}
		}
		if ((d != m || e != n || f != p) && dp[m][n][p] == 0) cout << -1 << endl;
		else cout << dp[m][n][p] << endl;
	}
	return 0;
}

