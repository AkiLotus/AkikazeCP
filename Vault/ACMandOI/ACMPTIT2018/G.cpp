#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nn = 1e5 + 8;

ll a[nn], b[nn];
int p[nn];
int n;

ll calc() {
	ll res = 0;
	int pre = 1;
	for (int i = 2; i <= n; i++) {
		res += a[p[i]] * b[pre];
		pre = max(pre, p[i]);
		if (pre == n) break;
	}
	return res;
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &b[i]);
		}
		ll tmp = 8e18;
		int x = 0;
		for (int i = 2; i < n; i++) {
			if (tmp > b[1] * a[i] + b[i] * a[n]) {
				tmp = b[1] * a[i] + b[i] * a[n];
				x = i;
			}
		}
		p[2] = x;
		p[3] = n;
		ll res = 8e18;
		printf("%lld\n", calc());
	}
}