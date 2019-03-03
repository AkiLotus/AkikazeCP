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
int T, cas = 0;

// functions here


/* -----COMPULSORY FUNCTIONS----- */
void VarInput() {
	cin >> T;
}

void ProSolve() {
	cout << "Case " << ++cas << ": ";
	i64 n, k; cin >> n >> k;
	vector<pii> divi;
	for (i64 i=2; i<=sqrt(k); i++) {
		if (k % i == 0) {
			i64 tmp = 0;
			while (k % i == 0) {
				k /= i; tmp++;
			}
			divi.pub(mp(i, tmp));
		}
	}
	if (k != 1) divi.pub(mp(k, 1));
	i64 ans = LINF;
	for (i64 i=0; i<divi.size(); i++) {
		i64 d = divi[i].fi;
		i64 divisor = d;
		i64 tmpExp = 0;
		while (divisor <= n) {
			tmpExp += n / divisor;
			divisor *= d;
		}
		ans = min(ans, tmpExp/divi[i].se);
	}
	cout << ans << endl;
}

/* -----MAIN FUNCTION----- */
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	while(T--) ProSolve();
	return 0;
}
