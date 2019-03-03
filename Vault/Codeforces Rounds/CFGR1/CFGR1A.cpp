#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int b, k; vector<int> a;

void Input() {
	cin >> b >> k; a.resize(k);
	for (auto &z: a) {cin >> z; z %= 2;}
}

void Solve() {
	b %= 2; int mul = 1, s = 0;
	for (int i=k-1; i>=0; i--) {
		s += mul * a[i];
		s %= 2; mul *= b; mul %= 2;
	}
	if (s == 0) cout << "even\n";
	else cout << "odd\n";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
  *  #Team4T Primary Flagship - Salvation  *
  \******************************************/
