#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

const int Inf = 1000000000;
int n, m; vector<int> a, cnt;
vector<vector<vector<int>>> dp;

int seek(int i, int j, int k) {
	if (i == 0) return ((cnt[0] - j - k) / 3);
	if (i == 1) return ((cnt[1] - j - k) / 3 + seek(i-1, 0, j));
	if (dp[i][j][k] != -1) return dp[i][j][k];
	int Min = max(min(min(cnt[i-2], cnt[i-1] - j), cnt[i] - j - k), 0);
	int res = 0;
	for (int z=0; z<=min(Min, 2); z++) res = max(res, z + (cnt[i] - j - k - z) / 3 + seek(i-1, z, j));
	dp[i][j][k] = res; return res;
}

void Input() {
	cin >> n >> m; a.resize(n); cnt.resize(m);
	dp.resize(m, vector<vector<int>>(3, vector<int>(3, -1)));
	for (auto &z: a) {cin >> z; z--; cnt[z]++;}
}

void Solve() {
	cout << seek(m-1, 0, 0);
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/
