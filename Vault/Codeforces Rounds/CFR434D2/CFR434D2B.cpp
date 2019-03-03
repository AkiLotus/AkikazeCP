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
    int n, m; cin >> n >> m;
	pair<int, int> a[m];
	for (int i=0; i<m; i++) cin >> a[i].first >> a[i].second;
	int ans = -1;
	for (int i=1; i<=100; i++) {
        bool valid = true;
        for (int j=0; j<m; j++) {
            if ((a[j].first-1)/i!=a[j].second-1) {
                valid = false;
                break;
            }
        }
        if (!valid) continue;
        int tmp = (n - 1) / i + 1;
        if (ans != -1 && tmp != ans) {
            cout << "-1"; return 0;
        }
        ans = tmp;
	}
	cout << ans;
	return 0;
}
