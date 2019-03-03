#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int q, l, r;

void Input() {
	cin >> q;
}

void Solve() {
	while (q--) {
		cin >> l >> r;
		int len = r - l + 1;
		int sum = 0;
		if (l % 2 == 1) sum += len / 2;
		else sum -= len / 2;
		if (len % 2 == 1) {
			if (l % 2 == 1) sum -= r;
			else sum += r;
		}
		cout << sum << endl;
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