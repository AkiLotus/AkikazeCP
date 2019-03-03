/**
	Template by Akikaze (秋風) - formerly proptit_4t41.
	Code written by a random fan of momocashew and Chiho.
**/

#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define endl '\n'
#define i64 long long
#define ld long double
#define pub push_back
#define mp make_pair
#define fi first
#define se second
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/
struct Node {
	i64 val = 0;
	i64 lazy = 0;
};

/** -----GLOBAL VARIABLES----- **/
i64 n, m;
vector<Node> tree(666666);

/** -----EXTENSIVE FUNCTIONS----- **/
void update(i64 node, i64 st, i64 en, i64 L, i64 R, i64 x) {
	if (tree[node].lazy > 0) {
		tree[node].val += tree[node].lazy;
		if (st != en) {
			tree[node*2].lazy += tree[node].lazy;
			tree[node*2+1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
	if (st > en || st > R || en < L) return;
	if (L <= st && en <= R) {
		tree[node].val += x;
		if (st != en) {
			tree[node*2].lazy += x;
			tree[node*2+1].lazy += x;
		}
		return;
	}
	update(node*2, st, (st+en)/2, L, R, x);
	update(node*2+1, (st+en)/2+1, en, L, R, x);
	tree[node].val = max(tree[node*2].val, tree[node*2+1].val);
}

i64 get(i64 node, i64 st, i64 en, i64 L, i64 R) {
	if (st > en || st > R || en < L) return -LINF;
	if (tree[node].lazy > 0) {
		tree[node].val += tree[node].lazy;
		if (st != en) {
			tree[node*2].lazy += tree[node].lazy;
			tree[node*2+1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
	if (L <= st && en <= R) return tree[node].val;
	i64 p1 = get(node*2, st, (st+en)/2, L, R);
	i64 p2 = get(node*2+1, (st+en)/2+1, en, L, R);
	return max(p1, p2);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n >> m;
}

void ProSolve() {
	while (m--) {
		i64 cmd, l, r; cin >> cmd >> l >> r;
		if (cmd == 0) {
			i64 value; cin >> value;
			update(1, 1, n, l, r, value);
		}
		else cout << get(1, 1, n, l, r) << endl;
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}