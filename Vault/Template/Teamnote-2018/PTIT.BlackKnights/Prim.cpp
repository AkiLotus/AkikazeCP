int n, m; long long ans = 0;
vector<vector<pair<int, int>>> adj;
vector<int> chosen; priority_queue<pair<long long, int>> Q;

void Input() {
	cin >> n >> m; adj.resize(n+1, vector<pair<int, int>>(0));
	chosen.resize(n+1, false); Q.push({0LL, 1});
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({b,c}); adj[b].push_back({a,c});
	}
}

void Solve() {
	while (!Q.empty()) {
		pii Z = Q.top(); Q.pop(); i64 z = Z.second, tmp = Z.first;
		if (chosen[z]) continue; chosen[z] = true; ans -= tmp;
		for (auto zz: adj[z]) {
			if (!chosen[zz.first]) Q.push({-zz.second, zz.first});
		}
	}
	cout << ans;
}