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
vector<i64> tree(2222222, 0);
vector<i64> lazy(2222222, 0);


/** -----EXTENSIVE FUNCTIONS----- **/
vector<i64> parse(string Q) {
	vector<i64> res(1, 0);
	vector<i64> sign(1, 1);
	i64 ele = 0;
	for (i64 i=0; i<Q.size(); i++) {
		if (Q[i] == ' ') {
			res.pub(0); ele++;
			sign.pub(1);
		}
		else if (Q[i] == '-') sign[ele] = -1;
		else {
			res[ele] *= 10;
			res[ele] += (Q[i] - '0');
		}
	}
	for (i64 i=0; i<res.size(); i++) res[i] *= sign[i];
	return res;
}

void ITbuild(i64 node, i64 left, i64 right) {
	if (left > right) return;
	if (left == right) {
		tree[node] = a[left]; return;
	}
	ITbuild(node*2, left, (left+right)/2);
	ITbuild(node*2+1, (left+right)/2+1, right);
	tree[node] = min(tree[node*2], tree[node*2+1]);
}

void pushDown(i64 node) {
	if (lazy[node] != 0) {
		lazy[node*2] += lazy[node];
		lazy[node*2+1] += lazy[node];
		tree[node*2] += lazy[node];
		tree[node*2+1] += lazy[node];
		lazy[node] = 0;
	}
}

i64 ITget(i64 node, i64 left, i64 right, i64 st, i64 en) {
	if (left > right || left > en || right < st) return LINF;
	if (left == st && right == en) return tree[node];
	pushDown(node);
	i64 p1 = ITget(node*2, left, (left+right)/2, st, en);
	i64 p2 = ITget(node*2+1, (left+right)/2+1, right, st, en);
	return min(p1, p2);
}

void ITupdate(i64 node, i64 left, i64 right, i64 st, i64 en, i64 val) {
	if (left > right || left > en || right < st) return;
	if (st <= left && right <= en) {
		tree[node] += val; lazy[node] += val;
		return;
	}
	pushDown(node);
	ITupdate(node*2, left, (left+right)/2, st, en, val);
	ITupdate(node*2+1, (left+right)/2+1, right, st, en, val);
	tree[node] = min(tree[node*2], tree[node*2+1]);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> N; a.resize(N);
	for (i64 i=0; i<N; i++) cin >> a[i];
	ITbuild(1, 0, N-1);
}

void ProSolve() {
	i64 M; cin >> M;
	string removeBuffer; getline(cin, removeBuffer);
	while (M--) {
		string query; getline(cin, query);
		vector<i64> cmd = parse(query);
		if (cmd.size() == 2) {
			//cout << cmd[0] << " " << cmd[1] << endl;
			if (cmd[0] <= cmd[1]) cout << ITget(1, 0, N-1, cmd[0], cmd[1]) << endl;
			else {
				i64 p1 = ITget(1, 0, N-1, cmd[0], N-1);
				i64 p2 = ITget(1, 0, N-1, 0, cmd[1]);
				cout << min(p1, p2) << endl;
			}
			//for (int i=1; i<8; i++) cout << tree[i] << " "; cout << endl;
			//for (int i=1; i<8; i++) cout << lazy[i] << " "; cout << endl;
		}
		else {
			//cout << cmd[0] << " " << cmd[1] << " " << cmd[2] << endl;
			if (cmd[0] <= cmd[1]) ITupdate(1, 0, N-1, cmd[0], cmd[1], cmd[2]);
			else {
				ITupdate(1, 0, N-1, cmd[0], N-1, cmd[2]);
				ITupdate(1, 0, N-1, 0, cmd[1], cmd[2]);
			}
			//for (int i=1; i<8; i++) cout << tree[i] << " "; cout << endl;
			//for (int i=1; i<8; i++) cout << lazy[i] << " "; cout << endl;
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
