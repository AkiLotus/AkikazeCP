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

int n; string s;

void Input() {
	cin >> s;
	n = s.size();
}

void Solve() {
	int a = 0;
	for (auto c: s) a += (c == 'a');
	if ((n + a) % 2 != 0) {cout << ":(\n"; return;}
	int org = (n + a) / 2;
	string o = s.substr(0, org);
	string m = s.substr(org);
	string z = "";
	for (auto c: o) {
		if (c != 'a') z += c;
	}
	if (m == z) cout << o << endl;
	else cout << ":(\n";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/