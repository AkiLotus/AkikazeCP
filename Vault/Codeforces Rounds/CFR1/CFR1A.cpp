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
	ll n, m, k;
	cin >> n >> m >> k;
	ll z1 = n / k, z2 = m / k;
	if (n % k != 0) z1++;
	if (m % k != 0) z2++;
	cout << z1 * z2;
	return 0;
}
