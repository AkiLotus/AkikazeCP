// Template by proptit_4t41
// Applied for C++11/C++14
// Add -std=c++14 to your IDE.

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define i64 long long
#define u64 unsigned long long
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define MOD 1000000007LL
#define INF 1e9
#define LINF 1e18
#define EPS 1e-9
#define GOLD ((1+sqrt(5))/2)
#define REcheck cout << "RE here?\n"
#define tracker1(i) cout << "working at " << i << endl;
#define tracker2(i,j) cout << "working at " << i << "-" << j << endl;
#define tracker3(i,j,k) cout << "working at " << i << "-" << j << "-" << k << endl;
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

// global variables here


// custom typedef here


// functions here
i64 foo (i64 z) {
	i64 res = 0;
	while (z > 1) {
		res += (z % 2 + 1);
		z /= 2;
	}
	return res;
}

// File I/O here
string problemName = "";
string in = ".INP";
string out = ".OUT";

int main() {
	//ifstream fin; ofstream fout;
	//fin.open(problemName+in); fout.open(problemName+out);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	int t; cin >> t;
	while (t--) {
		i64 n, q; cin >> n >> q;
		vector<i64> a(n);
		vector<i64> step(n);
		vector<i64> sum(n);
		for (i64 i=0; i<n; i++) {
			cin >> a[i];
			step[i] = foo(a[i]);
		}
		sum[0] = step[0];
		for (i64 i=1; i<n; i++) sum[i] = sum[i-1] + step[i];
		while (q--) {
			i64 l, r; cin >> l >> r;
			if (l == 1) cout << sum[r-1] << endl;
			else cout << (sum[r-1] - sum[l-2]) << endl;
		}
	}
	//fin.close(); fout.close();
	return 0;
}
