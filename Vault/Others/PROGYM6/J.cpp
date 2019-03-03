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
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<int> ccA(16, 0);
		vector<int> ccC(60, 0);
		vector<int> a(n), b(m);
		for (int i=0; i<n; i++) {
			cin >> a[i]; ccA[a[i]]++;
		}
		for (int i=0; i<m; i++) {
			cin >> b[i]; ccC[b[i]]++;
		}
		sort(a.begin(), a.end()); sort(b.begin(), b.end());
		for (int i=0; i<a.size()-1; i++) {
			while (i+1 < a.size() && a[i+1] == a[i]) {
				a.erase(a.begin()+i+1);
			}
		}
		for (int i=0; i<b.size()-1; i++) {
			while (i+1 < b.size() && b[i+1] == b[i]) {
				b.erase(b.begin()+i+1);
			}
		}
		bool ok = true;
		int tmp = 0;
		for (int i=0; i<a.size(); i++) {
			//cout << a[i] << " " << b[tmp] << endl;
			while (tmp < b.size() && ccC[b[tmp]] < ccA[a[i]]) tmp++;
			if (tmp == b.size()) {
				ok = false; break;
			}
			//cout << a[i] << " " << b[tmp] << endl;
			tmp++;
		}
		if (ok) cout << "YES\n"; else cout << "NO\n";
	}
	//fin.close(); fout.close();
	return 0;
}
