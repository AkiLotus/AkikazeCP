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
	int T; cin >> T;
	while (T--) {
		i64 N; cin >> N;
		vector<i64> dp(N, 0), height(N, 0), index(N, 0);
		vector<tiii> a(N);
		for (i64 i=0; i<N; i++) cin >> index[i];
		for (i64 i=0; i<N; i++) cin >> height[i];
		for (i64 i=0; i<N; i++) a[i] = mt(height[i], index[i], i);
		stack<tiii> S;
		for (i64 i=0; i<N; i++) {
			if (i == 0) {
				dp[i] = a[i].se * a[i].fi;
				S.push(a[i]); continue;
			}
			dp[i] = dp[i-1] + (a[i].se - a[i-1].se - 1) * a[i].fi;
			while (!S.empty() && get<0>(S.top()) <= get<0>(a[i])) {
				int last = get<2>(S.top());
				dp[i] = dp[last] + (get<1>(a[i]) - get<1>(a[last]) * get<0>(a[i]);
			}
		}
	}
	return 0;
}
