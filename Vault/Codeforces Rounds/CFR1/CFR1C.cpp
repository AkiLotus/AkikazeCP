#include <iostream>
#include <cmath>
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
	double x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	double a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	double b = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
	double c = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	double p = (a + b + c) / 2;
	double ans = sqrt(p * (p - a) * (p - b) * (p - c)) * 2;
	cout << ans;
	return 0;
}
