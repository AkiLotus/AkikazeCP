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
int n;
int ans = 0;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n;
	while (n--) {
		int x; cin >> x;
		if (x == 0) ans += 32;
		else ans += 16/x;
	}
}

void ProSolve() {
	cout << ans/16;
	if (ans % 16 == 8) cout << ".5";
	else if (ans % 16 == 4) cout << ".25";
	else if (ans % 16 == 2) cout << ".125";
	else if (ans % 16 == 1) cout << ".0625";
	else if (ans % 16 == 3) cout << ".1875";
	else if (ans % 16 == 5) cout << ".3125";
	else if (ans % 16 == 6) cout << ".375";
	else if (ans % 16 == 7) cout << ".4375";
	else if (ans % 16 == 9) cout << ".5625";
	else if (ans % 16 == 10) cout << ".625";
	else if (ans % 16 == 11) cout << ".6875";
	else if (ans % 16 == 12) cout << ".75";
	else if (ans % 16 == 13) cout << ".8125";
	else if (ans % 16 == 14) cout << ".875";
	else if (ans % 16 == 15) cout << ".9375";
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
