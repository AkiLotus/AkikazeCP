#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n; vector<vector<pair<int, int>>> adj;
vector<int> ColPar, Par, Start, End;
vector<int> colored;

void DFS(int z, int last, int &id) {
	Start[z] = id;
	for (auto Pr: adj[z]) {
		int t = Pr.first, d = Pr.second;
		if (t == last) continue;
		Par[t] = z; ColPar[t] = d;
		id++; DFS(t, z, id);
	}
	End[z] = id;
}

void Increase(int L, int R, int val) {
	colored[L] += val;
	if (R+1 < colored.size()) colored[R+1] -= val;
}

void Input() {
	cin >> n; adj.resize(n); colored.resize(n, 0);
	Start.resize(n); End.resize(n); Par.resize(n, -1); ColPar.resize(n, -1);
	for (int i=1; i<n; i++) {
		int u, v, c; cin >> u >> v >> c; u--; v--;
		adj[u].push_back({v, c}); adj[v].push_back({u, c});
	}
}

void Solve() {
	int zz = 0; DFS(0, -1, zz);
	for (int z=0; z<n; z++) {
		map<int, int> Map;
		for (auto Pr: adj[z]) {
			int t = Pr.first, col = Pr.second;
			if (t == Par[z]) continue;
			if (ColPar[z] == col) {
				Increase(Start[t], End[t], +1);
				Increase(Start[z], End[z], -1);
				Increase(0, n-1, +1); continue;
			}
			Map[col]++;
		}
		for (auto Pr: adj[z]) {
			int t = Pr.first, col = Pr.second;
			if (t == Par[z]) continue;
			if (ColPar[z] == col) continue;
			if (Map[col] > 1) Increase(Start[t], End[t], +1);
		}
	}
	for (int i=1; i<n; i++) colored[i] += colored[i-1];
	vector<int> List;
	for (int i=0; i<n; i++) {
		if (colored[Start[i]] == 0) List.push_back(i+1);
	}
	cout << List.size() << endl;
	for (auto x: List) cout << x << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/
