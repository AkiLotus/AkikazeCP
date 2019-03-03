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
i64 N;
i64 pYu = 0, pYe = 0;
i64 Yu10 = 0, Ye10 = 0;
i64 YuX = 0, YeX = 0;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> N;
	for (i64 i=0; i<N; i++) {
		string res; cin >> res;
		if (res.size() == 2) {
			pYu += 10; Yu10++;
		}
		else {
			if (res[0] >= '0' && res[0] <= '9') pYu += res[0] - '0';
			else if (res[0] == 'X') {
				pYu += 10; YuX++; Yu10++;
			}
		}
	}
	for (i64 i=0; i<N; i++) {
		string res; cin >> res;
		if (res.size() == 2) {
			pYe += 10; Ye10++;
		}
		else {
			if (res[0] >= '0' && res[0] <= '9') pYe += res[0] - '0';
			else if (res[0] == 'X') {
				pYe += 10; YeX++; Ye10++;
			}
		}
	}
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	if (pYu > pYe) cout << "Yuju";
	else if (pYu < pYe) cout << "Yerin";
	else if (Yu10 > Ye10) cout << "Yuju";
	else if (Yu10 < Ye10) cout << "Yerin";
	else if (YuX > YeX) cout << "Yuju";
	else if (YuX < YeX) cout << "Yerin";
	else cout << "Shoot-off";
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
