#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, k, A, B; vector<int> a;

int heroCount(int L, int R) {
	int x = lower_bound(a.begin(), a.end(), L) - a.begin();
	int y = upper_bound(a.begin(), a.end(), R) - a.begin();
	return (y - x);
}

long long solve(int L, int R) {
	int cnt = heroCount(L, R);
	if (cnt == 0) return A;
	long long res = 1LL * B * (R - L + 1) * cnt;
	if (L == R) return res;
	return min(res, solve(L, (L+R)/2+0) + solve((L+R)/2+1, R));
}

void Input() {
	cin >> n >> k >> A >> B; a.resize(k);
	for (auto &z: a) {cin >> z; z--;}
}

void Solve() {
	sort(a.begin(), a.end());
	int lim = 1 << n;
	cout << solve(0, lim-1) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
  *  #Team4T Primary Flagship - Salvation  *
  \******************************************/
