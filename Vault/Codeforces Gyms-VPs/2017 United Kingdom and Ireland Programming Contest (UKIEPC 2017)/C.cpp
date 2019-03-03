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
vector<int> col(8, 0);

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n;
	while (n--) {
		string color; cin >> color;
		if (color == "red") col[1]++;
		if (color == "yellow") col[2]++;
		if (color == "green") col[3]++;
		if (color == "brown") col[4]++;
		if (color == "blue") col[5]++;
		if (color == "pink") col[6]++;
		if (color == "black") col[7]++;
	}
}

void ProSolve() {
	if (col[1] == 0) {
		int ans = 0;
		for (int i=0; i<8; i++) ans += i * col[i];
		cout << ans; return;
	}
	if (col[2] == 0 && col[3] == 0 && col[4] == 0 && col[5] == 0 && col[6] == 0 && col[7] == 0) {cout << 1; return;}
	int ans = col[1], mx = 0;
	for (int i=2; i<8; i++) {
		if (col[i] > 0) {
			mx = i;
		}
		ans += col[i] * i;
	}
	ans += mx * col[1];
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
