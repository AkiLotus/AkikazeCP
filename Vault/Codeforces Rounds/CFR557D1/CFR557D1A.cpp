#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define y0 holdtheflower
#define y1 enjoythecolorandscent
#define yn walkthroughthesoulgarden
#define j1 feelthewarmbreathofkindnessandsalvation

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, k; vector<int> x;

void Input() {
	cin >> n >> k; x.resize(k);
	for (auto &z: x) {cin >> z; z--;}
}

void Solve() {
	vector<vector<int>> occ(n);
	for (int i=0; i<k; i++) occ[x[i]].push_back(i);
	int ans = 0;
	for (int i=0; i<n; i++) {
		for (int j=-1; j<=1; j++) {
			if (i+j < 0 || i+j >= n) continue;
			if (j == 0) {ans += occ[i].empty(); continue;}
			if (occ[i].empty()) {ans++; continue;}
			int id = occ[i][0];
			ans += (lower_bound(occ[i+j].begin(), occ[i+j].end(), id) == occ[i+j].end());
		}
	}
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/