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

const int Mod = 998244353;
int n, k; vector<int> a;

int modPow(int a, int b) {
	int res = 1;
	while (b > 0) {
		if (b & 1) {res = (1LL * res * a) % Mod;}
		b >>= 1; a = (1LL * a * a) % Mod;
	}
	return res;
}

void Input() {
	cin >> n >> k; a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	vector<int> dp(n, 1);
	int ans = 1;
	for (int i=0; i<n; i+=2) {
		if (a[i] > 0) continue;
		int j = i; while (j+2 < n && a[j+2] == -1) j += 2;
		if (i < 2 && j >= n-2) {
			int tmp = k;
			for (int x=1; x<(j-i)/2+1; x++) tmp = (1LL * tmp * (k - 1)) % Mod;
			ans = (1LL * ans * tmp) % Mod;
		}
		else if (i < 2 || j >= n-2) {
			int tmp = 1;
			for (int x=0; x<(j-i)/2+1; x++) tmp = (1LL * tmp * (k - 1)) % Mod;
			ans = (1LL * ans * tmp) % Mod;
		}
		else {
			int diff = k - 2 + (a[i-2] == a[j+2]), same = (a[i-2] != a[j+2]);
			for (int x=1; x<(j-i)/2+1; x++) {
				int nextsame = diff;
				int nextdiff = ((1LL * same * (k - 1)) % Mod + (1LL * diff * (k - 2)) % Mod) % Mod;
				same = nextsame; diff = nextdiff;
			}
			ans = (1LL * ans * diff) % Mod;
		}
		i = j;
	}
	for (int i=1; i<n; i+=2) {
		if (a[i] > 0) continue;
		int j = i; while (j+2 < n && a[j+2] == -1) j += 2;
		if (i < 2 && j >= n-2) {
			int tmp = k;
			for (int x=1; x<(j-i)/2+1; x++) tmp = (1LL * tmp * (k - 1)) % Mod;
			ans = (1LL * ans * tmp) % Mod;
		}
		else if (i < 2 || j >= n-2) {
			int tmp = 1;
			for (int x=0; x<(j-i)/2+1; x++) tmp = (1LL * tmp * (k - 1)) % Mod;
			ans = (1LL * ans * tmp) % Mod;
		}
		else {
			int diff = k - 2 + (a[i-2] == a[j+2]), same = (a[i-2] != a[j+2]);
			for (int x=1; x<(j-i)/2+1; x++) {
				int nextsame = diff;
				int nextdiff = ((1LL * same * (k - 1)) % Mod + (1LL * diff * (k - 2)) % Mod) % Mod;
				same = nextsame; diff = nextdiff;
			}
			ans = (1LL * ans * diff) % Mod;
		}
		i = j;
	}
	for (int i=0; i<n-2; i++) {
		if (a[i] != -1 && a[i+2] != -1 && a[i] == a[i+2]) ans = 0;
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