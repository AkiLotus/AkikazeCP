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

int n; vector<int> cmd, f;
vector<vector<int>> adj;

void DFS(int z, vector<int> &Leaf, vector<int> &Max) {
	bool isLeaf = true;
	int DiffMin = INT_MAX, MinCase = 1;
	for (auto t: adj[z]) {
		isLeaf = false;
		DFS(t, Leaf, Max); Leaf[z] += Leaf[t];
		DiffMin = min(DiffMin, Leaf[t] - Max[t]);
		MinCase += (Max[t] - 1);
	}
	if (isLeaf) {Leaf[z] = 1; Max[z] = 1;}
	else if (cmd[z] == 0) Max[z] = MinCase;
	else if (cmd[z] == 1) Max[z] = Leaf[z] - DiffMin;
}

void Input() {
	cin >> n; cmd.resize(n);
	f.resize(n, -1); adj.resize(n);
	for (auto &z: cmd) cin >> z;
	for (int i=1; i<n; i++) {
		cin >> f[i]; f[i]--;
		adj[f[i]].push_back(i);
	}
}

void Solve() {
	vector<int> Leaf(n), Max(n);
	DFS(0, Leaf, Max);
	cout << Max[0] << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/