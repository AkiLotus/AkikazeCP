#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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

bool candidateSort(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if (a.first > b.first) return true;
    if (a.first == b.first && a.second.first < b.second.first) return true;
    if (a.first == b.first && a.second.first == b.second.first && a.second.second < b.second.second) return true;
    return false;
}

int main() {
	int n, k, m, a;
	cin >> n >> k >> m >> a;
	vector<pair<int, pair<int, int>>> z(n);
	vector<int> ans(n);
	for (int i=0; i<n; i++) z[i].second.second = i;
	for (int i=0; i<a; i++) {
        int p; cin >> p;
        z[p-1].first++;
        z[p-1].second.first = i;
	}
	sort(z.begin(), z.end(), candidateSort);
	int boundary = z[k-1].first;
	int tmp = k-1;
	while (tmp >= 0 && boundary == 0) {
        tmp--; boundary = z[tmp].first;
	}
	int pp = 0;
	while (z[pp].first != 0 && pp < n) pp++;
	int qq = m-a;
	int maxPossible = 0;
	for (int i=min(k, pp); i<n; i++) {
        qq = m-a;
        int bound = z[k-1-maxPossible].first;
        //cout << bound - z[6].first << endl;
        for (int j=k; j<=k+maxPossible; j++) qq -= (bound - z[j].first + 1);
        if (qq < 0) break;
        maxPossible++;
	}
	//cout << maxPossible << endl;
	for (int i=0; i<n; i++) {
        //cout << z[i].first << " " << z[i].second.first << " " << z[i].second.second << endl;
        int id = z[i].second.second;
        if (z[i].first == 0 && m - a == 0) ans[id] = 3;
        else {
            if (i < k-maxPossible) ans[id] = 1;
            else if (z[i].first > boundary - (m-a)) ans[id] = 2;
            else ans[id] = 3;
        }
        if (ans[id] == 1 && z[i].first == 0) ans[id] = 2;
	}
	for (int i=0; i<n; i++) cout << ans[i] << " ";
	return 0;
}
