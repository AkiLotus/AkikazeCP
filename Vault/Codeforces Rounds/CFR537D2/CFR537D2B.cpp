#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, k, m; vector<int> a;

void Input() {
	cin >> n >> k >> m; a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	sort(a.begin(), a.end());
	vector<long long> suffixSum(n, a[n-1]);
	for (int i=n-2; i>=0; i--) suffixSum[i] = suffixSum[i+1] + a[i];
	long double ans = 0.0L;
	for (int del=0; del<n; del++) {
		if (del > m) break;
		long long inc = min((long long)m - del, 1LL * (n - del) * k);
		long long sum = suffixSum[del] + inc;
		ans = max(ans, (long double)sum / (n - del));
	}
	cout << fixed << setprecision(18) << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
  *  #Team4T Primary Flagship - Salvation  *
  \******************************************/
