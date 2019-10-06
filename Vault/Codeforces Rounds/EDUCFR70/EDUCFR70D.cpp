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

int n;
vector<int> nC2(1, 0);

void Input() {
	cin >> n;
}

void Solve() {
	int three = upper_bound(nC2.begin(), nC2.end(), n) - nC2.begin() - 1;
	n -= nC2[three];
	if (n == 0) {
		cout << "1";
		for (int i=0; i<three; i++) cout << "3";
		cout << "7\n";
	}
	else {
		cout << "133";
		for (int i=0; i<n; i++) cout << "7";
		for (int i=0; i<three-2; i++) cout << "3";
		cout << "7\n";
	}
}

int main(int argc, char* argv[]) {
	for (int i=1; 2000000000/i>=i; i++) {
		nC2.push_back(i * (i - 1) / 2);
	}
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/