#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define y0 takethescythe
#define y1 reapyourenemies
#define yn feedontheirflesh
#define j1 ascendthroughtheirblood

#define endl '\n'
typedef long long i64;
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

const int Mod = 1000000007;
int R, C;

int modPow(int a, int b, int res = 1) {
	while (b > 0) {
		if (b & 1) res = (1LL * res * a) % Mod;
		b >>= 1; a = (1LL * a * a) % Mod;
	}
	return res;
}

void Input() {
	cin >> R >> C;
}

void Solve() {
	cout << (1LL * modPow(3, R+C) * modPow(2, R*C)) % Mod << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/