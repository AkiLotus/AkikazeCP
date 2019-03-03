/**
	Template by Akikaze (秋風) - formerly proptit_4t41.
	Code written by a random fan of momocashew and Chiho.
**/

#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define endl '\n'
#define i64 long long
#define ld long double
#define pub push_back
#define mp make_pair
#define fi first
#define se second
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/


/** -----GLOBAL VARIABLES----- **/
i64 sum, lim; vector<vi> cc(100009, vi(24, 0));
vi val(100009, 0); vector<vi> List(24, vi(0));

/** -----EXTENSIVE FUNCTIONS----- **/
i64 solve(i64 z) {
	i64 ans = 0;
	while (z % 2 == 0) {
		ans++; z /= 2;
	}
	return ans;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> sum >> lim;
	for (i64 i=1; i<=lim; i++) {
		for (i64 j=0; j<24; j++) cc[i][j] = cc[i][j-1];
		//cout << "val[" << i << "] = " << solve(i) << endl;
		val[i] = solve(i); cc[i][val[i]]++;
		List[val[i]].pub(i);
	}
}

void ProSolve() {
	vi ans; i64 s = 0;
	for (i64 i=23; i>=0; i--) {
		if (cc[lim][i] == 0) continue;
		i64 tmp = 0;
		while (s + (1 << i) <= sum && tmp < List[i].size()) {
			//cout << "pushed " << List[i][tmp] << endl;
			ans.pub(List[i][tmp]); tmp++;
			s += (1 << i);
		}
	}
	if (s < sum) {cout << "-1"; return;}
	cout << ans.size() << endl;
	for (i64 i=0; i<ans.size(); i++) cout << ans[i] << " ";
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}