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

/** -----GLOBAL VARIABLES----- **/
i64 n, m, q;
vi A(55555), tree(666666);

/** -----EXTENSIVE FUNCTIONS----- **/
void build(i64 node, i64 st, i64 en) {
	if (st > en) return;
	if (st == en) {
		tree[node] = A[st];
		return;
	}
	build(node*2, st, (st+en)/2);
	build(node*2+1, (st+en)/2+1, en);
	tree[node] = max(tree[node*2], tree[node*2+1]);
}

i64 get(i64 node, i64 st, i64 en, i64 L, i64 R) {
	if (st > en || st > R || en < L) return -LINF;
	if (L <= st && en <= R) return tree[node];
	i64 p1 = get(node*2, st, (st+en)/2, L, R);
	i64 p2 = get(node*2+1, (st+en)/2+1, en, L, R);
	return max(p1, p2);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n >> m;
	while (m--) {
		i64 u, v, k; cin >> u >> v >> k;
		A[u] += k; A[v+1] -= k;
	}
	for (i64 i=2; i<=n; i++) A[i] += A[i-1];
	build(1, 1, n);
}

void ProSolve() {
	cin >> q;
	while (q--) {
		i64 u, v; cin >> u >> v;
		cout << get(1, 1, n, u, v) << endl;
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}