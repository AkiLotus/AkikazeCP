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
int a[24];

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	for (int i=0; i<24; i++) cin >> a[i];
}

void ProSolve() {
	/*for (int i=0; i<6; i++) {
		cout << a[4*i] << " " << a[4*i+1] << endl << a[4*i+2] << " " << a[4*i+3] << endl << endl;
	}*/
	int faceSolved = 0;
	vector<bool> solved(6, false);
	for (int i=0; i<6; i++) {
		if (a[4*i] == a[4*i+1] && a[4*i+1] == a[4*i+2] && a[4*i+2] == a[4*i+3]) {
			faceSolved++; solved[i] = true;
		}
	}
	if (faceSolved != 2) {
		cout << "NO"; return;
	}
	for (int i=0; i<6; i++) {
		if (i == 0 && solved[i] && !solved[i+2]) {
			cout << "NO"; return;
		}
		if (i == 1 && solved[i] && !solved[i+4]) {
			cout << "NO"; return;
		}
		if (i == 3 && solved[i] && !solved[i+1]) {
			cout << "NO"; return;
		}
	}
	if (solved[0]) {
		if ((a[12] == a[13] && a[13] == a[6] && a[6] == a[7] && a[4] == a[5] && a[5] == a[18] && a[18] == a[19] && a[16] == a[17]
			&& a[17] == a[22] && a[22] == a[23] && a[20] == a[21] && a[21] == a[14] && a[14] == a[15]) ||
			(a[12] == a[13] && a[13] == a[22] && a[22] == a[23] && a[20] == a[21] && a[21] == a[18] && a[18] == a[19] && a[16] == a[17]
			&& a[17] == a[6] && a[6] == a[7] && a[4] == a[5] && a[5] == a[14] && a[14] == a[15])) cout << "YES";
		else cout << "NO";
	}
	else if (solved[1]) {
		if ((a[0] == a[1] && a[1] == a[13] && a[13] == a[15] && a[12] == a[14] && a[14] == a[9] && a[9] == a[8] && a[11] == a[10]
			&& a[10] == a[16] && a[16] == a[18] && a[17] == a[19] && a[19] == a[2] && a[2] == a[3]) ||
			(a[0] == a[1] && a[1] == a[16] && a[16] == a[18] && a[17] == a[19] && a[19] == a[9] && a[9] == a[8] && a[11] == a[10]
			&& a[10] == a[15] && a[15] == a[13] && a[14] == a[12] && a[12] == a[2] && a[2] == a[3])) cout << "YES";
		else cout << "NO";
	}
	else if (solved[3]) {
		if ((a[0] == a[2] && a[2] == a[20] && a[20] == a[22] && a[21] == a[23] && a[23] == a[9] && a[9] == a[11] && a[8] == a[10]
			&& a[10] == a[5] && a[5] == a[7] && a[4] == a[6] && a[6] == a[1] && a[1] == a[3]) ||
			(a[0] == a[2] && a[2] == a[5] && a[5] == a[7] && a[4] == a[6] && a[6] == a[9] && a[9] == a[11] && a[8] == a[10]
			&& a[10] == a[20] && a[20] == a[22] && a[21] == a[23] && a[23] == a[1] && a[1] == a[3])) cout << "YES";
		else cout << "NO";
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
