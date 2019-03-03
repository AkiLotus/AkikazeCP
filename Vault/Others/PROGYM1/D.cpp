#include <iostream>
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
	ll n, m, k;
	cin >> n >> m >> k;
	if (k * 3 < n + m) cout << "-1";
	else {
        ll sum = n + m;
        ll three = (sum - k) / 2;
        ll two = 1;
        if (sum - three * 3 == k - three) two = 0;
        ll ans = max(0ll, two*2+three*3-n);
        cout << ans;
	}
	return 0;
}
