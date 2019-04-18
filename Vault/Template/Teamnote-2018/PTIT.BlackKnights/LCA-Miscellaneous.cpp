int n, m, a, b; vector<vector<int>> adj;
vector<vector<int>> Table; vector<int> d, subtree;

void DFS(int z, int last) {
	if (z != 0) d[z] = d[last] + 1;
	for (auto t: adj[z]) {
		if (t == last) continue;
		DFS(t, z); Table[t].pub(z);
		subtree[z] += subtree[t];
	}
}

void Preprocess() {
	subtree.resize(n, 1); Table.resize(n);
	d.resize(n, 0); DFS(0, -1);
	for (int j=1; j<17; j++) {
		for (int i=0; i<n; i++) {
			if (Table[i].size() < j) continue;
			if (Table[Table[i][j-1]].size() < j) continue;
			Table[i].push_back(Table[Table[i][j-1]][j-1]);
		}
	}
}

int ancestor(int node, int dist) {
	if (dist == 0) return node;
	for (int i=16; i>=0; i--) {
		if (dist >= (1LL << i)) {
			return ancestor(Table[node][i], dist - (1LL << i));
		}
	}
}

int LCA(int x, int y) {
	if (x == y) return x;
	if (d[x] == d[y]) {
		int id = 0, Init = min(Table[x].size(), Table[y].size()-1);
		for (int i=Init; i>=0; i--) {
			if (Table[x][i] != Table[y][i]) {id = i; break;}
		}
		return LCA(Table[x][id], Table[y][id]);
	}
	if (d[x] < d[y]) {
		int mul = 1, id = 0;
		while (d[x] < d[y] - mul * 2) {
			mul *= 2; id++;
		}
		return LCA(x, Table[y][id]);
	}
	if (d[x] > d[y]) {
		int mul = 1, id = 0;
		while (d[y] < d[x] - mul * 2) {
			mul *= 2; id++;
		}
		return LCA(Table[x][id], y);
	}
}

int Dist(int x, int y) {
	if (x == y) return 0;
	if (d[x] == d[y]) {
		int id = 0, Init = min(Table[x].size(), Table[y].size()-1);
		for (int i=Init; i>=0; i--) {
			if (Table[x][i] != Table[y][i]) {id = i; break;}
		}
		return ((1LL << id)*2 + Dist(Table[x][id], Table[y][id]));
	}
	if (d[x] < d[y]) {
		int mul = 1, id = 0;
		while (d[x] < d[y] - mul * 2) {
			mul *= 2; id++;
		}
		return ((1LL << id) + Dist(x, Table[y][id]));
	}
	if (d[x] > d[y]) {
		int mul = 1, id = 0;
		while (d[y] < d[x] - mul * 2) {
			mul *= 2; id++;
		}
		return ((1LL << id) + Dist(Table[x][id], y));
	}
}