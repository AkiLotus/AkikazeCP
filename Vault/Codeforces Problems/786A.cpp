#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int n, k1, k2; vector<vector<int>> a;
vector<int> m(2);

void Input() {
	cin >> n; a.resize(2);
	for (int i=0; i<2; i++) {
		cin >> m[i]; a[i].resize(m[i]);
		for (auto &x: a[i]) cin >> x;
	}
}

void Solve() {
	vector<vector<int>> ans(2, vector<int>(n+1, 0));
	vector<vector<int>> deg(2, vector<int>(n+1, 0));
	queue<pair<bool, int>> q;
	q.push({0, 1}); ans[0][1] = 2;
	q.push({1, 1}); ans[1][1] = 2;
	while(!q.empty()) {
		bool i = !q.front().first;
		int pos = q.front().second;
		q.pop();
		for (int j=0; j<m[i]; j++) {
			int t = (pos - a[i][j] + n - 1) % n + 1;
			if ((++deg[i][t] == m[i] || ans[!i][pos] == 2) && !ans[i][t]) {
				ans[i][t] = 3 - ans[!i][pos];
				q.push({i,t});
			}
		}
	}
	for (int i=0; i<2; i++) {
		for(int j=2; j<=n; j++) {
			cout << (ans[i][j] ? ans[i][j] == 1 ? "Win " : "Lose " : "Loop ");
		}
		cout << endl;
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
