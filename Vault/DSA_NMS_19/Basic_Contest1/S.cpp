#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
//mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int N; vector<int> A;

void Input() {
	cin >> N; A.clear(); A.resize(N);
	for (int i=0; i<N; i++) cin >> A[i];
}

void Solve() {
	map<int, int> Map;
	int ans = -1, pos = -1;
	for (int i=0; i<N; i++) {
		if (Map[A[i]]) {
			if (pos == -1) {ans = A[i]; pos = Map[A[i]];}
			else if (Map[A[i]] < pos) {ans = A[i]; pos = Map[A[i]];}
		}
		Map[A[i]] = i + 1;
	}
	if (pos == -1) cout << "NO\n";
	else cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T;
	while (T--) {Input(); Solve();} return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
  *  #Team4T Primary Flagship - Salvation  *
  \******************************************/
