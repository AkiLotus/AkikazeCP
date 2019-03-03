#include <iostream>
#include <algorithm>
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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	while (a != 0 || b != 0 || c != 0 || d != 0) {
        a *= 9; b *= 9; c *= 9; d *= 9;
        int ans = 1080;
        if (a > b) ans += (a - b);
        else ans += (360 - (b - a));
        if (c > b) ans += (c - b);
        else ans += (360 - (b - c));
        if (c > d) ans += (c - d);
        else ans += (360 - (d - c));
        cout << ans << endl;
        cin >> a >> b >> c >> d;
	}
	return 0;
}
