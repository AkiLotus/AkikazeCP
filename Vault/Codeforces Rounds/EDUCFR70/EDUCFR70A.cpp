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

string x, y;

void Input() {
	cin >> x >> y;
}

void Solve() {
	int first1 = y.size() - 1;
	while (y[first1] == '0') first1--;
	for (int k=0; k<111111; k++) {
		if (x.size()-1-(y.size()-1-(first1-k)) < 0) break;
		if (x[x.size()-1-(y.size()-1-(first1-k))] == '1') {
			cout << k << endl;
			return;
		}
	}
	cout << "-1\n";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/