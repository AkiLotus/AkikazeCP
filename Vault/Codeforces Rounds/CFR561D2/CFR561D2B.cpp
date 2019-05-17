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

int k;
string vowel = "aeiou";

void Input() {
	cin >> k;
}

void Solve() {
	for (int i=5; i<=sqrt(k); i++) {
		if (k % i != 0) continue;
		int j = k / i;
		vector<vector<char>> Mat(i, vector<char>(j, 't'));
		for (int x=0; x<i; x++) {
			for (int y=0; y<j; y++) {
				Mat[(x+y) % i][y] = vowel[x % 5];
			}
		}
		for (int x=0; x<i; x++) {
			for (int y=0; y<j; y++) {
				cout << Mat[x][y];
			}
		}
		cout << endl; return;
	}
	cout << "-1\n";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/