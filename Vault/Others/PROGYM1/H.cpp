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
	vector<int> a(2*n, 0);
	vector<bool> visited(2*n, false);
	vector<int> result(2*n);
	int found = 0;
	int sum = 0;
	for (int i=0; i<2*n; i++) {
        cin >> a[i];
        sum += a[i];
	}
	for (int i=0; i<2*n; i++) {
        if (visited[i]) continue;
        int tmp = 999999999, pos = -1;
        visited[i] = true;
        for (int j=0; j<2*n; j++) {
            if (visited[j]) continue;
            if (abs((a[i] + a[j])*n - sum) < tmp) {
                tmp = abs((a[i] + a[j])*n - sum);
                pos = j;
            }
        }
        result[found*2] = a[i]; result[found*2+1] = a[pos];
        found++;
        visited[pos] = true;
	}
	for (int i=0; i<2*n; i++) cout << result[i] << " ";
	return 0;
}
