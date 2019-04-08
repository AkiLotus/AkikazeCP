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

int n, m; vector<vector<int>> A, B;

void Input() {
	cin >> n >> m; A.resize(n, vector<int>(m));
	B.resize(n, vector<int>(m));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> A[i][j];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> B[i][j];
		}
	}
}

void Solve() {
	for (int i=0; i<n-1; i++) {
		for (int j=0; j<m-1; j++) {
			if (A[i][j] == B[i][j]) continue;
			A[i][j] = 1 - A[i][j]; A[i+1][j+1] = 1 - A[i+1][j+1];
			A[i+1][j] = 1 - A[i+1][j]; A[i][j+1] = 1 - A[i][j+1];
		}
	}
	if (A == B) cout << "Yes\n"; else cout << "No\n";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/