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

int foo (int z) {
    int res = 0;
    while (z > 0) {
        res += z % 10;
        z /= 10;
    }
    return res;
}

int main() {
	int n;
	cin >> n;
	while (n != 0) {
        int z = n;
        while (z > 9) z = foo(z);
        cout << z << endl;
        cin >> n;
	}
	return 0;
}
