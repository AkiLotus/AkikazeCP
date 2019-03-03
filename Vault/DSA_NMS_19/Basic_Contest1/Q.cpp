#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
//mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

string A, B; vector<string> Tokens;
int Test = 0;

string generalize(string str) {
	for (int i=0; i<str.size(); i++) {
		if (str[i] <= 'Z') str[i] += 32;
	}
	return str;
}

void Input() {
	getline(cin, A); getline(cin, B);
	Tokens.clear(); Test = Test + 1;
}

void Solve() {
	string tmp = "";
	for (int i=0; i<A.size(); i++) {
		char c = A[i];
		if (c == ' ' && tmp != "") {
			Tokens.push_back(tmp); tmp = "";
		}
		else if (c != ' ') tmp += c;
	}
	if (tmp != "") Tokens.push_back(tmp);
	
	cout << "Test " << Test << ":";
	for (int i=0; i<Tokens.size(); i++) {
		if (generalize(Tokens[i]) != generalize(B)) {
			cout << " " << Tokens[i];
		}
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; getline(cin, A);
	while (T--) {Input(); Solve();} return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
  *  #Team4T Primary Flagship - Salvation  *
  \******************************************/
