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
	cin >> n >> s;
}

void Solve() {
	if (n % 2 != 0) {cout << ":(\n"; return;}
	if (s[0] == ')') {cout << ":(\n"; return;}
	if (s[n-1] == '(') {cout << ":(\n"; return;}
	s[0] = '('; s[n-1] = ')';
	int curclose = 0;
	for (auto &z: s) curclose += (z == ')');
	if (curclose > n / 2) {cout << ":(\n"; return;}
	for (int i=n-1; i>=0 && curclose < n/2; i--) {
		if (s[i] == '(') continue;
		else if (s[i] == '?') {curclose++; s[i] = ')';}
	}
	for (int i=0; i<n; i++) {
		if (s[i] == '?') s[i] = '(';
	}
	int tmp = 0;
	for (int i=0; i<n-1; i++) {
		tmp += (s[i] == '('); tmp -= (s[i] == ')');
		if (tmp == 0) {cout << ":(\n"; return;}
	}
	tmp += (s[n-1] == '('); tmp -= (s[n-1] == ')');
	if (tmp == 0) cout << s << endl;
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