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
int n, m;
char board[128][128];
bool row[128];
bool col[128];
int cc[128], rc[128];

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> board[i][j];
			if (board[i][j] == '#') {
				row[i] = true;
				rc[i]++; cc[j]++;
			}
		}
	}
}

void ProSolve() {
	while (true) {
		int maxPos = 1;
		for (int i=2; i<=m; i++) {
			if (cc[maxPos] < cc[i]) maxPos = i;
		}
		int tmp = 0;
		bool tmpConf[128];
		for (int i=0; i<128; i++) tmpConf[i] = false;
		for (int i=1; i<=n; i++) {
			if (!row[i]) continue;
			if (rc[i] == 1) {
				tmp++; tmpConf[i] = true;
			}
			rc[i]--;
		}
		if (tmp <= 1) break;
		for (int i=1; i<=n; i++) {
			if (!row[i]) continue;
			if (tmpConf[i]) row[i] = false;
		}
		col[maxPos] = true;
	}
	int ans = 0;
	for (int i=1; i<=n; i++) ans += row[i];
	for (int i=1; i<=m; i++) ans += col[i];
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
