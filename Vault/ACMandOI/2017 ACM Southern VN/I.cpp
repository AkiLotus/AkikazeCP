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
i64 n, m, ans = 0;
vector<pii> a, b;
vector<i64> sumb, valb, indb;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n; a.resize(n);
	for (i64 i=0; i<n; i++) {
		cin >> a[i].fi; a[i].se = i+1;
	}
	cin >> m; b.resize(m); sumb.resize(m);
	valb.resize(m); indb.resize(m);
	for (i64 i=0; i<m; i++) {
		cin >> b[i].fi; b[i].se = i+1;
	}
	sort(a.begin(), a.end()); sort(b.begin(), b.end());
	for (i64 i=0; i<m; i++) {
		if (i == 0) {
			sumb[i] = b[i].fi * b[i].se;
			valb[i] = b[i].fi;
			indb[i] = b[i].se;
		}
		else {
			sumb[i] = sumb[i-1] + b[i].fi * b[i].se;
			valb[i] = valb[i-1] + b[i].fi;
			indb[i] = indb[i-1] + b[i].se;
		}
	}
	//cout << "sumb: "; for (i64 i=0; i<m; i++) cout << sumb[i] << " "; cout << endl;
	//cout << "valb: "; for (i64 i=0; i<m; i++) cout << valb[i] << " "; cout << endl;
	//cout << "indb: "; for (i64 i=0; i<m; i++) cout << indb[i] << " "; cout << endl;
}

void ProSolve() {
	for (i64 i=0; i<n; i++) {
		pii mark = mp(a[i].fi, 0);
		i64 pos = lower_bound(b.begin(), b.end(), mark) - b.begin();
		if (pos == 0) {
			ans -= a[i].se * m * a[i].fi + sumb[m-1] - a[i].se * valb[m-1] - a[i].fi * indb[m-1];
			//cout << "- " << a[i].se * m * a[i].fi + sumb[m-1] - a[i].se * valb[m-1] - a[i].fi * indb[m-1] << endl;
		}
		else {
			ans -= a[i].se * (m - pos) * a[i].fi + (sumb[m-1] - sumb[pos-1]) - a[i].se * (valb[m-1] - valb[pos-1]) - a[i].fi * (indb[m-1] - indb[pos-1]);
			//cout << "- " << a[i].se * (valb[m-1] - valb[pos-1]) - (a[i].se * m) * a[i].fi - (sumb[m-1] - sumb[pos-1]) + (indb[m-1] - indb[pos-1]) * a[i].fi << endl;
			ans += a[i].se * pos * a[i].fi + sumb[pos-1] - a[i].se * valb[pos-1] - a[i].fi * indb[pos-1];
			//cout << "+ " << a[i].se * pos * a[i].fi + sumb[pos-1] - a[i].se * valb[pos-1] - a[i].fi * indb[pos-1] << endl;
		}
		//cout << "ans = " << ans << endl;
	}
	cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
