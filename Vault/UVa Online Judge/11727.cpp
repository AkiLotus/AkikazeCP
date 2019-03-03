#include <iostream>
using namespace std;

long long strtoll(string z) {
	long long result = 0, sign = 1, i = 0;
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
	int t, cas = 0;
	cin >> t;
	while (t-- > 0) {
        int a, b, c, ans;
        cin >> a >> b >> c;
        if (a < b) {
            if (b < c) ans = b;
            else {
                if (a < c) ans = c;
                else ans = a;
            }
        }
        else {
            if (b > c) ans = b;
            else {
                if (a > c) ans = c;
                else ans = a;
            }
        }
        cout << "Case " << ++cas << ": " << ans << endl;
	}
	return 0;
}
