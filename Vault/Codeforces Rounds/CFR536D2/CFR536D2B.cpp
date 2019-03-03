#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, m; vector<int> a, c;

void Input() {
	cin >> n >> m; a.resize(n); c.resize(n);
	for (auto &z: a) cin >> z;
	for (auto &z: c) cin >> z;
}

void Solve() {
	set<pair<int, int>> Rem;
	for (int i=0; i<n; i++) Rem.insert({c[i], i});
	while (m--) {
		int t, d; cin >> t >> d; t--;
		long long cost = 0; int InitialTaken = min(a[t], d);
		cost += 1LL * InitialTaken * c[t];
		a[t] -= InitialTaken; d -= InitialTaken;
		if (a[t] == 0 && InitialTaken > 0) Rem.erase({c[t], t});
		while (d > 0 && !Rem.empty()) {
			int id = Rem.begin()->second;
			int Taken = min(a[id], d);
			cost += 1LL * Taken * c[id]; a[id] -= Taken; d -= Taken;
			if (a[id] == 0) Rem.erase({c[id], id});
		}
		if (d > 0) cost = 0;
		cout << cost << endl;
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
*  Thuy-Trang Tran, #Team4T's Leader     *
*  #Team4T Primary Flagship - Salvation  *
\******************************************/
