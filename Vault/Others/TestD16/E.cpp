#include <iostream>
#include <vector>
using namespace std;

struct data {
    int x, y;
};

int N;
bool visited[128][128];
vector<data> adj[128][128];
int matrix[128][128];
int dp[128][128];

void DFS(int a, int b) {
    for (int i=0; i<adj[a][b].size(); i++) {
        data tmp = adj[a][b][i];
        if (!visited[tmp.x][tmp.y]) {
            dp[tmp.x][tmp.y] = min(dp[a][b]+matrix[tmp.x][tmp.y], dp[tmp.x][tmp.y]);
            visited[tmp.x][tmp.y] = true;
            DFS(tmp.x, tmp.y);
        }
    }
}

int main() {
	cin >> N;
	for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> matrix[i][j];
            dp[i][j] = 99999999;
            data tmp1; tmp1.x = i-1; tmp1.y = j-1;
            data tmp2; tmp2.x = i-1; tmp2.y = j+1;
            data tmp3; tmp3.x = i+1; tmp3.y = j-1;
            data tmp4; tmp4.x = i+1; tmp4.y = j+1;
            if (i > 1 && j > 1) adj[i][j].push_back(tmp1);
            if (i > 1 && j < N) adj[i][j].push_back(tmp2);
            if (i < N && j > 1) adj[i][j].push_back(tmp3);
            if (i < N && j < N) adj[i][j].push_back(tmp4);
        }
	}
	dp[1][1] = matrix[1][1];
	DFS(1, 1);
	cout << dp[N][N];
	return 0;
}
