#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
//mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, Test = 0; vector< vector<long long> > A;

void Input() {
	cin >> n; A.clear();
	A.resize(n, vector<long long>(n));
}

void Solve() {
	int id = n * n, st = 0, en = n-1;
	
	while (st < en) {
		for (int j=st; j<en; j++) A[st][j] = id--;
		for (int i=st; i<en; i++) A[i][en] = id--;
		for (int j=en; j>st; j--) A[en][j] = id--;
		for (int i=en; i>st; i--) A[i][st] = id--;
		st = st + 1; en = en - 1;
	}
	
	if (st == en) A[st][en] = id--;
	
	cout << "Test " << (++Test) << ":\n";
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
  *  #Team4T Primary Flagship - Salvation  *
  \******************************************/
