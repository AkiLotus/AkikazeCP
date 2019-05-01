/*

Description: Given a directed graph with positive weights only, find
the shortest distance to all nodes from a single starting node.

Implementation Notes: The graph is stored using an adjacency list.
This implementation negates distances before adding them to the
priority queue, since the container is a max-heap by default. This
method is suggested in contests because it is easier than defining
special comparators. An alternative would be declaring the queue
with template parameters (clearly, this way is very verbose and ugly):
  priority_queue< pair<int, int>, vector<pair<int, int> >,
                  greater<pair<int, int> > > pq;
If only the path between a single pair of nodes is needed, for speed,
we may break out of the loop as soon as the destination is reached
by inserting the line "if (a == dest) break;" after the line "pq.pop();"

Complexity: This version uses an adjacency list and priority queue
(internally a binary heap) and has a complexity of O((E+V) log V) =
O(E log V). The priority queue and adjacency list improves the
simplest O(V^2) version of the algorithm, which uses looping and
an adjacency matrix. If the priority queue is implemented as a more
sophisticated Fibonacci heap, the complexity becomes O(E + V log V).

Modification to Shortest Path Faster Algorithm: The code for Dijkstra's
algorithm here can be easily modified to become the Shortest Path Faster
Algorithm (SPFA) by simply commenting out "visit[a] = true;" and changing
the priority queue to a FIFO queue like in BFS. SPFA is a faster version
of the Bellman-Ford algorithm, working on negative path lengths (whereas
Dijkstra's cannot). Certain graphs can be constructed to make SPFA slow.

=~=~=~=~= Sample Input =~=~=~=~=
4 5
0 1 2
0 3 8
1 2 2
1 3 4
2 3 1
0 3

=~=~=~=~= Sample Output =~=~=~=~=
The shortest distance from 0 to 3 is 5.
Take the path: 0->1->2->3.

*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 100, INF = 0x3f3f3f3f;
int dist[MAXN], pred[MAXN];
vector<pair<int, int> > adj[MAXN];

void dijkstra(int nodes, int start) {
  vector<bool> vis(nodes, false);
  for (int i = 0; i < nodes; i++) {
    dist[i] = INF;
    pred[i] = -1;
  }
  int u, v;
  dist[start] = 0;
  priority_queue<pair<int, int> > pq;
  pq.push(make_pair(0, start));
  while (!pq.empty()) {
    u = pq.top().second;
    pq.pop();
    vis[u] = true;
    for (int j = 0; j < (int)adj[u].size(); j++) {
      if (vis[v = adj[u][j].first]) continue;
      if (dist[v] > dist[u] + adj[u][j].second) {
        dist[v] = dist[u] + adj[u][j].second;
        pred[v] = u;
        pq.push(make_pair(-dist[v], v));
      }
    }
  }
}

//Use the precomputed pred[] array to print the path
void print_path(int dest) {
  int i = 0, j = dest, path[MAXN];
  while (pred[j] != -1) j = path[++i] = pred[j];
  cout << "Take the path: ";
  while (i > 0) cout << path[i--] << "->";
  cout << dest << ".\n";
}

int main() {
  int nodes, edges, u, v, w, start, dest;
  cin >> nodes >> edges;
  for (int i = 0; i < edges; i++) {
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v, w));
  }
  cin >> start >> dest;
  dijkstra(nodes, start);
  cout << "The shortest distance from " << start;
  cout << " to " << dest << " is " << dist[dest] << ".\n";
  print_path(dest);
  return 0;
}
