#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n; vector<int> a, b;

void Input() {
	cin >> n; a.resize(n); b.resize(n);
	for (auto &z: a) cin >> z;
	for (auto &z: b) cin >> z;
}

void Solve() {
	long long Joy = 0;
	for (int i=0; i<n; i++) {
		if (b[i] < 2 || b[i] > a[i] * 2) {Joy--; continue;}
		int x = b[i] / 2, y = b[i] - x;
		Joy += 1LL * x * y;
	}
	cout << Joy << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
*  Thuy-Trang Tran, #Team4T's Leader     *
*  #Team4T Primary Flagship - Salvation  *
\******************************************/
