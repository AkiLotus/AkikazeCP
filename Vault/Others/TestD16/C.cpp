#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
        long long N, K;
        cin >> K >> N;
        if (N == 1) cout << 1 << endl;
        else if (N < 3) cout << (K % 1000000007) << endl;
        else {
            long long ans = (K % 1000000007);
            while (N-- > 3) {
                ans *= ans; ans %= 1000000007;
            }
            cout << ans << endl;
        }
	}
	return 0;
}
