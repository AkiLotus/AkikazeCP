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

template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
//int T, cas = 0; // for multi-testcase problems
string z; i64 n;
vector<i64> origin, mirror;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> z; n = z.size();
	origin.resize(n, 0);
	mirror.resize(n, 0);
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	for (i64 i=1; i<n; i++) {
		origin[i] = origin[i-1]; mirror[i] = mirror[i-1];
		if (z[i] == ')' && z[i-1] == ':') origin[i]++;
		if (z[i] == ':' && z[i-1] == '(') mirror[i]++;
	}
	i64 ans = origin[n-1];
	for (i64 i=0; i<n; i++) {
		cout << mirror[i] << " " << origin[n-1] - origin[i] << endl;
		i64 tmp = mirror[i] + (origin[n-1] - origin[i]);
		if (i < n-1 && z[i] == ':' && z[0] != ':' && z[i+1] == ')') tmp--;
		ans = max(ans, tmp);
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
