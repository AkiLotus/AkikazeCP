#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
//mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

string s; vector<string> Tokens;
map<string, int> Address;

string generalize(string str) {
	for (int i=0; i<str.size(); i++) {
		if (str[i] <= 'Z') str[i] += 32;
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
	string email = Tokens.back();
	for (int i=0; i<Tokens.size()-1; i++) {
		email += Tokens[i][0];
	}
	Address[email]++;
	if (Address[email] == 1) cout << email << "@ptit.edu.vn\n";
	else cout << email << Address[email] << "@ptit.edu.vn\n";
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
