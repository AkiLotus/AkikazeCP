#include <iostream>
using namespace std;

int main() {
	long long l, r, x, y, k;
	cin >> l >> r >> x >> y >> k;
	for (long long i=x; i<=y; i++) {
		if (i * k >= l && i * k <= r) {cout << "YES"; return 0;}
	}
	cout << "NO"; return 0;
}
