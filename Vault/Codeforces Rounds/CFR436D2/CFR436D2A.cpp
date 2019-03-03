#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll strtoll(string z) {
	ll result = 0, sign = 1, i = 0;
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
	vector<int> q;
	vector<int> cc;
	while (n--) {
        int z; cin >> z;
        if (find(q.begin(), q.end(), z) == q.end()) {
            q.push_back(z); cc.push_back(1);
        }
        else {
            int m = find(q.begin(), q.end(), z) - q.begin();
            cc[m]++;
        }
	}
	if (q.size() == 2 && cc[0] == cc[1]) cout << "YES\n" << q[0] << " " << q[1];
	else cout << "NO";
	return 0;
}
