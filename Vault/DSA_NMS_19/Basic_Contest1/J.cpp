#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
//mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, m, Test = 0;
vector< vector<long long> > A1;

vector< vector<long long> > Transpose(vector< vector<long long> > A) {
	vector< vector<long long> > res(m, vector<long long>(n));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			res[j][i] = A[i][j];
		}
	}
	return res;
}

vector< vector<long long> > Multiply(vector< vector<long long> > A, vector< vector<long long> > B) {
	vector< vector<long long> > res(n, vector<long long>(n));
	for (int k=0; k<m; k++) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				res[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	
	return res;
}

void Input() {
	cin >> n >> m; A1.clear();
	A1.resize(n, vector<long long>(m));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> A1[i][j];
		}
	}
}

void Solve() {
	vector< vector<long long> > A2 = Transpose(A1);
	
	vector< vector<long long> > B = Multiply(A1, A2);
	
	cout << "Test " << (++Test) << ":\n";
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << B[i][j] << " ";
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
