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
vector<bool> found(1000, false);
vector<vector<int>> cube;
int n;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n; cube.resize(n, vector<int>(6));
	for (int i=0; i<n; i++) {
		for (int j=0; j<6; j++) {
			cin >> cube[i][j];
		}
	}
}

void ProSolve() {
	if (n == 1) {
		for (int i=1; i<=10; i++) {
			if (find(cube[0].begin(), cube[0].end(), i) == cube[0].end()) {
				cout << i-1; return;
			}
		}
	}
	if (n == 2) {
		for (int i=0; i<6; i++) {
			if (cube[0][i] == 0) continue;
			found[cube[0][i]] = true;
			for (int j=0; j<6; j++) {
				found[cube[1][j]] = true;
				found[10*cube[0][i]+cube[1][j]] = true;
			}
		}
		for (int i=0; i<6; i++) {
			if (cube[1][i] == 0) continue;
			for (int j=0; j<6; j++) {
				found[10*cube[1][i]+cube[0][j]] = true;
			}
		}
		for (int i=1; i<=100; i++) {
			if (!found[i]) {
				cout << i-1; return;
			}
		}
	}
	if (n == 3) {
		for (int i=0; i<6; i++) {
			if (cube[0][i] == 0) continue;
			for (int j=0; j<6; j++) {
				found[10*cube[0][i]+cube[1][j]] = true;
				found[10*cube[0][i]+cube[2][j]] = true;
			}
		}
		for (int i=0; i<6; i++) {
			if (cube[1][i] == 0) continue;
			for (int j=0; j<6; j++) {
				found[10*cube[1][i]+cube[2][j]] = true;
				found[10*cube[1][i]+cube[0][j]] = true;
			}
		}
		for (int i=0; i<6; i++) {
			if (cube[2][i] == 0) continue;
			for (int j=0; j<6; j++) {
				found[10*cube[2][i]+cube[0][j]] = true;
				found[10*cube[2][i]+cube[1][j]] = true;
			}
		}
		for (int i=0; i<6; i++) {
			if (cube[0][i] == 0) continue;
			found[cube[0][i]] = true;
			for (int j=0; j<6; j++) {
				found[cube[1][j]] = true;
				for (int k=0; k<6; k++) {
					found[cube[2][k]] = true;
					found[100*cube[0][i]+10*cube[1][j]+cube[2][k]] = true;
				}
			}
		}
		for (int i=1; i<=1000; i++) {
			if (!found[i]) {
				cout << i-1; return;
			}
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
