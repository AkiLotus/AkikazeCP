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
		int n; cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; i++) cin >> a[i];
		if (n == 1) cout << a[0] << endl;
		else if (n == 2) cout << abs(a[0] - a[1]) << endl;
		else {
			int left = a[0], right = a[n-1];
			deque<int> D;
			for(int i=1; i<n-1; i++) D.pub(a[i]);
			int ans = 0, turn = 1;
			while (!D.empty()) {
				if (left - D.front() > right - D.back()) {
					if (turn == 1) ans += left; else ans -= left;
					left = D.front(); D.pof();
				}
				else {
					if (turn == 1) ans += right; else ans -= right;
					right = D.back(); D.pob();
				}
				turn = 1 - turn;
			}
			if (turn == 1) ans += abs(left-right);
			else ans -= abs(left-right);
			cout << ans << endl;
		}
	}
	//fin.close(); fout.close();
	return 0;
}
