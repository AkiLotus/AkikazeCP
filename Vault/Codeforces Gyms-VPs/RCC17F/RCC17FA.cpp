#include <iostream>
#include <vector>
#include <cmath>
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

vector<int> diff;
vector<bool> diffappeared(1000007, false);
vector<bool> nope(1000007, false);
vector<int> answer;

int main() {
	int t;
	cin >> t;
	while (t--) {
        diff.clear(); answer.clear();
        for (int i=0; i<1000007; i++) {
            diffappeared[i] = false;
            nope[i] = false;
        }
        int n;
        cin >> n;
        int a[n];
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                int tmp = abs(a[i]-a[j]);
                if (!diffappeared[tmp]) diff.push_back(tmp);
                diffappeared[tmp] = true;
            }
        }
        int possible = 0;
        for (int i=1; i<=1000000; i++) {
            if (nope[i]) continue;
            possible++; answer.push_back(i);
            for (int j=0; j<diff.size(); j++) {
                if (i > diff[j]) nope[i - diff[j]] = true;
                nope[i + diff[j]] = true;
            }
        }
        if (possible < n) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i=0; i<n; i++) cout << answer[i] << " "; cout << endl;
        }
	}
	return 0;
}
