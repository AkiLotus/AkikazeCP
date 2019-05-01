i64 Dinic_DFS(i64 z, i64 src, i64 sink, i64 MinCap, vector<vi> &CapacityMatrix, vector<vi> &adj, vi &dist) {
	if (z == sink) return MinCap;
	i64 Total = 0;
	for (auto t: adj[z]) {
		if (dist[z] >= dist[t]) continue;
		if (CapacityMatrix[z][t] == 0) continue;
		i64 Reduced = Dinic_DFS(t, src, sink, min(MinCap, CapacityMatrix[z][t]), CapacityMatrix, adj, dist);
		CapacityMatrix[z][t] -= Reduced; CapacityMatrix[t][z] += Reduced;
		Total += Reduced; MinCap -= Reduced; if (MinCap == 0) break;
	}
	return Total;
}
 
void ConstructGraph(i64 &N, vector<vi> &CapacityMatrix, vector<vi> &adj, i64 &src, i64 &sink) {
	// do anything required to make the graph, based on the original material
}
 
i64 MaxFlow(vector<vi> CapacityMatrix = vector<vi>(0), vector<vi> adj = vector<vi>(0), i64 N = 0, i64 src = 0, i64 sink = 0) {
	ConstructGraph(N, CapacityMatrix, adj, src, sink);
	i64 res = 0;
	while (true) {
		vb vis(N, false); vi dist(N, LINF);
		queue<i64> Q; Q.push(src);
		vis[src] = true; dist[src] = 0;
		while (!Q.empty()) {
			i64 z = Q.front(); Q.pop();
			for (auto t: adj[z]) {
				if (vis[t]) continue;
				if (CapacityMatrix[z][t] == 0) continue;
				vis[t] = true; dist[t] = dist[z] + 1; Q.push(t);
			}
		}
		if (dist[sink] == LINF) break;
		i64 DinicCall = Dinic_DFS(src, src, sink, LINF, CapacityMatrix, adj, dist);
		res += DinicCall;
	}
	return res;
}