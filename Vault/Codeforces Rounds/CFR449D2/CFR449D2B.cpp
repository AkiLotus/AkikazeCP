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
i64 k, p, ans = 0;

/** -----EXTENSIVE FUNCTIONS----- **/
i64 digitnum(i64 z) {
	i64 res = 0;
	while (z > 0) {
		res++; z /= 10;
	}
	return res;
}

i64 palin(i64 z) {
	i64 res = 0;
	while (z > 0) {
		res = res * 10 + z % 10;
		z /= 10;
	}
	return res;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> k >> p;
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	for (i64 i=1; i<=k; i++) {
		i64 tmp = i;
		if (digitnum(i) == 1) tmp = tmp * 10 + palin(tmp);
		else if (digitnum(i) == 2) tmp = tmp * 100 + palin(tmp);
		else if (digitnum(i) == 3) tmp = tmp * 1000 + palin(tmp);
		else if (digitnum(i) == 4) tmp = tmp * 10000 + palin(tmp);
		else if (digitnum(i) == 5) tmp = tmp * 100000 + palin(tmp);
		else if (digitnum(i) == 6) tmp = tmp * 1000000 + palin(tmp);
		else if (digitnum(i) == 7) tmp = tmp * 10000000 + palin(tmp);
		ans = (ans + tmp) % p;
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
