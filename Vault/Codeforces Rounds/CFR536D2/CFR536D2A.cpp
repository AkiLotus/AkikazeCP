#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n; vector<vector<char>> A;

void Input() {
	cin >> n; A.resize(n, vector<char>(n));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> A[i][j];
		}
	}
}

void Solve() {
	int res = 0;
	for (int i=1; i<n-1; i++) {
		for (int j=1; j<n-1; j++) {
			res += (A[i][j] == 'X' && A[i-1][j-1] == 'X' && A[i-1][j+1] == 'X' && A[i+1][j-1] == 'X' && A[i+1][j+1] == 'X');
		}
	}
	cout << res << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
*  Thuy-Trang Tran, #Team4T's Leader     *
*  #Team4T Primary Flagship - Salvation  *
\******************************************/
