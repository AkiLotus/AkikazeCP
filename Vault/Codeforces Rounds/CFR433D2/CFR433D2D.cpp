#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct data {
    long long x, y;
};

int main() {
	long long n, m, k;
	cin >> n >> m >> k;
	long long lastArrival = -1, firstDeparture = 1000007;
	vector<data> flight[n+1][2];
	vector<bool> arrive(n+1, false);
	vector<bool> depart(n+1, false);
	while (m-- > 0) {
        long long d, f, t, c;
        cin >> d >> f >> t >> c;
        data tmp; tmp.y = c;
        if (f == 0) {
            firstDeparture = min(d, firstDeparture);
            tmp.x = t; flight[t][1].push_back(tmp);
            depart[t] = true;
        }
        else {
            lastArrival = max(d, lastArrival);
            tmp.x = f; flight[f][0].push_back(tmp);
            arrive[f] = true;
        }
	}
	if (firstDeparture - lastArrival <= k) {
        cout << -1;
        return 0;
	}
	else {
        for (long long i=1; i<=n; i++) {
            if (!depart[i] || !arrive[i]) {
                cout << -1;
                return 0;
            }
        }

	}
	return 0;
}
