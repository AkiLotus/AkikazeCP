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

int n; vector<string> a;
vector<int> cnt(26, 0);

void Input() {
	cin >> n; a.resize(n);
	for (auto &z: a) {
		cin >> z;
		cnt[z[0]-'a']++;
	}
}

void Solve() {
	int ans = 0;
	for (int i=0; i<26; i++) {
		int x = cnt[i] / 2, y = cnt[i] - x;
		ans += x * (x - 1) / 2;
		ans += y * (y - 1) / 2;
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