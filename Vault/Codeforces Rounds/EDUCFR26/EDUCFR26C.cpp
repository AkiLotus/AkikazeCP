#include <iostream>
#include <algorithm>
using namespace std;

struct sign {
	int x, y;
};

bool signSort(sign a, sign b) {
	if (a.x < b.x) return true;
	if (a.x == b.x && a.y < b.y) return true;
	return false;
}

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	sign input[n];
	for (int i=0; i<n; i++) {
		cin >> input[i].x >> input[i].y;
		if (input[i].x > input[i].y) {
			int tmp = input[i].x;
			input[i].x = input[i].y;
			input[i].y = tmp;
		}
	}
	sort(input, input+n, signSort);
	int ans = 0;
	for (int i=n-1; i>0; i--) {
		if ((input[i].x > a || input[i].y > a) && (input[i].x > b || input[i].y > b)) continue;
		for (int j=0; j<i; j++) {
			if ((input[j].x > a || input[j].y > a) && (input[j].x > b || input[j].y > b)) continue;
			int tmp = input[i].x * input[i].y + input[j].x * input[j].y;
			if (input[i].x + input[j].x <= a && max(input[i].y, input[j].y) <= b) {
				ans = max(ans, tmp);
				continue;
			}
			if (input[i].x + input[j].y <= a && max(input[i].y, input[j].x) <= b) {
				ans = max(ans, tmp);
				continue;
			}
			if (input[i].y + input[j].x <= a && max(input[i].x, input[j].y) <= b) {
				ans = max(ans, tmp);
				continue;
			}
			if (input[i].y + input[j].y <= a && max(input[i].x, input[j].x) <= b) {
				ans = max(ans, tmp);
				continue;
			}
			if (input[i].x + input[j].x <= b && max(input[i].y, input[j].y) <= a) {
				ans = max(ans, tmp);
				continue;
			}
			if (input[i].x + input[j].y <= b && max(input[i].y, input[j].x) <= a) {
				ans = max(ans, tmp);
				continue;
			}
			if (input[i].y + input[j].x <= b && max(input[i].x, input[j].y) <= a) {
				ans = max(ans, tmp);
				continue;
			}
			if (input[i].y + input[j].y <= b && max(input[i].x, input[j].x) <= a) {
				ans = max(ans, tmp);
				continue;
			}
		}
	}
	cout << ans;
	return 0;
}
