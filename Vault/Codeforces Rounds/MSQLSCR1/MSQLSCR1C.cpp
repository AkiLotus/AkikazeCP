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
	char token = 'b';
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) cin >> a[i];
	int bob = 0, alice = 0;
	int current = a[0];
	for (int i=1; i<n; i++) {
        if (a[i] < current) {
            if (token == 'b') {
                token = 'a'; bob += current;
            }
            else {
                token = 'b'; alice += current;
            }
            current = 0;
        }
        current += a[i];
	}
	if (token == 'b') bob += current;
	else alice += current;
	cout << alice << " " << bob;
	return 0;
}
