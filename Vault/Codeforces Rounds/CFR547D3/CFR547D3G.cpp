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

int n, k; vector<vector<int>> adj; vector<int> Rank;
map<pair<int, int>, int> Map; vector<int> Labels;

bool degreesort(int x, int y) {
	return (adj[x].size() > adj[y].size());
}

void DFS(int z, int last) {
	set<int> IDcnt;
	if (last != -1) {IDcnt.insert(Labels[Map[{z, last}]]);}
	int r = 1; while (IDcnt.find(r) != IDcnt.end()) r++;
	for (auto t: adj[z]) {
		if (t == last) continue;
		if (Rank[z] >= k) {
			int id = Map[{z, t}];
			Labels[id] = r; IDcnt.insert(r);
			while (IDcnt.find(r) != IDcnt.end()) r++;
		}
		DFS(t, z);
	}
}

void Input() {
	cin >> n >> k; adj.resize(n);
	Labels.resize(n-1, 1); Rank.resize(n);
	for (int i=0; i<n-1; i++) {
		int u, v; cin >> u >> v; u--; v--;
		adj[u].push_back(v); adj[v].push_back(u);
		Map[{u, v}] = i; Map[{v, u}] = i;
	}
}

void Solve() {
	if (n == 2) {cout << "1\n1\n"; return;}
	vector<int> A(n); for (int i=0; i<n; i++) A[i] = i;
	sort(A.begin(), A.end(), degreesort);
	for (int i=0; i<n; i++) Rank[A[i]] = i;
	DFS(A[0], -1);
	cout << *max_element(Labels.begin(), Labels.end()) << endl;
	for (auto z: Labels) cout << z << " "; cout << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/