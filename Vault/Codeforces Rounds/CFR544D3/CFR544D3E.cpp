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

int n, k; vector<int> a;
int dp[5000][5001];

void Input() {
	cin >> n >> k; a.resize(n);
	for (auto &z: a) cin >> z;
	for (int i=0; i<n; i++) {
		for (int j=1; j<=k; j++) {
			dp[i][j] = -1;
		}
	}
}

void Solve() {
	sort(a.begin(), a.end());
	int i = 0, j = -1;
	for (; i<n; i++) {
		while (j+1 < n && a[j+1] - a[i] <= 5) j++;
		if (i == 0) {dp[j][1] = j - i + 1; continue;}
		for (int x=0; x<=k; x++) dp[i][x] = max(dp[i][x], dp[i-1][x]);
		for (int x=0; x<k; x++) {
			dp[j][x+1] = max(dp[j][x+1], dp[i-1][x] + (j - i + 1));
		}
	}
	int ans = 0;
	for (int i=1; i<=k; i++) ans = max(ans, dp[n-1][i]);
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/