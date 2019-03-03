#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int n; vector<int> p;
vector<long long> acc;
vector<vector<int>> adj;

int DFS(int z, int last, int subtree) {
	for (auto t: adj[z]) {
		if (t == last) continue;
		subtree += DFS(t, z, 1);
		acc[z] += acc[t];
	}
	acc[z] += subtree;
	return subtree;
}

void Input() {
	cin >> n; p.resize(n, -1);
	acc.resize(n, 0LL); adj.resize(n);
	for (int i=1; i<n; i++) {
		cin >> p[i]; p[i]--;
		adj[i].push_back(p[i]);
		adj[p[i]].push_back(i);
	}
}

void Solve() {
	DFS(0, -1, 1);
	for (auto x: acc) cout << x << " ";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/