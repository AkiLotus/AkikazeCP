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


// File I/O here
string problemName = "";
string in = ".INP";
string out = ".OUT";

int main() {
	//ifstream fin; ofstream fout;
	//fin.open(problemName+in); fout.open(problemName+out);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	int n, k; cin >> n >> k;
	vector<int> bitmask(n);
	vector<int> cc(32, 0);
	for (int i=0; i<n; i++) {
		int a[k], mul = 1;
		for (int j=0; j<k; j++) {
			cin >> a[j];
			bitmask[i] += a[j] * mul; mul *= 2;
		}
		cc[bitmask[i]]++;
	}
	bool ok = false;
	for (int i=0; i<n; i++) {
		if (cc[bitmask[i] ^ ((1 << k) - 1)] > 0) {
			ok = true;
		}
	}
	if (ok) cout << "YES"; else cout << "NO";
	//fin.close(); fout.close();
	return 0;
}
