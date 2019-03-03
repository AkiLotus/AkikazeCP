#include <bits/stdc++.h>
using namespace std;

int bit(int state, int i) {
    return ((state >> i) & 1);
}

int ok(int state, int n) {
    for (int i = 1; i < n; i++) {
        if (bit(state, i) && bit(state, i - 1)) return 1;
    }
    for (int len = 1; len * 3 <= n; len++) {
        for (int j = 0; j + len * 3 - 1 < n; j++) {
            bool ok = true;
            for (int k = j; k <= j + len - 1; k++) {
                int x = bit(state, k);
                int y = bit(state, k + len);
                int z = bit(state, k + len * 2);
                if (x != y || y != z || z != x) {
                    ok = false;
                    break;
                }
            }
            if (ok) return 1;
        }
    }
    return 0;
}

int modPow(int a, int b, int MOD) {
	if (b == 1) return (a % MOD);
	if (b == 0) return 1;
	int tmp = modPow(a, b/2, MOD);
	if (b % 2 == 0) return ((tmp * tmp) % MOD);
	return ((((tmp * tmp) % MOD) * a) % MOD);
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n > 20) {cout << modPow(2, n, 1000) << endl; continue;}
        int res = 0;
        for (int state = 0; state < (1 << n); state++) {
            res += ok(state, n);
        }
        cout << (res % 1000) << endl;
    }
}