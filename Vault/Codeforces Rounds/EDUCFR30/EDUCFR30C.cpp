// Template by proptit_4t41
// Applied for C++11/C++14
// Add -std=c++14 to your IDE.

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define i64 long long
#define u64 unsigned long long
#define ld long double
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


int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	int n, m, k; cin >> n >> m >> k;
	int a[n][m], dp[n][m];
	vector<int> one[m];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> a[i][j]; dp[i][j] = 0;
			if (a[i][j]) {
				one[j].push_back(i);
				for (int z=0; z<k; z++) {
					if (i - z < 0) break;
					if (a[i-z][j]) dp[i-z][j]++;
				}
			}
		}
	}
	int ans = 0, change = 0;
	for (int j=0; j<m; j++) {
		int maximum = 0, pos = -1;
		for (int i=0; i<n; i++) {
			if (maximum < dp[i][j]) {
				maximum = dp[i][j]; pos = i;
			}
		}
		ans += maximum;
		if (pos != -1) change += lower_bound(one[j].begin(), one[j].end(), pos) - one[j].begin();
	}
	cout << ans << " " << change;
	return 0;
}
