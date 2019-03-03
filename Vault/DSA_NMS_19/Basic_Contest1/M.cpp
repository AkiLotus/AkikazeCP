#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
//mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

string s;

void Input() {
	getline(cin, s);
}

void Solve() {
	string t = s; reverse(t.begin(), t.end());
	bool inct = true, incs = true;
	for (int i=1; i<s.size(); i++) {
		if (t[i] < t[i-1]) inct = false;
		if (s[i] < s[i-1]) incs = false;
	}
	if (inct || incs) cout << "YES\n";
	else cout << "NO\n";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; getline(cin, s);
	while (T--) {Input(); Solve();} return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
  *  #Team4T Primary Flagship - Salvation  *
  \******************************************/
