i64 n, m, ans = 0; vector<vector<pii>> adj;
vector<i64> chosen; priority_queue<pii> Q;

void Input() {
	cin >> n >> m; adj.resize(n+1, vector<pii>(0));
	chosen.resize(n+1, false); Q.push({0, 1});
	while (m--) {
		i64 a, b, c; cin >> a >> b >> c;
		adj[a].pub({b,c}); adj[b].pub({a,c});
	}
}

void Solve() {
	while (!Q.empty()) {
		pii Z = Q.top(); Q.pop(); i64 z = Z.se, tmp = Z.fi;
		if (chosen[z]) continue; chosen[z] = true; ans -= tmp;
		for (auto zz: adj[z]) {
			if (!chosen[zz.fi]) Q.push({-zz.se, zz.fi});
		}
	}
	cout << ans;
}