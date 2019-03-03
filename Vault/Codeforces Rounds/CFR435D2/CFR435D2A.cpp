#include <iostream>
#include <vector>
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
	int n, x;
	cin >> n >> x;
	vector<bool> visited(111, false);
	int z;
	while (n-- > 0) {
        cin >> z;
        visited[z] = true;
	}
	int ans = 0;
	if (visited[x]) ans++;
	for (int i=0; i<x; i++) {
        if (!visited[i]) ans++;
	}
	cout << ans;
	return 0;
}
