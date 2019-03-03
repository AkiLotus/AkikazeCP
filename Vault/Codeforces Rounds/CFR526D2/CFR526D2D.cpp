#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

long long n, u, v, c;
vector<long long> w, dp;
vector<vector< pair<long long, long long> >> adj;
long long ans = 0;

void DFS(long long z, long long last) {
	priority_queue<long long> Heap;
	Heap.push(0);
	for (auto T: adj[z]) {
		long long t = T.first, d = T.second;
		if (t == last) continue;
		DFS(t, z);
		Heap.push(dp[t] - d);
	}
	dp[z] = max(dp[z], Heap.top() + w[z]);
	if (Heap.size() == 1) ans = max(ans, dp[z]);
	else {
		Heap.pop(); long long additional = Heap.top();
		ans = max(ans, dp[z] + additional);
	}
}

void Input() {
	cin >> n; w.resize(n); adj.resize(n);
	for (auto &x: w) cin >> x;
	dp = w;
	for (long long i=1; i<n; i++) {
		cin >> u >> v >> c; u--; v--;
		adj[u].push_back(make_pair(v, c));
		adj[v].push_back(make_pair(u, c));
	}
}

void Solve() {
	DFS(0, -1);
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
