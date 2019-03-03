#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, m; vector<bool> vis;
vector<vector<int>> adj;

void Input() {
	cin >> n >> m; adj.resize(n);
	vis.resize(n, false);
	while (m--) {
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void Solve() {
	priority_queue<int, vector<int>, greater<int>> MinHeap;
	MinHeap.push(0); vis[0] = true;
	while (!MinHeap.empty()) {
		int z = MinHeap.top(); MinHeap.pop();
		cout << z+1 << " ";
		for (auto t: adj[z]) {
			if (vis[t]) continue;
			vis[t] = true; MinHeap.push(t);
		}
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
*  Thuy-Trang Tran, #Team4T's Leader     *
*  #Team4T Primary Flagship - Salvation  *
\******************************************/
