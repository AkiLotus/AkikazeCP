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
	cin >> n; a.resize(n+1, 0);
	for (int i=1; i<=n; i++) cin >> a[i];
}

void Solve() {
	long long ans = 0;
	for (int i=1; i<=n; i++) {
		if (a[i-1] == a[i]) continue;
		if (a[i-1] < a[i]) ans += 1LL * (a[i] - a[i-1]) * (n - a[i] + 1);
		if (a[i-1] > a[i]) ans += 1LL * (a[i-1] - a[i]) * a[i];
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