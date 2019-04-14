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

int n, m, h; vector<int> a, b;
vector<vector<int>> TopView;

void Input() {
	cin >> n >> m >> h;
	a.resize(m); b.resize(n);
	TopView.resize(n, vector<int>(m));
	for (auto &z: a) cin >> z;
	for (auto &z: b) cin >> z;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> TopView[i][j];
		}
	}
}

void Solve() {
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (!TopView[i][j]) continue;
			TopView[i][j] = min(b[i], a[j]);
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cout << TopView[i][j] << " ";
		}
		cout << endl;
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