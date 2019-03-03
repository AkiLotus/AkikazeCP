i64 n, m, a, b; vector<vi> adj;
vector<vi> Table; vi d, subtree;

void DFS(i64 z, i64 last) {
	if (z != 0) d[z] = d[last] + 1;
	for (auto t: adj[z]) {
		if (t == last) continue;
		DFS(t, z); Table[t].pub(z);
		subtree[z] += subtree[t];
	}
}

void Preprocess() {
	subtree.rsz(n, 1); Table.rsz(n);
	d.rsz(n, 0); DFS(0, -1);
	for (i64 j=1; j<17; j++) {
		for (i64 i=0; i<n; i++) {
			if (Table[i].size() < j) continue;
			if (Table[Table[i][j-1]].size() < j) continue;
			Table[i].pub(Table[Table[i][j-1]][j-1]);
		}
	}
}

i64 ancestor(i64 node, i64 dist) {
	if (dist == 0) return node;
	for (i64 i=16; i>=0; i--) {
		if (dist >= (1LL << i)) {
			return ancestor(Table[node][i], dist - (1LL << i));
		}
	}
}

i64 LCA(i64 x, i64 y) {
	if (x == y) return x;
	if (d[x] == d[y]) {
		i64 id = 0, Init = min(Table[x].size(), Table[y].size()-1);
		for (i64 i=Init; i>=0; i--) {
			if (Table[x][i] != Table[y][i]) {id = i; break;}
		}
		return LCA(Table[x][id], Table[y][id]);
	}
	if (d[x] < d[y]) {
		i64 mul = 1, id = 0;
		while (d[x] < d[y] - mul * 2) {
			mul *= 2; id++;
		}
		return LCA(x, Table[y][id]);
	}
	if (d[x] > d[y]) {
		i64 mul = 1, id = 0;
		while (d[y] < d[x] - mul * 2) {
			mul *= 2; id++;
		}
		return LCA(Table[x][id], y);
	}
}

i64 Dist(i64 x, i64 y) {
	if (x == y) return 0;
	if (d[x] == d[y]) {
		i64 id = 0, Init = min(Table[x].size(), Table[y].size()-1);
		for (i64 i=Init; i>=0; i--) {
			if (Table[x][i] != Table[y][i]) {id = i; break;}
		}
		return ((1LL << id)*2 + Dist(Table[x][id], Table[y][id]));
	}
	if (d[x] < d[y]) {
		i64 mul = 1, id = 0;
		while (d[x] < d[y] - mul * 2) {
			mul *= 2; id++;
		}
		return ((1LL << id) + Dist(x, Table[y][id]));
	}
	if (d[x] > d[y]) {
		i64 mul = 1, id = 0;
		while (d[y] < d[x] - mul * 2) {
			mul *= 2; id++;
		}
		return ((1LL << id) + Dist(Table[x][id], y));
	}
}