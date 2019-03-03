#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;
	vector<long long> pos[n+1];
	vector<long long> bead(n);
	for (long long i=0; i<n; i++) {
        cin >> bead[i];
        pos[bead[i]].push_back(i);
	}
	while (m-- > 0) {
        long long cmd;
        cin >> cmd;
        if (cmd == 1) {
            long long p, x;
            cin >> p >> x;
            p--;
            long long val = bead[p];
            long long tmp = lower_bound(pos[val].begin(), pos[val].end(), p) - pos[val].begin();
            pos[val].erase(pos[val].begin()+tmp);
            long long z = lower_bound(pos[x].begin(), pos[x].end(), p) - pos[x].begin();
            pos[x].insert(pos[x].begin()+z, p);
            bead[p] = x;
        }
        else {
            long long l, r;
            cin >> l >> r;
            l--; r--;
            long long result = 0;
            stack<long long> found;
            vector<long long> first(n+1, -1);
            vector<long long> last(n+1, -1);
            for (long long i=l; i<=r; i++) {
                found.push(bead[i]);
                if (first[bead[i]] == -1) first[bead[i]] = i;
                last[bead[i]] = i;
            }
            while (!found.empty()) {
                long long z = found.top(); found.pop();
                result += last[z] - first[z];
                last[z] = -1; first[z] = -1;
            }
            cout << result << endl;
        }
	}
	return 0;
}
