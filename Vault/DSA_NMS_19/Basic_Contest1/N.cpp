#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
//mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

string s; vector<string> Tokens;

string generalize(string str) {
	if (str[0] >= 'a' && str[0] <= 'z') str[0] -= 32;
	for (int i=1; i<str.size(); i++) {
		if (str[i] <= 'Z' && str[i] >= 'A') str[i] += 32;
	}
	return str;
}

string upcase(string str) {
	for (int i=0; i<str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
	}
	return str;
}

void Input() {
	getline(cin, s);
	Tokens.clear();
}

void Solve() {
	string tmp = "";
	for (int i=0; i<s.size(); i++) {
		char c = s[i];
		if (c == ' ' && tmp != "") {
			Tokens.push_back(generalize(tmp)); tmp = "";
		}
		else if (c != ' ') tmp += c;
	}
	if (tmp != "") Tokens.push_back(generalize(tmp));
	for (int i=0; i<Tokens.size(); i++) {
		cout << Tokens[i] << " ";
	}
	cout << endl;
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
