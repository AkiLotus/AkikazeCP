#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int n, m; vector<int> a;

void Input() {
	cin >> n >> m; a.resize(n);
	for (auto &x: a) cin >> x;
}

void Solve() {
	long long s = 0, Max = 0, Minimum = n;
	sort(a.begin(), a.end()); int Height = 0;
	for (int i=0; i<n; i++) {s += a[i]; Max = max(Max, (long long)a[i]);}
	for (int i=0; i<n; i++) Height = min(Height+1, a[i]);
	Minimum += (Max - Height);
	cout << (s - Minimum);
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/