// Code written by JadeMasochist

#include <bits/stdc++.h>
using namespace std;

#define LL long long
typedef vector<LL> vi;


LL n, m, SCCcnt = 0; // Basic variables.
LL Time = 0; // Used to track the traversing order.
vector<vi> adj; vi Lowest, Enum; // Store essential informations.
	// adj: Adjacency lists.
	// Enum: The traversing position of a node.
	// Lowest: The lowest position of any nodes within the same SCC as the current one.
stack<LL> S; // Keep the currently working nodes (incomplete SCC).

void traverse(LL z) {
	Lowest[z] = ++Time; Enum[z] = Time; S.push(z);
	for (LL i=0; i<adj[z].size(); i++) {
		if (Enum[adj[z][i]] != 0) Lowest[z] = min(Lowest[z], Lowest[adj[z][i]]); // Traversed node - update Lowest value.
		else {
			traverse(adj[z][i]); // Untraversed node, so traverse it.
			Lowest[z] = min(Lowest[z], Lowest[adj[z][i]]); // Update the new Lowest value.
		}
	}
	
	if (Enum[z] == Lowest[z]) { // Lowest node found - SCC completed
		SCCcnt++; LL t;
		do {
			t = S.top(); S.pop();
			Lowest[t] = 1e18; Enum[t] = 1e18; // Remove every vertex on the SCC out of traversion.
		}
		while (z != t);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m; adj.resize(n+1, vi(0));
	while (m--) {
		LL u, v; cin >> u >> v;
		adj[u].push_back(v);
	}
	Lowest.resize(n+1, 0); Enum = Lowest;
	for (LL i=1; i<=n; i++) {
		if (Lowest[i] == 0) traverse(i);
	}
	cout << SCCcnt;	
	return 0;
}