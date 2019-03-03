#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

const long long Mod = 1000000007LL;

int n; vector<int> a;
vector<vector<int>> Multiplier;
vector<vector<pair<int, int>>> AccumulatedSums;

void Input() {
	cin >> n; a.resize(n+1);
	Multiplier.resize(n+1);
	AccumulatedSums.resize(n+1);
	AccumulatedSums[0].push_back(make_pair(1, 0));
	for (int i=1; i<=n; i++) cin >> a[i];
}

void Solve() {
	for (int i=1; i<=n; i++) {
		int x = a[i];
		for (int d=1; d<=sqrt(x); d++) {
			if (x % d != 0) continue;
			if (d <= n) Multiplier[d].push_back(i);
			if (d * d != x && x/d <= n) Multiplier[x/d].push_back(i);
		}
	}
	int ans = 0;
	for (int i=1; i<=n; i++) {
		if (Multiplier[i].empty()) break;
		int pointer = 0; int prefixsum = 0;
		for (auto id: Multiplier[i]) {
			while (pointer < AccumulatedSums[i-1].size() && AccumulatedSums[i-1][pointer].second < id) {
				prefixsum += AccumulatedSums[i-1][pointer].first; prefixsum %= Mod; pointer++;
			}
			ans += prefixsum; ans %= Mod; AccumulatedSums[i].push_back(make_pair(prefixsum, id));
		}
	}
	cout << ans;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/