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

int n; vector<int> a, b;

void Input() {
	cin >> n; a.resize(n); b.resize(n);
	for (auto &z: a) cin >> z;
	for (auto &z: b) cin >> z;
}

void Solve() {
	map<pair<int, int>, int> Map; int ans = 0, guaranteed = 0;
	for (int i=0; i<n; i++) {
		if (a[i] == 0) guaranteed += (b[i] == 0);
		else {
			int x = abs(b[i]), y = abs(a[i]);
			int g = __gcd(x, y);
			if (a[i] < 0) g = -g;
			Map[make_pair(-b[i] / g, a[i] / g)]++;
		}
	}
	for (auto it=Map.begin(); it!=Map.end(); it++) ans = max(ans, it->second);
	cout << (ans + guaranteed) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/