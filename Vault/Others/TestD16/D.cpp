#include <iostream>
using namespace std;

int main() {
	int m;
	cin >> m;
	int cc[8096];
	for (int i=0; i<8096; i++) cc[i] = 0;
	for (int i=0; i<m; i++) {
        int z;
        cin >> z;
        cc[z]++;
	}
	int maximum = -1;
	int ans = 0;
	for (int i=0; i<8096; i++) {
        if (cc[i] > 0) {
            maximum = i;
            ans++;
        }
	}
	for (int i=maximum-1; i>=0; i--) {
        if (cc[i] > 1) ans++;
	}
	if (ans < 2) cout << 0;
	else cout << ans;
	return 0;
}
