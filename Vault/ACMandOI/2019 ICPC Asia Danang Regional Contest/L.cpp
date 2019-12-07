#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define y0 takethescythe
#define y1 reapyourenemies
#define yn feedontheirflesh
#define j1 ascendthroughtheirblood

#define endl '\n'
typedef long long i64;
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1000000000;

struct Edge {int v, rev, cap, f, cost;};
 
class MaxFlow {
private:
	int n;
	vector<vector<Edge>> g;
	vector<int> pNode, pEdge;
 
	bool spfa(int s, int t) {
		queue<int> q; pNode.assign(n, -1); pEdge.assign(n, -1);
		vector<bool> inQueue(n, false); vector<int> dist(n, INF);
 
		q.push(s); inQueue[s] = true; dist[s] = 0;
 
		while (!q.empty()) {
			int u = q.front(); q.pop();
			inQueue[u] = false;
 
			for(int i = 0; i < g[u].size(); ++i) {
				Edge e = g[u][i];
				if (e.cap - e.f == 0)
					continue;
				if (dist[u] + e.cost < dist[e.v]) {
					dist[e.v] = dist[u] + e.cost;
					pNode[e.v] = u;
					pEdge[e.v] = i;
					if (!inQueue[e.v]) {
						q.push(e.v);
						inQueue[e.v] = true;
					}
				}
			}
		}
 
		return (dist[t] != INF);
	}
 
	pair<int, int> increaseFlow(int s, int t) {
		int df = INF;
		for(int v = t; v != s; v = pNode[v]) {
			int u = pNode[v], i = pEdge[v];
			df = min(df, g[u][i].cap - g[u][i].f);
		}
 
		int dcost = 0;
		for(int v = t; v != s; v = pNode[v]) {
			int u = pNode[v], i = pEdge[v];
			g[u][i].f += df;
			g[v][g[u][i].rev].f -= df;
			dcost += g[u][i].cost * df;
		}
 
		return {df, dcost};
	}
 
public:
	MaxFlow(int n): n(n) {
		g.assign(n, vector<Edge>());
	}
 
	void addEdge(int u, int v, int cap, int cost) {
		g[u].push_back({v, (int)g[v].size(), cap, 0, cost});
		g[v].push_back({u, (int)g[u].size() - 1, 0, 0, -cost});
	}

	vector<Edge> getEdgesFrom(int id) {
		return g[id];
	}
 
	pair<int, int> getMaxFlow(int s, int t) {
		int flow = 0, cost = 0;
		while (spfa(s, t)) {
			pair<int, int> res = increaseFlow(s, t);
			flow += res.first; cost += res.second;
		}
		return {flow, cost};
	}
};

int n, k; vector<vector<int>> a;
vector<bool> vis;

void Input() {
	cin >> n >> k; a.resize(n, vector<int>(n, 0));
	vis.resize(n+1, false);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> a[i][j];
			vis[a[i][j]] = true;
		}
	}
}

void Solve() {
	for (int x=1; x<=n; x++) {
		if (vis[x]) continue;

		MaxFlow flownet = MaxFlow(n*2+2);
		for (int i=1; i<=n; i++) flownet.addEdge(0, i, 1, 0);
		for (int i=n+1; i<=n*2; i++) flownet.addEdge(i, n*2+1, 1, 0);
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (a[i][j] == 0) {
					flownet.addEdge(i+1, n+j+1, INF, 0);
				}
			}
		}
		int matching = flownet.getMaxFlow(0, n*2+1).first;
		if (matching < n) {cout << "NO\n"; return;}
		for (int i=0; i<n; i++) {
			vector<Edge> edgeList = flownet.getEdgesFrom(i+1);
			for (auto E: edgeList) {
				int j = E.v - n - 1;
				if (E.v < n+1 || E.v > n*2) continue;
				if (E.f == 1) a[i][j] = x;
			}
		}
	}
	cout << "YES\n";
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/