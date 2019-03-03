#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

string s, t;
map<char, bool> vowel;

void Input() {
	cin >> s >> t;
	vowel['a'] = true;
	vowel['e'] = true;
	vowel['i'] = true;
	vowel['o'] = true;
	vowel['u'] = true;
}

void Solve() {
	if (s.size() != t.size()) {cout << "No\n"; return;}
	for (int i=0; i<min(s.size(), t.size()); i++) {
		if (!vowel[s[i]] && !vowel[t[i]]) continue;
		if (vowel[s[i]] && vowel[t[i]]) continue;
		cout << "No\n"; return;
	}
	cout << "Yes\n";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
  *  #Team4T Primary Flagship - Salvation  *
  \******************************************/
