#include <iostream>
#include <cmath>
#include <map>
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
    map<long long, long long> cube;
    for (long long i=0; i<2000000; i++) cube[i*i*i] = i;
	int n;
	cin >> n;
	while (n-- > 0) {
        long long a, b;
        cin >> a >> b;
        long long z = a * b;
        long long tmp = cube[z];
        if (tmp * tmp * tmp != z) cout << "No\n";
        else {
            if (a % tmp == 0 && b % tmp == 0) cout << "Yes\n";
            else cout << "No\n";
        }
	}
	return 0;
}
