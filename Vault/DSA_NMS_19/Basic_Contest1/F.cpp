#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
//mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, Test;

void Input() {
	cin >> n;
}

void Solve() {
	cout << "Test " << (++Test) << ":";
	
	for (int i=2; i<=sqrt(n); i++) {
		if (n % i != 0) continue;
		int j = 0; while (n % i == 0) {n /= i; j++;}
		cout << " " << i << "(" << j << ")";
	}
	
	if (n > 1) cout << " " << n << "(1)";
	
	cout << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
  *  #Team4T Primary Flagship - Salvation  *
  \******************************************/
