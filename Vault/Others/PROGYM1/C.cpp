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
	int n, m, x, y, z;
	cin >> n >> m >> x >> y >> z;
	if (m > x + y + z) {cout << "No"; return 0;}
	if (m < x) {x -= m; m = 0;}
	else {
        m -= x; x = 0;
        if (m < y) {y -= m; m = 0;}
        else {
            m -= y; y = 0;
            z -= m;
        }
    }
    //cout << x << " " << y << " " << z << endl;
	bool ok = false;
	for (int i=0; i<=max(x+y+z,0); i++) {
        for (int j=0; j<=max(y+z-max(i-x, 0),0); j++) {
            for (int k=0; k<=max(z-max(i+j-x-y, 0),0); k++) {
                //cout << "i = " << i << " | j = " << j << " | k = " << k << endl;
                if (i + 2 * j + 3 * k == n) {
                    ok = true; break;
                }
            }
            if (ok) break;
        }
        if (ok) break;
	}
	if (ok) cout << "Yes";
	else cout << "No";
	return 0;
}
