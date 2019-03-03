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
i64 N, Q; vi A;
vi tree(444444, 0);

/** -----EXTENSIVE FUNCTIONS----- **/
void IT_build(i64 n, i64 st, i64 en) {
	if (st > en) return;
	if (st == en) {
		tree[n] = A[st]; return;
	}
	IT_build(n*2, st, (st+en)/2);
	IT_build(n*2+1, (st+en)/2+1, en);
	tree[n] = max(tree[n*2], tree[n*2+1]);
}

i64 get(i64 n, i64 st, i64 en, i64 L, i64 R) {
	if (st > en || st > R || en < L) return -LINF;
	if (L <= st && en <= R) {
		return tree[n];
	}
	i64 z1 = get(n*2, st, (st+en)/2, L, R);
	i64 z2 = get(n*2+1, (st+en)/2+1, en, L, R);
	return max(z1, z2);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> N >> Q; A.resize(N);
	for (i64 i=0; i<N; i++) cin >> A[i];
	IT_build(1, 0, N-1);
}

void ProSolve() {
	while (Q--) {
		i64 d, ans = LINF; cin >> d;
		for (i64 i=0; i<=N-d; i++) ans = min(ans, get(1, 0, N-1, i, i+d-1));
		cout << ans << endl;
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}