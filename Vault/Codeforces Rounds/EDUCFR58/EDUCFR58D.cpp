#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, u, v; vector<int> a;
vector<vector<int>> adj;

int Max = 0;

void DFS(int z, int last, map<int, int> &Map) {
	map<int, vector<int>> CrossoverPaths;
	for (auto t: adj[z]) {
		if (t == last) continue;
		map<int, int> Map2; DFS(t, z, Map2);
		map<int, int> TmpMap;
		for (auto it=Map2.begin(); it!=Map2.end(); it++) {
			int k = it->first, w = it->second;
			Max = max(Max, w);
			int G = __gcd(k, a[z]);
			if (G == 1) continue;
			Map[G] = max(Map[G], w+1);
			for (int i=2; i<=sqrt(G); i++) {
				if (G % i != 0) continue;
				while (G % i == 0) G /= i;
				TmpMap[i] = max(TmpMap[i], w+1);
			}
			if (G > 1) TmpMap[G] = max(TmpMap[G], w+1);
		}
		for (auto it=TmpMap.begin(); it!=TmpMap.end(); it++) {
			int k = it->first, w = it->second;
			CrossoverPaths[k].push_back(w);
		}
	}
	if (a[z] > 1) Map[a[z]] = max(Map[a[z]], 1);
	for (auto it=CrossoverPaths.begin(); it!=CrossoverPaths.end(); it++) {
		vector<int> A = it->second; sort(A.rbegin(), A.rend());
		if (A.size() == 1) continue; Max = max(Max, A[0] + A[1] - 1);
	}
}

void Input() {
	cin >> n; a.resize(n); adj.resize(n);
	for (auto &x: a) cin >> x;
	for (int i=1; i<n; i++) {
		cin >> u >> v; u--; v--;
		adj[u].push_back(v); adj[v].push_back(u);
	}
}

void Solve() {
	map<int, int> Map;
	DFS(0, -1, Map);
	for (auto it=Map.begin(); it!=Map.end(); it++) {
		Max = max(Max, it->second);
	}
	cout << Max << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
