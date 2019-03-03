#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

const long long Mod = 998244353LL;

int n, m; vector<vector<int>> adj;
vector<vector<long long>> dp;

void Input() {
	cin >> n >> m; adj.clear(); dp.clear();
	adj.resize(n); dp.resize(n, vector<long long>(2, 0));
	dp[0][0] = 1; dp[0][1] = 2;
	while (m--) {
		int u, v; cin >> u >> v; u--; v--;
		adj[u].push_back(v); adj[v].push_back(u);
	}
}

void Solve() {
	long long ans = 1;
	vector<vector<int>> state(n, vector<int>(2, -1));
	for (int i=0; i<n; i++) {
		if (state[i][0] != -1) continue;
		queue<int> Q; Q.push(i);
		state[i][0] = 0; state[i][1] = 1;
		vector<int> valid(2, 1), List;
		int tmp1 = 1, tmp2 = 1;
		while (!Q.empty()) {
			int z = Q.front(); Q.pop();
			List.push_back(z);
			for (auto t: adj[z]) {
				if (state[t][0] != -1 && (state[z][0] + state[t][0]) % 2 == 0) valid[0] = 0;
				if (state[t][1] != -1 && (state[z][1] + state[t][1]) % 2 == 0) valid[1] = 0;
				if (state[t][0] != -1) continue;
				state[t][0] = 1 - state[z][0]; state[t][1] = 1 - state[z][1];
				Q.push(t);
			}
		}
		tmp1 *= valid[0]; tmp2 *= valid[1];
		for (auto z: List) {
			tmp1 *= (state[z][0] + 1); tmp1 %= Mod;
			tmp2 *= (state[z][1] + 1); tmp2 %= Mod;
		}
		ans *= (tmp1 + tmp2); ans %= Mod;
	}
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
