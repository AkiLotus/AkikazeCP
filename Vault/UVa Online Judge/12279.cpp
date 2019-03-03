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
	while (t != 0) {
        int bal = 0;
        while (t-- > 0) {
            int p; cin >> p;
            if (p == 0) bal--; else bal++;
        }
        cout << "Case " << ++cas << ": " << bal << endl;
        cin >> t;
	}
	return 0;
}
