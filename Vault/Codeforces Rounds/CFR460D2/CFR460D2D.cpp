#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, m, ans = 0; string s;
vector<vector<int>> adj, dp;
vector<int> visited; bool cycle = false;
stack<int> topo;

void DFS(int z) {
	visited[z] = 2; // traversing state
	if (cycle) return;
	for (int i=0; i<adj[z].size(); i++) {
		if (visited[adj[z][i]] == 1) continue;
		if (visited[adj[z][i]] == 2) {
			cycle = true; return;
		}
		DFS(adj[z][i]);
	}
	visited[z] = 1; // completion state
	topo.push(z);
}

void toposort() {
	for (int i=0; i<n; i++) {
		if (cycle) break;
		if (!visited[i]) DFS(i);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m; adj.resize(n, vector<int>(0));
	dp.resize(n, vector<int>(26, 0));
	visited.resize(n, 0); cin >> s;
	while (m--) {
		int x, y; cin >> x >> y;
		if (x == y) {cout << "-1"; return 0;} // loop
		adj[--x].push_back(--y);
	}
	toposort();
	if (cycle) {cout << "-1"; return 0;} // cycle found, not DAG so path will be infinitely long
	while (!topo.empty()) {
		int fr = topo.top();
		dp[fr][s[fr]-'a'] = max(dp[fr][s[fr]-'a'], 1);
		for (int i=0; i<adj[fr].size(); i++) {
			for (int j=0; j<26; j++) {
				dp[adj[fr][i]][j] = max(dp[adj[fr][i]][j], dp[fr][j] + (s[adj[fr][i]] == char(97+j)));
			}
		}
		topo.pop();
	}
	for (int i=0; i<n; i++) ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
	cout << ans;
	return 0;
}