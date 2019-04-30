#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define y0 holdtheflower
#define y1 enjoythecolorandscent
#define yn walkthroughthesoulgarden
#define j1 feelthewarmbreathofkindnessandsalvation

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, m; vector<int> orient;
vector<pair<int, int>> Edge;
vector<bool> vis;
vector<vector<int>> adj;
vector<vector<int>> adjOut, adjIn;
map<pair<int, int>, int> Map;

void DFS(int z, int parity) {
	vis[z] = true;
	for (auto t: adj[z]) {
		int id = Map[make_pair(z, t)];
		if (orient[id] != -1) continue;
		if (parity == 0) {adjOut[z].push_back(t); adjIn[t].push_back(z);}
		else {adjIn[z].push_back(t); adjOut[t].push_back(z);}
		orient[id] = parity ^ (make_pair(z, t) != Edge[id]);
		if (!vis[t]) DFS(t, parity ^ 1);
	}
}

void Input() {
	cin >> n >> m; orient.resize(m, -1);
	vis.resize(m, false); adj.resize(n);
	adjIn.resize(n); adjOut.resize(n); Edge.resize(m);
	for (int i=0; i<m; i++) {
		int u, v; cin >> u >> v; u--; v--;
		Edge[i] = make_pair(u, v);
		Map[make_pair(u, v)] = i; Map[make_pair(v, u)] = i;
		adj[u].push_back(v); adj[v].push_back(u);
	}
}

void Solve() {
	DFS(0, 0);
	for (int i=0; i<n; i++) {
		if (!adjIn[i].empty() && !adjOut[i].empty()) {
			cout << "NO\n"; return;
		}
	}
	cout << "YES\n";
	for (auto z: orient) cout << z;
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