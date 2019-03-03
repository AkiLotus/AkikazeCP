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
	i64 n, m; cin >> n >> m;
	vector<i64> t(n), b(m+1);
	for (i64 i=0; i<n; i++) cin >> t[i];
	for (i64 i=0; i<m; i++) cin >> b[i];
	i64 current = t[0]; b[m] = t[0];
	i64 time = 0;
	for (i64 i=0; i<=m; i++) {
		i64 shortestToTele;
		if (current <= t[0]) shortestToTele = t[0] - current;
		else if (current >= t[n-1]) shortestToTele = current - t[n-1];
		else {
			i64 p = lower_bound(t.begin(), t.end(), current) - t.begin();
			shortestToTele = t[p] - current;
			if (t[p] - current > current - t[p-1]) shortestToTele = current - t[p-1];
		}
		i64 len = shortestToTele;
		if (lower_bound(t.begin(), t.end(), b[i]) == t.begin()) len += t[0] - b[i];
		else if (b[i] >= t[n-1]) len += b[i] - t[n-1];
		else {
			i64 p = lower_bound(t.begin(), t.end(), b[i]) - t.begin();
			len += min(t[p] - b[i], b[i] - t[p-1]);
		}
		len = min(len, abs(current-b[i]));
		//cout << len << endl;
		time += len; current = b[i];
	}
	cout << time;
	return 0;
}
