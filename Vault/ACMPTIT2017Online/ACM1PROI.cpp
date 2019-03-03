#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int n, min = 0, max = 0, m, haha, huhu, dem = 0;
		cin >> n;
		int a[n];
		bool fit[n] = {false};
		for (int i=0; i<n; i++) cin >> a[i];
		sort(a, a+n);
		cin >> m;
		while (m-- > 0) {
			int l, r;
			cin >> l >> r;
			int bl = lower_bound(a, a+n, l) - a;
			int br = upper_bound(a, a+n, r) - a - 1;
			for (int i=bl; i<=br; i++) fit[i] = true;
		}
		for (int i=0; i<n; i++)
			if (fit[i]) dem++;
		cout << dem << endl;
	}
	return 0;
}