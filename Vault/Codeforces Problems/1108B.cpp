#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n; vector<int> d;

void Input() {
	cin >> n; d.resize(n);
	for (auto &z: d) cin >> z;
}

void Solve() {
	sort(d.begin(), d.end());
	int x = d[n-1];
	for (int i=1; i<=x; i++) {
		if (x % i != 0) continue;
		d.erase(lower_bound(d.begin(), d.end(), i));
	}
	int y = d[d.size() - 1];
	cout << x << " " << y << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
*  Thuy-Trang Tran, #Team4T's Leader     *
*  #Team4T Primary Flagship - Salvation  *
\******************************************/
