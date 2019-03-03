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

int n; vector<int> a;

void Input() {
	cin >> n; a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	if (n == 1) {cout << "1\n"; return;}
	if (n == 2) {cout << "0\n"; return;}
	int ans = 0;
	vector<vector<int>> prs(n, vector<int>(2, 0)); prs[0][0] = a[0]; prs[1][1] = a[1];
	vector<vector<int>> sus(n, vector<int>(2, 0)); sus[n-1][(n-1)%2] = a[n-1]; sus[n-2][(n-2)%2] = a[n-2];
	for (int i=2; i<n; i++) prs[i][i % 2] = prs[i-2][i % 2] + a[i];
	for (int i=n-3; i>=0; i--) sus[i][i % 2] = sus[i+2][i % 2] + a[i];
	for (int i=0; i<n; i++) {
		int sum1 = 0, sum2 = 0;
		if (i - 1 >= 0) sum1 += prs[i-1][(i-1) % 2];
		if (i - 2 >= 0) sum2 += prs[i-2][(i-2) % 2];
		if (i + 1 < n) sum2 += sus[i+1][(i+1) % 2];
		if (i + 2 < n) sum1 += sus[i+2][(i+2) % 2];
		ans += (sum1 == sum2);
	}
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