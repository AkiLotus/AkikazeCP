/*

Description: Given an undirected graph that is a tree, the
lowest common ancestor (LCA) of two nodes v and w is the
lowest (i.e. deepest) node that has both v and w as descendants,
where we define each node to be a descendant of itself (so if
v has a direct connection from w, w is the lowest common
ancestor). The following program uses sparse tables to solve
the problem on an unchanging graph.

Time Complexity: O(N log N) for build() and O(log N) for lca(),
where N is the number of nodes in the tree.

Space Complexity: O(N log N).

*/

#include <vector>

const int MAXN = 1000;
int len, timer, tin[MAXN], tout[MAXN];
std::vector<int> adj[MAXN], dp[MAXN];

void dfs(int u, int p) {
  tin[u] = timer++;
  dp[u][0] = p;
  for (int i = 1; i < len; i++)
    dp[u][i] = dp[dp[u][i - 1]][i - 1];
  for (int j = 0, v; j < (int)adj[u].size(); j++)
    if ((v = adj[u][j]) != p)
      dfs(v, u);
  tout[u] = timer++;
}

void build(int nodes, int root) {
  len = 1;
  while ((1 << len) <= nodes) len++;
  for (int i = 0; i < nodes; i++)
    dp[i].resize(len);
  timer = 0;
  dfs(root, root);
}

inline bool is_parent(int parent, int child) {
  return tin[parent] <= tin[child] && tout[child] <= tout[parent];
}

int lca(int a, int b) {
  if (is_parent(a, b)) return a;
  if (is_parent(b, a)) return b;
  for (int i = len - 1; i >= 0; i--)
    if (!is_parent(dp[a][i], b))
      a = dp[a][i];
  return dp[a][0];
}

/*** Example Usage ***/

#include <iostream>
using namespace std;

int main() {
  adj[0].push_back(1);
  adj[1].push_back(0);
  adj[1].push_back(2);
  adj[2].push_back(1);
  adj[3].push_back(1);
  adj[1].push_back(3);
  adj[0].push_back(4);
  adj[4].push_back(0);
  build(5, 0);
  cout << lca(3, 2) << "\n"; //1
  cout << lca(2, 4) << "\n"; //0
  return 0;
}
