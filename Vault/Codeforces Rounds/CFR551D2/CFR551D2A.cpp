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

int n, t; vector<int> s, d;

void Input() {
	cin >> n >> t; s.resize(n); d.resize(n);
	for (int i=0; i<n; i++) cin >> s[i] >> d[i];
}

void Solve() {
	int id = 0, Time = INT_MAX;
	for (int i=0; i<n; i++) {
		int tmpTime = INT_MAX;
		for (int j=s[i]; j<=400000; j+=d[i]) {
			if (j < t) continue;
			tmpTime = min(tmpTime, j - t);
		}
		if (tmpTime < Time) {Time = tmpTime; id = i + 1;}
	}
	cout << id << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/