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

vector<int> stepsRequired1(450000);
vector<int> stepsRequired2(450000);

void Preprocess() {
	stepsRequired1[1] = 1;
	for (int x=2; x<450000; x++) {
		int sum = 0;
		stepsRequired1[x] = INT_MAX;
		for (int i=1; i<=x; i++) {
		    sum += i;
		    if (sum > x) break;
		    stepsRequired1[x] = min(stepsRequired1[x], stepsRequired1[x-sum] + i);
		}
	}
	stepsRequired2[1] = 1;
	for (int x=2; x<450000; x++) {
		int sum = 0;
		int i = sqrt(x * 2);
		while (1LL * (i + 1) * (i + 2) / 2 <= x) i++;
		while (1LL * i * (i + 1) / 2 > x) i--;
		stepsRequired2[x] = stepsRequired2[x - i * (i + 1) / 2] + i;
	}
}

void Input() {
	for (int i=0; i<450000; i++) {
		if (stepsRequired1[i] != stepsRequired2[i]) {
			cout << "Different at i = " << i << endl;
			cout << "Expected " << stepsRequired1[i] << ", found " << stepsRequired2[i] << endl;
		}
	}
}

void Solve() {
	
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL); Preprocess();
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/