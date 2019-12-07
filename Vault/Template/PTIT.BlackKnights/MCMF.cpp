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
 
	pair<int, int> getMaxFlow(int s, int t) {
		int flow = 0, cost = 0;
		while (spfa(s, t)) {
			pair<int, int> res = increaseFlow(s, t);
			flow += res.first; cost += res.second;
		}
		return {flow, cost};
	}
};