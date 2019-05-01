#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	char str[n];
	int hashpos[m];
	int hashcount = 0;
	for (int i=0; i<n; i++) {
		cin >> str[i];
		if (str[i] == '#') hashpos[hashcount++] = i;
	}
	string key[m];
	for (int i=0; i<m; i++) {
		cin >> key[i];
		sort(key[i].begin(), key[i].end());
	}
	x--;
	for (int i=0; i<m; i++) {
		str[hashpos[hashcount - 1]] = key[hashcount - 1][x % k];
		hashcount--;
		x /= k;
	}
	for (int i=0; i<n; i++) cout << str[i];
	return 0;
}