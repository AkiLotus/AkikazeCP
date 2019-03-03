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
	string s; cin >> s;
	i64 n = s.size();
	i64 preSet = 0, unknown = 0;
	vector<i64> un, sum;
	i64 ans = 0;
	for (i64 i=n-1; i>=0; i--) {
		if (s[i] == '0') continue;
		if (s[i] == '1') {
			ans += (n - 1 - preSet) - i;
			ans %= MOD; preSet++;
		}
		else {
			un.pub(i);
			unknown++;
		}
	}
	sum.resize(unknown, 0); sum[unknown-1] = un[unknown-1];
	for (i64 i=unknown-2; i>=0; i--) sum[i] = (un[i+1] + sum[i]);
	for (i64 i=0; i<unknown; i++) ans = (ans * 2) % MOD;
	i64 leftmost = n - preSet - unknown;
	for (i64 i=0; i<unknown; i++) {
		//
	}
	cout << ans;
	return 0;
}
