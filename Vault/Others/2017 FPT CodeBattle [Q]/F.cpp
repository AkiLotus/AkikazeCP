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
i64 T; // for multi-testcase problems
i64 N, ans = 0;
vector<i64> dp;
vector<bool> searched;
vector<bool> visited;
vector<vector<i64>> asc;
vector<vector<i64>> des;
queue<i64> Q;

/** -----EXTENSIVE FUNCTIONS----- **/
void findRoot(i64 z) {
	if (searched[z]) return;
	searched[z] = true;
	if (asc[z].size() == 0) {
		Q.push(z); dp[z] = 1;
		visited[z] = true; return;
	}
	for (i64 i=0; i<asc[z].size(); i++) findRoot(asc[z][i]);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> T; // for multi-testcase problems
}

void ProSolve() {
	asc.clear(); des.clear(); dp.clear(); searched.clear(); visited.clear(); ans = 0;
	while (!Q.empty()) Q.pop();
	cin >> N;
	dp.resize(N, 0); searched.resize(N, false); visited.resize(N, false);
	asc.resize(N, vector<i64>(0)); des.resize(N,vector<i64>(0));
	for (i64 i=1; i<N; i++) {
		i64 a, b; string ope; cin >> a >> ope >> b;
		if (ope == "<") {
			asc[b].pub(a); des[a].pub(b);
		}
		else {
			asc[a].pub(b); des[b].pub(a);
		}
	}
	for (i64 i=0; i<N; i++) findRoot(i);
	while (!Q.empty()) {
		i64 tmp = Q.front(); Q.pop();
		//tracker1(tmp);
		//cout << "dp[" << tmp << "] = " << dp[tmp] << endl;
		if (des[tmp].size() == 0) {
			ans = (ans + dp[tmp]) % MOD; continue;
		}
		for (i64 i=0; i<des[tmp].size(); i++) {
			if (!visited[des[tmp][i]]) {
				Q.push(des[tmp][i]); visited[des[tmp][i]] = true;
			}
			dp[des[tmp][i]] = (dp[des[tmp][i]] + dp[tmp]) % MOD;
		}
		//cout << "ans = " << ans << endl;
	}
	cout << ans << endl;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	while(T--) ProSolve(); // for multi-testcase problems
	//ProSolve(); // for regular problems
	return 0;
}
