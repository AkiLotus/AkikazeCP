#include <bits/stdc++.h>
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
	ll n, p, q, r; cin >> n >> p >> q >> r;
	vector<vector<ll>> dp(n, vector<ll>(3, 0));
	vector<ll> a(n);
	for (ll i=0; i<n; i++) {
        cin >> a[i];
        if (i == 0) {
			dp[i][0] = p*a[i];
			dp[i][1] = (p+q)*a[i];
			dp[i][2] = (p+q+r)*a[i];
        }
        else {
			dp[i][0] = max(dp[i-1][0], p*a[i]);
			dp[i][1] = max(dp[i-1][1], dp[i][0] + q*a[i]);
			dp[i][2] = max(dp[i-1][2], dp[i][1] + r*a[i]);
        }
        //for (ll j=0; j<3; j++) cout << dp[i][j] << " "; cout << endl;
	}
	cout << dp[n-1][2];
	return 0;
}