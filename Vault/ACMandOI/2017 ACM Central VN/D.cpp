/**
	Template by proptit_4t41
	Applied for C++11/C++14
	Add -std=c++14 to your IDE.
**/

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

/** -----IDEAS/ALGORITHMS----- **/


/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
i64 n; vector<pii> a;
pii last;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n;
	for (i64 i=0; i<n; i++) {
		i64 x, y; scanf("%lld%lld", &x, &y);
		a.pub(mp(x, y));
		//cout << "a[i] = " << a[i].fi << ", " << a[i].se << endl;
	}
	last.fi = a[1].fi - a[0].fi; last.se = a[1].se - a[0].se;
}

void ProSolve() {
	i64 ans = 0;
	for (i64 i=2; i<n; i++) {
		pii tmp = mp(a[i].fi - a[i-1].fi, a[i].se - a[i-1].se);
		//cout << "last = " << last.fi << ", " << last.se << endl;
		//cout << "tmp = " << tmp.fi << ", " << tmp.se << endl;
		if ((last == mp(0LL, 1LL) && tmp == mp(1LL, 0LL)) || (last == mp(0LL, -1LL) && tmp == mp(-1LL, 0LL)) || (last == mp(1LL, 0LL) && tmp == mp(0LL, -1LL)) || (last == mp(-1LL, 0LL) && tmp == mp(0LL, 1LL))) {
			ans++; //cout << "turn right and head to " << i << endl;
		}
		last = tmp;
	}
	cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
