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

int n, m, c, q; vector<int> DSUpar, DSUsize;
vector<map<int, int>> adj;
vector<set<int>> neighbors;

int DSUfind(int x) {
	while (DSUpar[x] != -1) x = DSUpar[x];
	return x;
}

void DSUmerge(int x, int y) {
	x = DSUfind(x); y = DSUfind(y);
	if (x == y) return;
	if (DSUsize[x] < DSUsize[y]) swap(x, y);
	DSUsize[x] += DSUsize[y]; DSUpar[y] = x;
	for (auto it=neighbors[y].begin(); it!=neighbors[y].end(); it++) {
		neighbors[x].insert(*it);
	}
}

void Input() {
	cin >> n >> m >> c >> q; adj.resize(n); neighbors.resize(n);
	DSUpar.resize(n, -1); DSUsize.resize(n, +1);
	while (m--) {
		int x, y, z; cin >> x >> y >> z; x--; y--;
		neighbors[DSUfind(x)].insert(y); neighbors[DSUfind(y)].insert(x);
		if (adj[x].find(z) != adj[x].end()) DSUmerge(y, adj[x][z]);
		else adj[x][z] = y;
		if (adj[y].find(z) != adj[y].end()) DSUmerge(x, adj[y][z]);
		else adj[y][z] = x;
	}
}

void Solve() {
	while (q--) {
		char cmd; int x, y; cin >> cmd >> x >> y; x--; y--;
		if (cmd == '+') {
			int z; cin >> z;
			neighbors[DSUfind(x)].insert(y); neighbors[DSUfind(y)].insert(x);
			if (adj[x].find(z) != adj[x].end()) DSUmerge(y, adj[x][z]);
			else adj[x][z] = y;
			if (adj[y].find(z) != adj[y].end()) DSUmerge(x, adj[y][z]);
			else adj[y][z] = x;
		}
		else if (cmd == '?') {
			if (DSUfind(x) == DSUfind(y)) cout << "Yes\n";
			else if (neighbors[DSUfind(x)].find(y) != neighbors[DSUfind(x)].end()) cout << "Yes\n";
			else cout << "No\n";
		}
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/