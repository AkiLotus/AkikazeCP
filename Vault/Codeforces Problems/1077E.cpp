#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int n; vector<int> a;
map<int, int> Map;
vector<int> freq;

void Input() {
	cin >> n; a.resize(n);
	for (auto &x: a) {
		cin >> x;
		Map[x]++;
	}
}

void Solve() {
	for (auto it=Map.begin(); it!=Map.end(); it++) freq.push_back(it->second);
	sort(freq.begin(), freq.end());
	int ans = 0;
	for (int i=1; i<=n; i++) {
		int x = i, tmp = 0, Last = -1;
		while (lower_bound(freq.begin()+Last+1, freq.end(), x) != freq.end()) {
			Last = lower_bound(freq.begin()+Last+1, freq.end(), x) - freq.begin();
			tmp += x; x *= 2;
		}
		ans = max(ans, tmp);
	}
	cout << ans;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}