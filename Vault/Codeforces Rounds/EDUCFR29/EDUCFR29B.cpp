#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long strtoll(string z) {
	long long result = 0, sign = 1, i = 0;
	if (z[0] == '-') {
		i = 1; sign = -1;
	}
	for (; i<z.size(); i++) {
		result *= 10;
		result += (z[i] - '0');
	}
	return result * sign;
}

int main() {
	int n; cin >> n;
	vector<int> a(2*n);
	for (int i=0; i<2*n; i++) {
        cin >> a[i];
	}
	int ans = 99999999;
	sort(a.begin(), a.end());
	for (int i=0; i<2*n-1; i++) {
        for (int j=i+1; j<2*n; j++) {
            vector<int> b = a;
            b.erase(b.begin()+j);
            b.erase(b.begin()+i);
            int tmp = 0;
            for (int k=0; k<b.size(); k+=2) {
                tmp += (b[k+1] - b[k]);
            }
            ans = min(ans, tmp);
        }
	}
	cout << ans;
	return 0;
}
