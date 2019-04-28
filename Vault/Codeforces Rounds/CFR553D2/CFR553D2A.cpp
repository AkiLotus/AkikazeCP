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
	int Min = INT_MAX;
	string genome = "ACTG";
	for (int i=0; i<=n-4; i++) {
		int cur = 0;
		for (int x=0; x<4; x++) {
			int Diff1 = abs(int(genome[x]) - int(s[i+x]));
			int Diff2 = 26 - Diff1;
			cur += min(Diff1, Diff2);
		}
		Min = min(Min, cur);
	}
	cout << Min << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/