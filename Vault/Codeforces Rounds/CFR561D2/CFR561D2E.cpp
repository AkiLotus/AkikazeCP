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

int m, n;
vector<vector<bool>> Dora, Swiper;

bool contains(vector<bool> &a, vector<bool> &b) {
	for (int i=0; i<a.size(); i++) {
		if (!a[i]) continue;
		if (b[i]) continue;
		return false;
	}
	return true;
}

void Input() {
	cin >> m >> n; Dora.resize(m); Swiper.resize(m);
	for (int i=0; i<m; i++) {
		Dora[i].resize(n, false); Swiper[i].resize(n, true);
		int s; cin >> s;
		for (int x=0; x<s; x++) {
			int z; cin >> z; z--;
			Dora[i][z] = true; Swiper[i][z] = false;
		}
	}
}

void Solve() {
	for (int i=0; i<m; i++) {
		for (int j=0; j<m; j++) {
			if (contains(Dora[i], Swiper[j])) {
				cout << "impossible\n"; return;
			}
		}
	}
	cout << "possible\n";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/