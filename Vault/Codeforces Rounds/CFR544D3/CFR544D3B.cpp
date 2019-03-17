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

int n, k; vector<int> d, cnt;

void Input() {
	cin >> n >> k; d.resize(n); cnt.resize(k);
	for (auto &z: d) {cin >> z; cnt[z % k]++;}
}

void Solve() {
	int ans = 0;
	for (int i=1; i*2<k; i++) {
		ans += min(cnt[i], cnt[k - i]);
	}
	ans += cnt[0] / 2;
	if (k % 2 == 0) ans += cnt[k / 2] / 2;
	cout << ans * 2 << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/