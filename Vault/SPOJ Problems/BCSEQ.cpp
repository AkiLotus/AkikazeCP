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

// custom typedef here


// global variables here


// functions here


int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	int n, m; cin >> n >> m;
	vector<int> a(n); map<int, int> Map;
	for (int i=0; i<n; i++) cin >> a[i];
	int ans = 1, tmp = 1, weight = 1, pos = 0, last = 0; Map[a[0]]++;
	for (int i=1; i<n; i++) {
		//cout << "Current weight = " << weight << endl;
		//cout << "Current segment = " << pos << " -> " << last << endl;
		if (weight < m || (weight == m && Map[a[i]] > 0)) {
			tmp++; Map[a[i]]++; ans = max(ans, tmp); last = i;
			if (Map[a[i]] == 1) weight++;
		}
		else {
			while (pos <= last && ((weight >= m) || (weight > m && Map[a[i]] > 0))) {
				Map[a[pos]]--; tmp--; if (Map[a[pos]] == 0) weight--; pos++;
			}
			tmp++; Map[a[i]]++; ans = max(ans, tmp); last = i;
			if (Map[a[i]] == 1) weight++;
		}
	}
	ans = max(ans, tmp);
	cout << ans;
	return 0;
}
