#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int n; vector<int> a, List;
long long s = 0;
vector<int> cnt(1000001, 0);

void Input() {
	cin >> n; a.resize(n);
	for (auto &x: a) {
		cin >> x;
		s += x; cnt[x]++;
	}
}

void Solve() {
	for (int i=0; i<n; i++) {
		cnt[a[i]]--; s -= a[i];
		if (s % 2 == 0 && s/2 < 1000001 && cnt[s/2]) {
			List.push_back(i+1);
		}
		cnt[a[i]]++; s += a[i];
	}
	cout << List.size() << endl;
	for (auto x: List) cout << x << " ";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}