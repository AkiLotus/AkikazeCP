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
const long double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

// custom typedef here


// global variables here


// functions here


int main() {
	//freopen("LISYS.INP", "r", stdin);
	//freopen("LISYS.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	int n, m, s; cin >> n >> m >> s;
	int state[n][m];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) cin >> state[i][j];
	}
	vector<int> row(n, 0);
	vector<int> col(m, 0);
	while (s--) {
		int z; cin >> z;
		if (z <= n) row[z-1]++;
		else col[z-n-1]++;
	}
	for (int i=0; i<n; i++) {
		if (row[i] == 0) continue;
		for (int j=0; j<m; j++) state[i][j] = (state[i][j] + row[i]) % 3;
	}
	for (int j=0; j<m; j++) {
		if (col[j] == 0) continue;
		for (int i=0; i<n; i++) state[i][j] = (state[i][j] + col[j]) % 3;
	}
	int ans = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (state[i][j] == 0) ans++;
		}
	}
	cout << ans;
	return 0;
}
