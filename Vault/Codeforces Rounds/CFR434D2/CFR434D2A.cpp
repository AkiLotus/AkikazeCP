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
	long long n, k, two = 0, five = 0;
	cin >> n >> k;
	long long tmp = n;
	while (tmp % 2 == 0) {
        tmp /= 2;
        two++;
	}
	while (tmp % 5 == 0) {
        tmp /= 5;
        five++;
	}
	long long ans = n;
	for (long long i=0; i<k-two; i++) ans *= 2;
	for (long long i=0; i<k-five; i++) ans *= 5;
	cout << ans;
	return 0;
}
