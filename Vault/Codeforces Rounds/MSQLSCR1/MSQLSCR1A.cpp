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
	int n;
	int maximum = -1;
	cin >> n;
	while (n-- > 0) {
        int x;
        cin >> x;
        maximum = max(maximum, x);
	}
	if (maximum <= 25) cout << 0;
	else cout << maximum - 25;
	return 0;
}
