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
	int t;
	cin >> t;
	while (t != 0) {
        int x, y;
        cin >> x >> y;
        while (t-- > 0) {
            int a, b;
            cin >> a >> b;
            if (a == x || b == y) cout << "divisa\n";
            else {
                if (b < y) cout << "S"; else cout << "N";
                if (a < x) cout << "O"; else cout << "E";
                cout << endl;
            }
        }
        cin >> t;
	}
	return 0;
}
