#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define y0 takethescythe
#define y1 reapyourenemies
#define yn feedontheirflesh
#define j1 ascendthroughtheirblood

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, m; vector<vector<int>> a;

void Input() {
	cin >> n >> m; a.resize(n, vector<int>(m));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}
}

void Solve() {
	vector<map<int, int>> ValueID(n);
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			ValueID[i][a[i][j]] = j + 1;
		}
	}
	vector<vector<bool>> vis(n, vector<bool>(1024, false));
	vector<vector<int>> Last(n, vector<int>(1024, -1));
	queue<pair<int, int>> Q;
	for (auto z: a[0]) {
		vis[0][z] = true; Q.push({0, z});
	}
	while (!Q.empty()) {
		pair<int, int> Token = Q.front(); Q.pop();
		int id = Token.first, val = Token.second;
		if (id == n - 1) break;
		for (auto z: a[id+1]) {
			if (vis[id+1][val ^ z]) continue;
			vis[id+1][val^z] = true; Last[id+1][val^z] = val;
			Q.push({id+1, (val ^ z)});
		}
	}
	for (int i=1; i<1024; i++) {
		if (!vis[n-1][i]) continue;
		int id = n-1, val = i;
		vector<int> Dist(n, -1);
		while (id > 0) {
			int LastVal = Last[id][val];
			Dist[id] = ValueID[id][val ^ LastVal];
			id = id - 1; val = LastVal;
		}
		Dist[0] = ValueID[0][val];
		cout << "TAK\n";
		for (auto z: Dist) cout << z << " ";
		cout << endl; return;
	}
	cout << "NIE\n";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/