#include <bits/stdc++.h>
#define N 1000006
using namespace std;

int a[N], c[N], d[N], i, j, k, m, n;

void input() {
	cin >> n;
	for (i = 0; i < n; i++) cin >> a[i];
}

void solve() {
	d[n] = -1000000000;
	c[n] = -1000000000;
	for (i = n-1; i >= 0; i--) {
		c[i] = max(c[i+1], a[i]+i);
		d[i] = max(d[i+1], -a[i]+i);
	}
	int ans = -1000000000;
	for (i = 0; i < n; i++) ans = max(max(ans, -a[i]-i+c[i]), a[i]-i+d[i]);
	cout << ans << endl;
}

main() {
		//freopen("input.txt", "r", stdin);
	   input();
	   solve();
}


