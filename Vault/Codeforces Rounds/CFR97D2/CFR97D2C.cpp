#include <iostream>
#include <algorithm>
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
	cin >> n;
	int a[n], res[n];
	res[0] = 1;
	for (int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
    for (int i=1; i<n; i++) res[i] = a[i-1];
    if (a[n-1] == 1) res[n-1] = 2;
    for (int i=0; i<n; i++) cout << res[i] << " ";
	return 0;
}
