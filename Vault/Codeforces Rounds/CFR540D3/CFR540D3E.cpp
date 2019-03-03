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

int n, k;

void Input() {
	cin >> n >> k;
}

void Solve() {
	if (1LL * k * (k - 1) < 1LL * n) {cout << "NO\n"; return;}
	cout << "YES\n"; int cnt = 0;
	for (int x=1; x<k; x++) {
		if (cnt == n) break;
		for (int i=0; i<k; i++) {
			if (cnt == n) break;
			int j = (i + x) % k; cnt++;
			cout << (i+1) << " " << (j+1) << endl;
		}
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/