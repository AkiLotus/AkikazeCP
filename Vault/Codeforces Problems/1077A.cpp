#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

long long T, a, b, k;

void Input() {
	cin >> T;
}

void Solve() {
	while (T--) {
		cin >> a >> b >> k;
		long long diff = a - b;
		cout << diff * (k / 2) + (k % 2) * a << endl;
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}