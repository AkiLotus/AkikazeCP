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
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

/** -----IDEAS/ALGORITHMS----- **/


/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
i64 n;
vector<pii> a;
vector<pii> Win, Not;
vector<bool> merged;
vector<i64> couple;

/** -----EXTENSIVE FUNCTIONS----- **/

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n;
	merged.resize(n+1, false); couple.resize(n+1, -1);
	for (i64 i=0; i<n; i++) {
		i64 A, B; cin >> A >> B;
		a.pub(mp((A-B), i+1));
		if (A - B > 0) Win.pub(mp(A-B, i+1));
		else Not.pub(mp(A-B, i+1));
	}
	sort(Win.begin(), Win.end()); sort(Not.begin(), Not.end(), greater<pii>());
}

void ProSolve() {
	i64 possible = 0, iter = Not.size()-1;
	i64 winSize = Win.size();
	for (i64 i=iter; i>=0; i--) {
		if (winSize * 2 > n - possible) break;
		i64 pos = Not[i].se;
		if (pos == 1) {
			if (a[pos].fi + Not[i].fi > 0 && !merged[pos+1]) {
				merged[pos] = true; merged[pos+1] = true;
				couple[pos] = pos+1; couple[pos+1] = pos;
				possible++;
				if (winSize * 2 > n - possible) break;
			}
		}
		else if (pos == n) {
			if (a[pos-2].fi + Not[i].fi > 0 && !merged[pos-1]) {
				merged[pos] = true; merged[pos-1] = true;
				couple[pos] = pos-1; couple[pos-1] = pos;
				possible++;
				if (winSize * 2 > n - possible) break;
			}
		}
		else {
			if (a[pos].fi + Not[i].fi > 0 && a[pos-2].fi + Not[i].fi <= 0 && !merged[pos+1]) {
				merged[pos] = true; merged[pos+1] = true;
				couple[pos] = pos+1; couple[pos+1] = pos;
				possible++;
				if (winSize * 2 > n - possible) break;
			}
			else if (a[pos].fi + Not[i].fi <= 0 && a[pos-2].fi + Not[i].fi > 0 && !merged[pos-1]) {
				merged[pos] = true; merged[pos-1] = true;
				couple[pos] = pos-1; couple[pos-1] = pos;
				possible++;
				if (winSize * 2 > n - possible) break;
			}
			else if (a[pos].fi + Not[i].fi > 0 && a[pos-2].fi + Not[i].fi > 0) {
				if (a[pos].fi < a[pos-2].fi && !merged[pos+1]) {
					merged[pos] = true; merged[pos+1] = true;
					couple[pos] = pos+1; couple[pos+1] = pos;
					possible++;
					if (winSize * 2 > n - possible) break;
				}
				else if (!merged[pos-1]) {
					merged[pos] = true; merged[pos-1] = true;
					couple[pos] = pos-1; couple[pos-1] = pos;
					possible++;
					if (winSize * 2 > n - possible) break;
				}
			}
		}
	}
	if (winSize * 2 <= n - possible) cout << "-1";
	else {
		cout << possible << endl;
		for (i64 i=1; i<=n; i++) {
			if (couple[i] > i) cout << i << " " << couple[i] << endl;
		}
	}
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
