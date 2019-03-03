#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T-- > 0) {
        long n, m;
        cin >> n >> m;
        vector<pair<long, long>> divisor;
        for (long long i=2; i<=sqrt(m); i++) {
            if (m % i == 0) {
                long long tmp = 0;
                pair<long, long> z; z.first = i;
                while (m % i == 0) {
                    m /= i;
                    tmp++;
                }
                z.second = tmp; divisor.push_back(z);
            }
        }
        if (m != 1) {
            pair<long, long> z; z.first = m; z.second = 1;
            divisor.push_back(z);
        }
        long ans = 999999999;
        for (long i=0; i<divisor.size(); i++) {
            long d = divisor[i].first;
            long z = d, tmp = 0;
            while (z <= n) {
                tmp += n / z;
                z *= d;
            }
            ans = min(tmp / divisor[i].second, ans);
        }
        if (ans == 999999999) ans = 0;
        cout << ans << endl;
	}
	return 0;
}
