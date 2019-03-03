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

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n;
}

void ProSolve() {
	if (n == 1) cout << "1\n";
	else if (n == 2) cout << "50\n";
	else {
		for (int i=0; i<n-2; i++) cout << "9"; cout << "50\n";
	}
	if (n == 1) cout << "9\n";
	else {
		cout << "1";
		for (int i=0; i<n-2; i++) cout << "0";
		cout << "9\n";
	}
	if (n == 1) cout << "0\n";
	else if (n == 2) cout << "25\n";
	else {
		string ans = ""; for (int i=0; i<n; i++) ans += "9";
		int change = 81 * n;
		int pos = n-1;
		while (change > 0) {
			int tmp = change % 10;
			ans[pos--] -= tmp;
			change /= 10;
		}
		ans[n-1] += 8; ans[n-2] += 8;
		pos = n-1;
		while (pos > 0 || ans[pos] > '9') {
			if (ans[pos] <= '9') {
				pos--; continue;
			}
			ans[pos] -= 10; ans[--pos] += 1;
		}
		cout << ans << endl;
	}
	if (n == 1) cout << "-72";
	else if (n == 2) cout << "-63";
	else {
		for (int i=0; i<n-3; i++) cout << "9";
		cout << "27";
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
