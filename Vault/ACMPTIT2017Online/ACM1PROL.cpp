#include <iostream>
using namespace std;

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	int a[n], tmp[n], b[m];
	for (int i=0; i<n; i++) {
		cin >> a[i];
		tmp[i] = a[i];
	}
	for (int i=0; i<m; i++) b[i] = i+1;
	while (q-- > 0) {
		int cmd, param1, param2;
		cin >> cmd >> param1 >> param2;
		if (cmd == 1) {
			a[param1-1] = param2;
		}
		else {
			if (cmd == 2) {
				int res = 0;
				for (int i=0; i<n; i++) {
					if (a[i] >= param2) continue;
					if (a[i] + m < param1) continue;
					if (a[i] < param1) {
						int excluded = param1 - a[i] - 1;
						res += min(m, (param2 - a[i])) - excluded;
					}
					else {
						res += min(m, (param2 - a[i]));
					}
				}
				cout << res << endl;
			}
		}
	}
	return 0;
}