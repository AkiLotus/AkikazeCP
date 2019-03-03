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
i64 N; vector<i64> a, ans;
vector<i64> tree(1111111, 0);

/** -----EXTENSIVE FUNCTIONS----- **/
void BuildIT(i64 node, i64 st, i64 en) {
	if (st > en) return;
	if (st == en) {
		tree[node] = a[st]; return;
	}
	BuildIT(node*2, st, (st+en)/2);
	BuildIT(node*2+1, (st+en)/2+1, en);
	tree[node] = max(tree[node*2], tree[node*2+1]);
}

i64 GetQuery(i64 node, i64 st, i64 en, i64 L, i64 R) {
	//cout << node << " " << st << " " << en << " " << L << " " << R << endl;
	//cout << (st > en) << endl; cout << (en < L) << endl; cout << (R < st) << endl;
	if (en < L || R < st) return -1;
	if (L <= st && en <= R) return tree[node];
	if (tree[node*2] > a[L-1] && !((st+en)/2 < L || R < st)) return GetQuery(node*2, st, (st+en)/2, L, R);
	else if (tree[node*2+1] > a[L-1] && !(en < L || R < (st+en)/2+1)) return GetQuery(node*2+1, (st+en)/2+1, en, L, R);
	else return -1;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> N; a.resize(N, 0LL);
	ans.resize(N, -1);
	for (i64 i=0; i<N; i++) cin >> a[i];
	BuildIT(1, 0, N-1);
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	for (i64 i=0; i<N; i++) {
		if (i == N-1) cout << "-1";
		else cout << GetQuery(1, 0, N-1, i+1, N-1) << " ";
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
