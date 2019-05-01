#include <bits/stdc++.h>
using namespace std;

int f[2000][2000];

void solution() {
	int n;
	int a[2000];
	memset(f, 0, sizeof(f));
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		f[1][i] = a[i];
	}
	for (int k = 2; k <= n; k++) {
		for (int i = 0; i <= n - k; i++) {
			f[k][i] = min(f[k-1][i], a[i+k-1]);
		} 
	}
	for (int k = 1; k <= n; k++) {
		int res = 0;
		for (int i = 0; i <= n - k; i++) {
			res = max(res, f[k][i]);
		}
		cout << res << " ";
	}
	cout << endl;
	
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solution();
	}
}