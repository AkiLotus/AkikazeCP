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
	while (t-- > 0) {
        string z; cin >> z;
        if (z.size() == 5) cout << "3\n";
        else {
            if ((z[0] == 'o' && z[1] == 'n') || (z[2] == 'e' && z[1] == 'n') || (z[0] == 'o' && z[2] == 'e')) cout << "1\n";
            else cout << "2\n";
        }
	}
	return 0;
}
