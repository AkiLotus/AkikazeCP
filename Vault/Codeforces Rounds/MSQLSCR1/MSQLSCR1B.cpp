#include <iostream>
#include <cmath>
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
	long long n;
	cin >> n;
	long long baseline = sqrt(n);
	if (baseline * baseline == n) cout << 4 * baseline;
	else {
        long long ans = 4 * baseline;
        if (n - baseline * baseline <= baseline) ans += 2;
        else ans += 4;
        cout << ans;
	}
	return 0;
}
