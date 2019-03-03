#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int n; vector<int> a;

void Input() {
	cin >> n; a.resize(n);
	for (auto &x: a) cin >> x;
}

void Solve() {
	int ans = 2e9;
	sort(a.begin(), a.end());
	for (int i=0; i<n/2; i++) ans = min(ans, a[n/2+i] - a[i]);
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
*  Thuy-Trang Tran, #Team4T's Leader     *
*  #Team4T Primary Flagship - Salvation  *
\******************************************/
