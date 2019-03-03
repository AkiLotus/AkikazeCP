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
	/**
		Solved by pixel-convex hull? (kinda convex hull, but classified by pixels instead)

	**/

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
i64 n, m;
i64 firstOcc = 1, lastOcc;
vector<string> board;
vector<vector<char>> result;
vector<i64> colMin, colMax;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n >> m; board.resize(n, ""); lastOcc = n-1;
	result.resize(n, vector<char>(m, '.'));
	colMin.resize(n, LINF); colMax.resize(n, -LINF);
	for (int i=0; i<n; i++) {
		cin >> board[i]; int tmp = board[i].find('*');
		if (tmp >= 0) {
			colMin[i] = tmp; colMax[i] = board[i].rfind('*');
		}
		if (colMin[i] == LINF) {
			if (firstOcc == i+1) firstOcc++;
		}
	}
	for (int i=n-1; i>=0; i--) {
		if (colMin[i] == LINF) lastOcc = i;
		else break;
	}
}

void ProSolve() {
	for (int i=firstOcc; i<=lastOcc; i++) {
		if (colMin[i] > colMin[i-1]) colMin[i] = colMin[i-1];
		if (colMax[i] < colMin[i-1]) colMax[i] = colMin[i-1];
		else if (colMax[i-1] < colMin[i]) colMax[i-1] = colMax[i];
	}
	for (int i=0; i<n; i++) {
		for (int j=colMin[i]; j<=colMax[i]; j++) result[i][j] = '*';
		for (int j=0; j<m; j++) cout << result[i][j];
		cout << endl;
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	freopen("WIFI3.INP", "r", stdin);
	freopen("WIFI3.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
