#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swaps(long long &a, long long &b) {
    long long tmp = a;
    a = b; b = tmp;
}

long long gcd(long long a, long long b) {
    while (true) {
        if (a < b) swaps(a, b);
        if (a % b == 0) return b;
        a %= b;
    }
    return 1;
}

void shrink(long long &a, long long &b) {
    long long z = gcd(a, b);
    a /= z; b /= z;
}

int main() {
	//freopen("data.in", r, stdin);
    //freopen("ketqua.out", w, stdout);
    int t;
    cin >> t;
    while (t-- > 0) {
        long long a[3];
        for (int i=0; i<3; i++) cin >> a[i];
        sort(a, a+3);
        long long q1 = (a[2] + a[1]), r1 = a[0];
        long long q2 = a[0], r2 = (a[2] - a[1]);
        if (q1 == 0 || q2 == 0 || r2 == 0) {
            cout << "NO\n";
            continue;
        }
        else {
            shrink(q1, r1);
            shrink(q2, r2);
            if (q1 == q2 && r1 == r2) cout << "YES\n";
            else cout << "NO\n";
        }
    }
	return 0;
}
