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
i64 N, B, pos;
vector<i64> A, diff;


/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> N >> B;
	A.resize(N); diff.resize(N, 0);
	for (i64 i=0; i<N; i++) {
		cin >> A[i];
		if (A[i] == B) pos = i;
	}
}

void ProSolve() {
	map<i64, i64> frontal;
	map<i64, i64> behind;
	i64 ans = 0;
	for (i64 i=pos-1; i>=0; i--) {
		diff[i] = diff[i+1];
		if (A[i] < B) diff[i]--;
		else diff[i]++;
		frontal[diff[i]]++;
	}
	for (i64 i=pos+1; i<N; i++) {
		diff[i] = diff[i-1];
		if (A[i] < B) diff[i]--;
		else diff[i]++;
		behind[diff[i]]++;
	}
	for (i64 i=pos-1; i>=0; i--) {
		//tracker1(diff[i]);
		//cout << behind[-diff[i]] << endl;
		ans += behind[-diff[i]];
	}
	for (i64 i=pos+1; i<N; i++) {
		//tracker1(diff[i]);
		//cout << frontal[-diff[i]] << endl;
		ans += frontal[-diff[i]];
	}
	ans = ans / 2 + 1;
	ans += (frontal[0] + behind[0]);
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
