#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int n, k;

void Input() {
	cin >> n >> k;
}

void Solve() {
	int s = 0;
	s += ((n * 2) / k + ((n * 2) % k != 0));
	s += ((n * 5) / k + ((n * 5) % k != 0));
	s += ((n * 8) / k + ((n * 8) % k != 0));
	cout << s;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/