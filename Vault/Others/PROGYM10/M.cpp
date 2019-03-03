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
	i64 n, sum = 0; cin >> n;
	vector<pii> kills(n);
	for (i64 i=0; i<n; i++) {
		cin >> kills[i].fi; kills[i].se = i;
		sum += kills[i].fi;
	}
	if (sum >= n) {
		cout << "NO"; return 0;
	}
	vector<pii> logs;
	sort(kills.begin(), kills.end(), greater<pii>());
	i64 firstNonZero = n-1;
	while (kills[firstNonZero].fi == 0) firstNonZero--;
	i64 killed = n-1;
	for (i64 i=firstNonZero; i>=0; i--) {
		while (kills[i].fi > 0) {
			logs.pub(mp(kills[i].se+1, kills[killed].se+1));

			kills[i].fi--; killed--;
		}
	}
	cout << "YES";
	for (i64 i=0; i<logs.size(); i++) cout << endl << logs[i].fi << " " << logs[i].se;
	return 0;
}
