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
        int a, b, c;
        cin >> a >> b >> c;
        cout << "Case " << ++cas << ": ";
        if (a > 20 || b > 20 || c > 20) cout << "bad\n";
        else cout << "good\n";
	}
	return 0;
}
