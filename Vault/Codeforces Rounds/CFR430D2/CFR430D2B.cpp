#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int r, d;
	cin >> r >> d;
	int n;
	cin >> n;
	int ans = 0;
	while (n-- > 0) {
        int x, y, ra;
        cin >> x >> y >> ra;
        float z = x*x + y*y;
        float dist = sqrt(z);
        if (dist >= ra+r-d && dist <= r-ra) ans++;
	}
	cout << ans;
	return 0;
}
