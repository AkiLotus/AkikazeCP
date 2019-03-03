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
i64 N; vector<i64> a;
bool zeroFound = false;
bool oddFound = false;
i64 tmp = 1;
map<i64, i64> M;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> N;
	for (i64 i=0; i<N; i++) {
		i64 x; cin >> x;
		if (x == 0) zeroFound = true;
		if (x == tmp) tmp *= 2;
		else {
			M[x]++;
			if (M[x] == 1) a.pub(x);
		}
	}
}

void ProSolve() {
	if (a.empty()) {
		cout << (tmp / 2 + 1); return;
	}
	i64 maximal = *max_element(a.begin(), a.end());
	if (zeroFound) {
		cout << tmp; return;
	}
	i64 minPower = LINF;
	for (i64 i=0; i<a.size(); i++) {
		i64 zzz = a[i], power = 0;
		while (zzz % 2 == 0) {
			zzz /= 2; power++;
		}
		minPower = min(power, minPower);
	}
	i64 Tmp = 0, maxcc = 0;
	for (i64 i=0; i<a.size(); i++) {
		if ((a[i] / (1 << minPower)) % 2 == 1 && M[a[i]] >= maxcc && tmp - a[i] > maximal) {
			maxcc = M[a[i]]; Tmp = a[i];
		}
	}
	cout << tmp - Tmp;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("A.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
