#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int n, k, x; vector<int> a;
vector<vector<long long>> dp;

void Input() {
	cin >> n >> k >> x; a.resize(n);
	dp.resize(x+1, vector<long long>(n, -1LL));
	for (auto &z: a) cin >> z;
}

void Solve() {
	for (int i=0; i<k; i++) dp[1][i] = a[i];
	for (int i=2; i<=x; i++) {
		deque<int> D;
		for (int j=0; j<n; j++) {
			while (!D.empty() && D.front() <= j-k-1) D.pop_front();
			if (!D.empty()) dp[i][j] = max(dp[i][j], dp[i-1][D.front()] + a[j]);
			while (!D.empty() && dp[i-1][j] > dp[i-1][D.back()]) D.pop_back();
			if (dp[i-1][j] != -1) D.push_back(j);
		}
	}
	long long ans = -1LL;
	for (int i=n-k; i<n; i++) ans = max(ans, dp[x][i]);
	cout << ans;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}