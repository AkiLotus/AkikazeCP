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
		int n, k; cin >> n >> k;
		vector<int> cc(131072, 0);
		vector<int> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i]; cc[a[i]]++;
		}
		sort(a.begin(), a.end());
		int ans1 = -1, ans2 = 0;
		for (int i=0; i<n; i++) {
			if (a[i] == 0) continue;
			if (k % a[i]) continue;
			if ((k/a[i] != a[i] && cc[k/a[i]]) || (a[i] * a[i] == k && cc[a[i]] > 1)) {
				ans1 = a[i];
				ans2 = k / a[i];
				break;
			}
		}
		if (ans1 == -1) cout << ans1 << endl;
		else cout << ans1 << " " << ans2 << endl;
	}
	//fin.close(); fout.close();
	return 0;
}
