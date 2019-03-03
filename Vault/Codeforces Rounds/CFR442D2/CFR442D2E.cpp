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
int n, q; vector<int> state;
int desc[222222];
int tree[222222], lazy[222222];
vector<int> adj[222222];


/** -----EXTENSIVE FUNCTIONS----- **/
void ITBuild(int z) {
	int ans = 0, cc = 0;
	for (int i=0; i<adj[z].size(); i++) {
		ITBuild(adj[z][i]);
		ans += tree[adj[z][i]];
		cc += desc[adj[z][i]];
	}
	tree[z] = state[z] + ans;
	desc[z] = cc + 1;
}

int ITget(int z) {
	if (lazy[z] != 0) {
		tree[z] = (desc[z] - tree[z]);
		for (int i=0; i<adj[z].size(); i++) {
			lazy[adj[z][i]] = (lazy[adj[z][i]] + lazy[z]) % 2;
		}
		lazy[z] = 0;
	}
	return tree[z];
}

void ITpow(int z) {
	if (lazy[z] == 0) {
		tree[z] = (desc[z] - tree[z]);
		for (int i=0; i<adj[z].size(); i++) lazy[adj[z][i]] = (lazy[adj[z][i]] + 1) % 2;
	}
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n; state.resize(n+1, 0);
	for (int i=2; i<=n; i++) {
		int p; cin >> p;
		adj[p].pub(i);
	}
	for (int i=1; i<=n; i++) cin >> state[i];
	ITBuild(1);
	for (int i=1; i<=n; i++) cout << desc[i] << " "; cout << endl;
	for (int i=1; i<=n; i++) cout << tree[i] << " "; cout << endl;
	for (int i=1; i<=n; i++) cout << lazy[i] << " "; cout << endl;
}

void ProSolve() {
	cin >> q;
	while (q--) {
		string cmd; int node; cin >> cmd >> node;
		if (cmd == "get") {
			cout << ITget(node) << endl;
			for (int i=1; i<=n; i++) cout << tree[i] << " "; cout << endl;
			for (int i=1; i<=n; i++) cout << lazy[i] << " "; cout << endl;
		}
		else {
			ITpow(node);
			for (int i=1; i<=n; i++) cout << tree[i] << " "; cout << endl;
			for (int i=1; i<=n; i++) cout << lazy[i] << " "; cout << endl;
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
