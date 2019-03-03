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

int sum[300007];

int main() {
	int n, k;
	cin >> n >> k;
	sum[0] = 0;
	for (int i=1; i<300007; i++) sum[i] = sum[i-1] + i;
	int base = upper_bound(sum, sum+300007, k) - sum;
	if ((k == sum[base-1] && n < k) || (sum[base-1] > k && n < k+1)) cout << "Impossible";
	else {
        int exceed = n - base;
        if (sum[base-1] < k) exceed--;
        cout << k << endl;
        cout << exceed << " " << base << endl;
        for (int i=0; i<exceed; i++) cout << "()";
        if (sum[base-1] == k) {
            for (int i=0; i<base; i++) cout << "(";
            for (int i=0; i<base; i++) cout << ")";
        }
        else {
            int handling = k - sum[base-1];
            for (int i=0; i<handling; i++) cout << "(";
            cout << "()";
            for (int i=0; i<base-handling; i++) cout << "(";
            for (int i=0; i<base; i++) cout << ")";
        }
	}
	return 0;
}
