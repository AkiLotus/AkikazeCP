#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
//mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n; vector<int> u, d;

int sum(vector<int> A) {
	int res = 0;
	for (int i=0; i<A.size(); i++) res += A[i];
	return res;
}

void Input() {
	cin >> n; u.resize(n); d.resize(n);
	for (int i=0; i<n; i++) cin >> u[i] >> d[i];
}

void Solve() {
	int MinU = *min_element(u.begin(), u.end());
	int MinD = *min_element(d.begin(), d.end());
	int SumU = sum(u), SumD = sum(d);
	cout << max(MinU+SumD, MinD+SumU) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
  *  #Team4T Primary Flagship - Salvation  *
  \******************************************/
