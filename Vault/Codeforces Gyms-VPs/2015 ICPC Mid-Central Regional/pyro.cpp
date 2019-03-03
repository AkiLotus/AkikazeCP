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
int L;
vector<int> A;
vector<int> cc;
map<int, int> M;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> L;
	while (L != -1) {
		A.pub(L); M[L]++;
		cc.pub(0); cin >> L;
	}
}

void ProSolve() {
	for (int x=0; x<A.size(); x++) {
		for (int i=0; i<18; i++) {
			int tmp = (1 << i);
			if ((A[x] ^ tmp) > A[x] && M[(tmp ^ A[x])]) {
				//cout << "found " << (A[x] ^ tmp) << endl;
				cc[x]++;
			}
			for (int j=i+1; j<18; j++) {
				int tmp2 = (1 << j);
				if ((A[x] ^ (tmp | tmp2)) <= A[x]) continue;
				if (M[(A[x] ^ (tmp | tmp2))]) {
					//cout << "found " << (A[x] ^ (tmp | tmp2)) << endl;
					cc[x]++;
				}
			}
		}
		cout << A[x] << ":" << cc[x] << endl;
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
