#include <iostream>
using namespace std;

typedef long long ll;

ll strtoll(string z) {
	ll result = 0, sign = 1, i = 0;
	if (z[0] == '-') {
		i = 1; sign = -1;
	}
	for (; i<z.size(); i++) {
		result *= 10;
		result += (z[i] - '0');
	}
	return result * sign;
}

int main() {
	int a, b, f, k;
	int ans = 0;
	cin >> a >> b >> f >> k;
    int fuel = b;
    for (int i=0; i<k; i++) {
        if (i == k-1) {
            if (i % 2 == 0) {
                if (fuel < f) {
                    cout << -1; return 0;
                }
            }
            else {
                if (fuel < a-f) {
                    cout << -1; return 0;
                }
            }
            if (fuel < a) {
                fuel = b; ans++;
            }
            if (i % 2 == 0) fuel -= (a - f);
            else fuel -= f;
            if (fuel < 0) {
                cout << -1; return 0;
            }
        }
        else if (i % 2 == 0) {
            fuel -= f;
            if (fuel < 0) {
                cout << -1; return 0;
            }
            if (fuel < 2 * (a - f)) {
                ans++; fuel = b;
            }
            fuel -= (a - f);
            if (fuel < 0) {
                cout << -1; return 0;
            }
        }
        else {
            fuel -= (a - f);
            if (fuel < 0) {
                cout << -1; return 0;
            }
            if (fuel < 2 * f) {
                ans++; fuel = b;
            }
            fuel -= f;
            if (fuel < 0) {
                cout << -1; return 0;
            }
        }
        //cout << "fuel left = " << fuel << endl;
    }
    cout << ans;
	return 0;
}
