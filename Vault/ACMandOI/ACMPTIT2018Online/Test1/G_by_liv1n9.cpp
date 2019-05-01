#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int nn = 1e6 + 8;
const ll mod = 1e9 + 7;

ll t[nn << 2], f1[nn << 2], f2[nn << 2];
ll n, m;
ll sum[nn];
ll query[2][nn];

void init(int k, int l, int r) {
    if (l == r) {
        t[k] = (m * sum[n - 1] + n * r) % mod;
        return;
    }
    int g = (l + r) >> 1;
    init(k << 1, l, g);
    init(k << 1 ^ 1, g + 1, r);
    t[k] = (t[k << 1] + t[k << 1 ^ 1]) % mod;
}

void lazy(int k, ll l, ll r) {
    t[k] = (t[k] + f1[k] * (sum[r] - sum[l - 1]) + f2[k] * (r - l + 1)) % mod;
    if (l < r) {
        f1[k << 1] = (f1[k << 1] + f1[k]) % mod;
        f1[k << 1 ^ 1] = (f1[k << 1 ^ 1] + f1[k]) % mod;
        f2[k << 1] = (f2[k << 1] + f2[k]) % mod;
        f2[k << 1 ^ 1] = (f2[k << 1 ^ 1] + f2[k]) % mod;
    }
    f1[k] = f2[k] = 0;
}

void update(int k, int l, int r, int x, int y, ll i, ll v) {
    lazy(k, l, r);
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
        t[k] = (t[k] * v) % mod;
        if (l < r) {
            f1[k << 1] = (f1[k << 1] + v - 1) % mod;
            f1[k << 1 ^ 1] = (f1[k << 1 ^ 1] + v - 1) % mod;
            ll v2 = (((i - 1) * (v - 1)) % mod) * m;
            f2[k << 1] = (f2[k << 1] + v2) % mod;
            f2[k << 1 ^ 1] = (f2[k << 1 ^ 1] + v2) % mod;
        }
        return;
    }
    int g = (l + r) >> 1;
    update(k << 1, l, g, x, y, i, v);
    update(k << 1 ^ 1, g + 1, r, x, y, i, v);
    t[k] = (t[k << 1] + t[k << 1 ^ 1]) % mod;
}

ll get(ll k, ll l, ll r, int i) {
    lazy(k, l, r);
    if (l > i || r < i) return 0;
    if (l == i && r == i) return t[k];
    int g = (l + r) >> 1;
    return (get(k << 1, l, g, i) + get(k << 1 ^ 1, g + 1, r, i)) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    int k;
    cin >> n >> m >> k;
    for (int i = 1; i <= max(n, m); i++) {
        sum[i] = (sum[i - 1] + i) % mod;
        query[0][i] = query[1][i] = 1;
    }
    init(1, 1, m);
    while (k--) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        query[c == 'S'][x] = (query[c == 'S'][x] * y) % mod;
    }
    for (int i = 1; i <= n; i++) {
        update(1, 1, m, 1, m, i, query[0][i]);
    }
    ll res = 0;
    for (int i = 1; i <= m; i++) {
        res = (res + query[1][i] * get(1, 1, m, i)) % mod;
    }
    if (res < 0) res += mod;
    cout << res;
}