#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

const long long L_Inf = 1000000000000000000LL;

int n, u, v; vector<int> a;
vector<long long> dp, Max;
vector<vector<int>> adj;

void DFS(int z, int last) {
	bool isLeaf = true;
	for (auto t: adj[z]) {
		if (t == last) continue;
		isLeaf = false; DFS(t, z);
	}
	if (isLeaf) {
		dp[z] = a[z];
		Max[z] = a[z];
		return;
	}
	dp[z] = a[z];
	for (auto t: adj[z]) {
		if (t == last) continue;
		dp[z] += max(0LL, dp[t]);
	}
	Max[z] = dp[z];
	for (auto t: adj[z]) {
		if (t == last) continue;
		Max[z] = max(Max[z], Max[t]);
	}
}

int DFSSeek(int z, int last, vector<bool> &discarded, vector<long long> &subtree, long long Max) {
	bool isLeaf = true; subtree[z] = a[z]; int cnt = 0;
	for (auto t: adj[z]) {
		if (t == last) continue;
		isLeaf = false; cnt += DFSSeek(t, z, discarded, subtree, Max);
		if (!discarded[t]) subtree[z] += max(0LL, subtree[t]);
	}
	if (subtree[z] == Max) {discarded[z] = true; return cnt+1;}
	return cnt;
}

void Input() {
	cin >> n; a.resize(n);
	adj.resize(n);
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=1; i<n; i++) {
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void Solve() {
	if (*max_element(a.begin(), a.end()) <= 0) {
		int Max = *max_element(a.begin(), a.end());
		long long s = 0LL; int k = 0;
		for (int i=0; i<n; i++) {
			if (a[i] != Max) continue;
			s += Max; k++;
		}
		cout << s << " " << k << endl; return;
	}
	dp.resize(n, 0LL); Max.resize(n, 0LL);
	vector<bool> discarded(n, false);
	vector<long long> subtree(n, 0);
	DFS(0, -1); long long cnt = DFSSeek(0, -1, discarded, subtree, Max[0]);
	cout << Max[0] * cnt << " " << cnt << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
