#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
//mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, Test = 0; vector< vector<long long> > A;
vector<long long> Fib(90, 0);

void Input() {
	cin >> n; A.clear();
	A.resize(n, vector<long long>(n));
}

void Solve() {
	int id = 1, st = 0, en = n-1;
	
	while (st < en) {
		for (int j=st; j<en; j++) A[st][j] = Fib[id++];
		for (int i=st; i<en; i++) A[i][en] = Fib[id++];
		for (int j=en; j>st; j--) A[en][j] = Fib[id++];
		for (int i=en; i>st; i--) A[i][st] = Fib[id++];
		st = st + 1; en = en - 1;
	}
	
	if (st == en) A[st][en] = Fib[id++];
	
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
	Fib[1] = 1; for (int i=2; i<90; i++) Fib[i] = Fib[i-1] + Fib[i-2];
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
  *  #Team4T Primary Flagship - Salvation  *
  \******************************************/
