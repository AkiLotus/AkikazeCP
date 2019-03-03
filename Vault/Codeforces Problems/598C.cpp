#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N5 = 100005;
pair <long double, int> angles [N5];
signed main () {
	int n; cin >> n;
	for (int i = 0; i < n; i ++) {
		int x, y; cin >> x >> y;
		angles [i] = make_pair (atan2 (y, x), i);
	}
	sort (angles, angles + n);
	long double m = 1000, e; int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; i ++) {
		e = angles[(i+1)%n].first - angles[i].first;
		if (e < 0) e += 2 * acos (-1.0);
		if (e < m) m = e, ans1 = angles[i].second, ans2 = angles[(i+1)%n].second;
	}
	cout << ans1 + 1 << " " << ans2 + 1;
}
