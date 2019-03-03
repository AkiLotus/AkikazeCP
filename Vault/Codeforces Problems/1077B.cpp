#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int n; vector<int> a;

void Input() {
	cin >> n; a.resize(n);
	for (auto &x: a) cin >> x;
}

void Solve() {
	int ans = 0;
	for (int i=1; i<n-1; i++) {
		if (a[i-1] && !a[i] && a[i+1]) {
			ans++; a[i+1] = 0;
		}
	}
	cout << ans;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}