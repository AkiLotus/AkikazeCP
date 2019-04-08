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

int n; vector<int> a;

void Input() {
	cin >> n; a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	vector<long long> dp(n, a[0] / 3), sum(n, a[0]);
	for (int i=1; i<n; i++) sum[i] = sum[i-1] + a[i];
	for (int i=1; i<n; i++) {
		long long rem = sum[i-1] - dp[i-1] * 3;
		long long removable = min(rem, 1LL * a[i] / 2);
		dp[i] = dp[i-1] + removable + (a[i] - removable * 2) / 3;
	}
	cout << dp[n-1] << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/