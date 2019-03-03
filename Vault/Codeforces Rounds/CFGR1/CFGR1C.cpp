#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int a;

bool fullBit(int z) {
	z = z + 1;
	while (z % 2 == 0) z /= 2;
	return (z == 1);
}

void Input() {
	cin >> a;
}

void Solve() {
	if (!fullBit(a)) {
		for (int i=0; i<30; i++) {
			if ((1 << i) > a) continue;
			a |= (1 << i);
		}
		cout << a << endl; return;
	}
	for (int i=2; i<=sqrt(a); i++) {
		if (a % i != 0) continue;
		cout << a / i << endl; return;
	}
	cout << "1\n";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int q; cin >> q; while (q--) {Input(); Solve();} return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/
