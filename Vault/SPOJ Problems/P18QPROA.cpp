#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int T, n;

void Input() {
	cin >> T;
}

void Solve() {
	while (T--) {
		cin >> n; int ans = 0;
		for (int i=1; i<=sqrt(n); i++) {
			if (n % i != 0) continue;
			ans += (i % 2 == 0);
			if (i * i != n) ans += ((n / i) % 2 == 0);
		}
		cout << ans << endl;
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