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
int T, cas = 0; // for multi-testcase problems
int N, Q; vector<int> A;
int MinTree[555555];
int MaxTree[555555];

/** -----EXTENSIVE FUNCTIONS----- **/
void ITBuild(int node, int left, int right) {
	if (left > right) return;
	if (left == right) {
		MinTree[node] = A[left]; MaxTree[node] = A[left];
		return;
	}
	ITBuild(node*2, left, (left+right)/2);
	ITBuild(node*2+1, (left+right)/2+1, right);
	MinTree[node] = min(MinTree[node*2], MinTree[node*2+1]);
	MaxTree[node] = max(MaxTree[node*2], MaxTree[node*2+1]);
}

int getMinQuery(int node, int left, int right, int st, int en) {
	if (left > right || left > en || right < st) return INF;
	if (left >= st && right <= en) return MinTree[node];
	int p1 = getMinQuery(node*2, left, (left+right)/2, st, en);
	int p2 = getMinQuery(node*2+1, (left+right)/2+1, right, st, en);
	return min(p1, p2);
}

int getMaxQuery(int node, int left, int right, int st, int en) {
	if (left > right || left > en || right < st) return -INF;
	if (left >= st && right <= en) return MaxTree[node];
	int p1 = getMaxQuery(node*2, left, (left+right)/2, st, en);
	int p2 = getMaxQuery(node*2+1, (left+right)/2+1, right, st, en);
	return max(p1, p2);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> N >> Q; A.resize(N, 0);
	for (int i=0; i<N; i++) cin >> A[i];
	ITBuild(1, 0, N-1);
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	while (Q--) {
		int L, R; cin >> L >> R;
		cout << getMaxQuery(1, 0, N-1, L-1, R-1) - getMinQuery(1, 0, N-1, L-1, R-1) << endl;
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
