#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
//mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, k; vector< vector<int> > A;

void Input() {
	cin >> n; A.resize(n, vector<int>(n));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> A[i][j];
		}
	}
}

void Solve() {
	cin >> k;
	while (k--) {
		int x, y; cin >> x >> y;
		for (int i=0; i<n; i++) {
			A[i].erase(A[i].begin()+y);
		}
		A.erase(A.begin()+x); n--;
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
  *  #Team4T Primary Flagship - Salvation  *
  \******************************************/
