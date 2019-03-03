#include<bits/stdc++.h>
using namespace std;

struct data {
	int x, y;
};

int infant = 0;
int R, C;
int mat[512][512];
int clones[512][512];
int dp[512][512];
bool visited[512][512];

void spread(int x, int y) {
	if (x-1 >= 0 && x-1 < R && clones[x-1][y] == 1 && !visited[x-1][y]) {
		clones[x-1][y] = 2; infant--;
		spread(x-1, y);
	}
	if (x+1 >= 0 && x+1 < R && clones[x+1][y] == 1 && !visited[x+1][y]) {
		clones[x+1][y] = 2; infant--;
		spread(x+1, y);
	}
	if (y-1 >= 0 && y-1 < C && clones[x][y-1] == 1 && !visited[x][y-1]) {
		clones[x][y-1] = 2; infant--;
		spread(x, y-1);
	}
	if (y+1 >= 0 && y+1 < C && clones[x][y+1] == 1 && !visited[x][y+1]) {
		clones[x][y+1] = 2; infant--;
		spread(x, y+1);
	}
}

int main()
{
	cin >> R >> C;
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			cin >> mat[i][j];
			clones[i][j] = mat[i][j];
			if (mat[i][j] == 1) infant++;
		}
	}
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			if (mat[i][j] == 2) spread(i, j);
		}
	}
	if (infant != 0) cout << -1;
	else {
		queue<data> Q;
		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) {
				if (mat[i][j] == 2) {
					data tmp; tmp.x = i; tmp.y = j;
					Q.push(tmp);
				}
			}
		}
		while (!Q.empty()) {
			data z = Q.front();
			Q.pop();
			if (visited[z.x][z.y]) continue;
			visited[z.x][z.y] = true;
			if (z.x-1 >= 0 && mat[z.x-1][z.y] == 1 && !visited[z.x-1][z.y]) {
				data cl = z; cl.x--; Q.push(cl);
				if(dp[cl.x][cl.y] != 0) dp[cl.x][cl.y] = min(dp[cl.x][cl.y], dp[z.x][z.y] + 1);
				else dp[cl.x][cl.y] = dp[z.x][z.y] + 1;
			}
			if (z.x+1 < R && mat[z.x+1][z.y] == 1 && !visited[z.x+1][z.y]) {
				data cl = z; cl.x++; Q.push(cl);
				if(dp[cl.x][cl.y] != 0) dp[cl.x][cl.y] = min(dp[cl.x][cl.y], dp[z.x][z.y] + 1);
				else dp[cl.x][cl.y] = dp[z.x][z.y] + 1;
			}
			if (z.y-1 >= 0 && mat[z.x][z.y-1] == 1 && !visited[z.x][z.y-1]) {
				data cl = z; cl.y--; Q.push(cl);
				if(dp[cl.x][cl.y] != 0) dp[cl.x][cl.y] = min(dp[cl.x][cl.y], dp[z.x][z.y] + 1);
				else dp[cl.x][cl.y] = dp[z.x][z.y] + 1;
			}
			if (z.y+1 < C && mat[z.x][z.y+1] == 1 && !visited[z.x][z.y+1]) {
				data cl = z; cl.y++; Q.push(cl);
				if(dp[cl.x][cl.y] != 0) dp[cl.x][cl.y] = min(dp[cl.x][cl.y], dp[z.x][z.y] + 1);
				else dp[cl.x][cl.y] = dp[z.x][z.y] + 1;
			}
		}
		int answer = dp[0][0];
		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) answer = max(answer, dp[i][j]);
		}
		cout << answer;
	}
	return 0;
}

