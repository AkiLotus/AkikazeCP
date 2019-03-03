#include<bits/stdc++.h>
using namespace std;

struct data {
	int x, y;
};

int N;
char board[128][128];
int dp[128][128];
vector<data> adj[128][128];
bool visited[128][128];
int a, b, c, d;

void generate() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (board[i][j] == 'X') continue;
			int tmp = i-1;
			while (tmp >= 0 && board[tmp][j] == '.') {
				data pp; pp.x = tmp; pp.y = j;
				adj[i][j].push_back(pp); tmp--;
			}
			tmp = i+1;
			while (tmp < N && board[tmp][j] == '.') {
				data pp; pp.x = tmp; pp.y = j;
				adj[i][j].push_back(pp); tmp++;
			}
			tmp = j-1;
			while (tmp >= 0 && board[i][tmp] == '.') {
				data pp; pp.x = i; pp.y = tmp;
				adj[i][j].push_back(pp); tmp--;
			}
			tmp = j+1;
			while (tmp < N && board[i][tmp] == '.') {
				data pp; pp.x = i; pp.y = tmp;
				adj[i][j].push_back(pp); tmp++;
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) cin >> board[i][j];
	}
	cin >> a >> b >> c >> d;
	generate();
	data init, dest;
	init.x = a; init.y = b; dest.x = c; dest.y = d;
	queue<data> Q;
	if (a != c || b != d) Q.push(init);
	while (!Q.empty()) {
		data z = Q.front(); Q.pop();\
		if (visited[z.x][z.y]) continue;
		visited[z.x][z.y] = true;
		for (int i=0; i<adj[z.x][z.y].size(); i++) {
			data xxx = adj[z.x][z.y][i];
			if (visited[xxx.x][xxx.y]) continue;
			if (dp[xxx.x][xxx.y] == 0) dp[xxx.x][xxx.y] = dp[z.x][z.y] + 1;
			else dp[xxx.x][xxx.y] = min(dp[xxx.x][xxx.y], dp[z.x][z.y] + 1);
			Q.push(xxx);
		}
	}
	cout << dp[c][d];
	return 0;
}

