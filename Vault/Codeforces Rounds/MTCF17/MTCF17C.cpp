#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

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
	ll n, m, k, x, ans = 0;
	cin >> n >> m;
	vector<ll> adj[n+1];
	for (ll i=1; i<n; i++) {
        ll x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
	}
	cin >> k >> x;
	if (k == 1) {
        if (m == 1) cout << "0";
        else cout << "1";
        return 0;
	}
	else {

	}
	return 0;
}
