#include <iostream>
#include <vector>
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
	vector<bool> visited(101, false);
	int n; string z; cin >> n >> z;
	int ans = -1;
	while (n--) {
        string q; int num; cin >> q >> num;
        if (q == z) {
            cout << num; return 0;
        }
        bool ok = true;
        for (int i=0; i<8; i++) {
            if (q[i] != '?' && q[i] != z[i]) {
                ok = false; break;
            }
        }
        if (ok) ans = max(ans, num);
        visited[num] = true;
	}
	if (ans > -1) cout << ans;
	else {
        for (int i=100; i>=0; i--) {
            if (!visited[i]) {
                cout << i; return 0;
            }
        }
	}
	return 0;
}
