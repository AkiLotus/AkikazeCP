#include <iostream>
#include <vector>
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
	int n; cin >> n;
	vector<int> a(n, 0);
	int sum = 0;
	for (int i=0; i<2*n; i++) {
        int z; cin >> z;
        sum += z; a[i/2] += z;
	}
	int ans = 0;
	for (int i=0; i<n; i++) {
        ans += abs(a[i]*n-sum);
	}
	double z = (double)ans / n;
	cout << z;
	return 0;
}
