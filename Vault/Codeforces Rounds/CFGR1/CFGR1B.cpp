#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, m, k; vector<int> b;

void Input() {
	cin >> n >> m >> k; b.resize(n);
	for (auto &z: b) cin >> z;
}

void Solve() {
	int used = n, Len = n;
	priority_queue<int, vector<int>, greater<int>> GapHeap;
	for (int i=1; i<n; i++) {
		if (b[i] - b[i-1] == 1) {used--; continue;}
		GapHeap.push(b[i] - b[i-1] - 1);
	}
	while (used > k) {
		Len += GapHeap.top();
		GapHeap.pop(); used--;
	}
	cout << Len << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
  *  #Team4T Primary Flagship - Salvation  *
  \******************************************/
