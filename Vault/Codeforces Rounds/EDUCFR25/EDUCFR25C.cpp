#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	int solved = upper_bound(a, a+n, k) - a;
	if (solved == n) cout << 0;
	else {
        int tmp = k;
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (a[i] > 2*tmp) {
                    ans++;
                    i--;
                    tmp = 2*tmp;
            }
            else if (a[i] > tmp) tmp = a[i];
        }
        cout << ans;
	}
	return 0;
}
