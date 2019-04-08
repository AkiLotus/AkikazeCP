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

int n; vector<int> c;
vector<vector<int>> List;

void Input() {
	cin >> n; c.resize(n); List.resize(n);
	for (auto &z: c) {cin >> z; z--;}
}

void Solve() {
	for (int i=0; i<n; i++) List[c[i]].push_back(i);
	int ans = 0;
	for (int i=0; i<n; i++) {
		int Left = 0, Right = n-1;
		while (lower_bound(List[i].begin(), List[i].end(), Left) != List[i].end()
		&& *lower_bound(List[i].begin(), List[i].end(), Left) == Left) Left++;
		while (lower_bound(List[i].begin(), List[i].end(), Right) != List[i].end()
		&& *lower_bound(List[i].begin(), List[i].end(), Right) == Right) Right--;
		for (auto z: List[i]) ans = max(ans, (int)max(abs(Left - z), abs(Right - z)));
	}
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/