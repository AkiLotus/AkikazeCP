#include <iostream>
#include <vector>
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
	vector<int> M(200006, 0);
	vector<int> duplicate;
	vector<int> pos[200006];
	vector<int> imm(200006, 0);
	int n; cin >> n;
	int avail = 0;
	int a[n];
	for (int i=0; i<n; i++) {
        cin >> a[i];
        if (M[a[i]] > 0) duplicate.push_back(a[i]);
        pos[a[i]].push_back(i);
        M[a[i]]++;
	}
	for (int i=1; i<=n; i++) {
        if (M[i] == 0) {
            avail = i;
            break;
        }
	}
	int ans1 = duplicate.size();
	cout << ans1 << endl;
	for (int i=0; i<n; i++) {
        int z = a[i];
        int siz = pos[z].size();
        if (M[z] == 1) continue;
        if ((avail < z) || (i != pos[z][imm[z]])) {
            M[a[i]]--; imm[z]++;
            a[i] = avail; M[avail]++;
            while (M[avail] != 0) avail++;
        }
	}
	for (int i=0; i<n; i++) cout << a[i] << " ";
	return 0;
}
