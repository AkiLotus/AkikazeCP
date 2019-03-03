#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n; vector<int> c, t;

void Input() {
	cin >> n; c.resize(n); t.resize(n);
	for (auto &z: c) cin >> z;
	for (auto &z: t) cin >> z;
}

void Solve() {
	if (c[0] != t[0] || c[n-1] != t[n-1]) {cout << "No\n"; return;}
	vector<int> a1(n-1), a2(n-1);
	for (int i=0; i<n-1; i++) a1[i] = c[i] - c[i+1], a2[i] = t[i] - t[i+1];
	sort(a1.begin(), a1.end()); sort(a2.begin(), a2.end());
	if (a1 == a2) cout << "Yes\n"; else cout << "No\n";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
  *  #Team4T Primary Flagship - Salvation  *
  \******************************************/
