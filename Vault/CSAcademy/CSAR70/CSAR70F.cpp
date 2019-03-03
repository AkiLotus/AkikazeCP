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
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef pair<pii, int> ppi;

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/
struct Node {
	int mx[20], sm[20], lazy[20], val = 0;
	Node() {
		for (int i=0; i<20; i++) {
			mx[i] = 0; sm[i] = 0;
			lazy[i] = 0; val = 0;
		}
	}
};

/** -----GLOBAL VARIABLES----- **/
int N, Q; vi A, Query;
vector<Node> tree(1000007);

/** -----EXTENSIVE FUNCTIONS----- **/
void STBuild(int node, int st, int en) {
	if (st > en) return;
	if (st == en) {
		int tmp = A[st]; tree[node].val = A[st];
		for (int i=0; i<20; i++) {
			tree[node].mx[i] = tmp % 2;
			tree[node].sm[i] = tmp % 2;
			tmp /= 2;
		}
		return;
	}
	STBuild(node*2+0, st, (st+en)/2);
	STBuild(node*2+1, (st+en)/2+1, en);
	for (int i=0; i<20; i++) {
		tree[node].mx[i] = max(tree[node*2].mx[i], tree[node*2+1].mx[i]);
		tree[node].sm[i] = tree[node*2].sm[i] + tree[node*2+1].sm[i];
		tree[node].val = max(tree[node*2].val, tree[node*2+1].val);
	}
}

void update(int node, int st, int en, int L, int R, int val, int And, int i) {
	if (st > en || en < L || R < st) return;
	int tmp = val % 2;
	if (tree[node].lazy[i] == -1) {
		int MODAL = (1 << 20) - 1 - (1 << i);
		tree[node].sm[i] = 0; tree[node].mx[i] = 0;
		tree[node].val &= MODAL;
		tree[node*2+0].lazy[i] = -1;
		tree[node*2+1].lazy[i] = -1;
		tree[node].lazy[i] = 0;
	}
	else if (tree[node].lazy[i] == 1) {
		int MODAL = (1 << i);
		tree[node].sm[i] = (en-st+1); tree[node].mx[i] = 1;
		tree[node].val |= MODAL;
		tree[node*2+0].lazy[i] = 1;
		tree[node*2+1].lazy[i] = 1;
		tree[node].lazy[i] = 0;
	}
	if (L <= st && en <= R) {
		if (And && !tmp) {
			int MODAL = (1 << 20) - 1 - (1 << i);
			tree[node].sm[i] = 0;
			tree[node].mx[i] = 0;
			tree[node].val &= MODAL;
			tree[node*2+0].lazy[i] = -1;
			tree[node*2+1].lazy[i] = -1;
		}
		else if (!And && tmp) {
			int MODAL = (1 << i);
			tree[node].sm[i] = (en - st + 1);
			tree[node].mx[i] = 1;
			tree[node].val |= MODAL;
			tree[node*2+0].lazy[i] = 1;
			tree[node*2+1].lazy[i] = 1;
		}
		return;
	}
	update(node*2, st, (st+en)/2, L, R, val, And, i);
	update(node*2+1, (st+en)/2+1, en, L, R, val, And, i);
	tree[node].mx[i] = max(tree[node*2].mx[i], tree[node*2+1].mx[i]);
	tree[node].sm[i] = tree[node*2].sm[i] + tree[node*2+1].sm[i];
	tree[node].val = max(tree[node*2].val, tree[node*2+1].val);
}

int get(int node, int st, int en, int L, int R) {
	//tracker3(node, st, en);
	if (st > en || en < L || R < st) return -INF;
	for (int i=0; i<20; i++) {
		if (tree[node].lazy[i] == -1) {
			int MODAL = (1 << 20) - 1 - (1 << i);
			tree[node].sm[i] = 0; tree[node].mx[i] = 0;
			tree[node].val &= MODAL;
			tree[node*2+0].lazy[i] = -1;
			tree[node*2+1].lazy[i] = -1;
			tree[node].lazy[i] = 0;
		}
		else if (tree[node].lazy[i] == 1) {
			int MODAL = (1 << i);
			tree[node].sm[i] = (en-st+1); tree[node].mx[i] = 1;
			tree[node].val |= MODAL;
			tree[node*2+0].lazy[i] = 1;
			tree[node*2+1].lazy[i] = 1;
			tree[node].lazy[i] = 0;
		}
	}
	if (L <= st && en <= R) return tree[node].val;
	int p1 = get(node*2, st, (st+en)/2, L, R);
	int p2 = get(node*2+1, (st+en)/2+1, en, L, R);
	return (max(p1, p2));
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> N >> Q; A.resize(N+1); Query.resize(Q);
	for (int i=1; i<=N; i++) cin >> A[i];
	STBuild(1, 1, N);
}

void ProSolve() {
	while (Q--) {
		int cmd, L, R; cin >> cmd >> L >> R;
		if (cmd == 3) cout << get(1, 1, N, L, R) << endl;
		else {
			int X; cin >> X;
			for (int i=0; i<20; i++) {
				if (cmd == 1) update(1, 1, N, L, R, X, true, i);
				else update(1, 1, N, L, R, X, false, i);
				X /= 2;
			}
		}
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
			#ifdef Akikaze
			//freopen("FILE.INP", "r", stdin);
			//freopen("FILE.OUT", "w", stdout);
			#endif
	VarInput();
			#ifdef Akikaze
			auto TIME1 = chrono::steady_clock::now();
			#endif
	ProSolve();
			#ifdef Akikaze
			auto TIME2 = chrono::steady_clock::now();
			auto DIFF = TIME2 - TIME1;
			cout << "\n\nTime elapsed: " << fixed << setprecision(18) << chrono::duration<double>(DIFF).count() << " seconds.";
			#endif
	return 0;
}