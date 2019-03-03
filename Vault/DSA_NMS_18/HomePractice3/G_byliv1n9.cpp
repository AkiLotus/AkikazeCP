#include <bits/stdc++.h>
using namespace std;
const int nn = 1e5 + 8;
const int mod = 1000;

int f[] = {0, 1, 4, 11, 25, 57, 120, 246, 503, 1015, 2039, 4087, 8182, 16373, 32763, 65534};

int Pow(int a, int x) {
    if (x == 0) return 1;
    int d = Pow(a, x >> 1);
    d = (d * d) % mod;
    if (x & 1) return (d * a) % mod;
    return d;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        if (n <= 16) cout << f[n - 1] % 1000 << endl;
        else cout << Pow(2, n) << endl;
    }
}
