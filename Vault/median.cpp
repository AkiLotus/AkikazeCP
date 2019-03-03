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
	freopen("median.inp", "r", stdin);
	freopen("median.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	int m, n, r, c; cin >> m >> n >> r >> c;
	int siz = r*c;
	int a[m][n];
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) cin >> a[i][j];
	}
	set<int> init, working;
	int ans = 1000000007;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			init.insert(a[i][j]);
		}
	}
	working = init;
	for (int i=0; i<=m-r; i++) {
		for (int j=0; j<=n-c; j++) {
			set<int>::iterator it = working.begin();
			advance(it, siz/2);
			//cout << *it << endl;
			ans = min(ans, *it);
			if (j < n-c) {
				for (int x=i; x<i+r; x++) {
					//cout << "Erase " << a[x][j] << endl;
					//cout << "Add " << a[x][j+c] << endl << endl;
					working.erase(a[x][j]);
					working.insert(a[x][j+c]);
				}
			}
		}
		if (i < m-r) {
			for (int y=0; y<c; y++) {
				//cout << "Erase " << a[i][y] << endl;
				//cout << "Add " << a[i+r][y] << endl << endl;
				init.erase(a[i][y]);
				init.insert(a[i+r][y]);
			}
		}
		working = init;
	}
	cout << ans;
	//fin.close(); fout.close();
	return 0;
}

