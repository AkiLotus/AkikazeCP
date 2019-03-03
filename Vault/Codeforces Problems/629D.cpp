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
i64 n; vector<pii> a;
vi tree(444444, 0);

/** -----EXTENSIVE FUNCTIONS----- **/
void update(i64 node, i64 st, i64 en, i64 pos, i64 val) {
	if (st > en || en < pos || pos < st) return;
	if (st == en) {tree[node] = val; return;}
	update(node*2, st, (st+en)/2, pos, val);
	update(node*2+1, (st+en)/2+1, en, pos, val);
	tree[node] = max(tree[node*2], tree[node*2+1]);
}

i64 get(i64 node, i64 st, i64 en, i64 L, i64 R) {
	if (st > en || en < L || R < st || L > R) return 0;
	if (L <= st && en <= R) return tree[node];
	i64 p1 = get(node*2, st, (st+en)/2, L, R);
	i64 p2 = get(node*2+1, (st+en)/2+1, en, L, R);
	return (max(p1, p2));
}

bool cmp(pii a, pii b) {
	if (a.fi < b.fi) return true;
	if (a.fi == b.fi && a.se > b.se) return true;
	return false;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n; a.resize(n);
	for (i64 i=0; i<n; i++) {
		i64 r, h; cin >> r >> h;
		a[i].fi = r * r * h; a[i].se = i+1;
	}
}

void ProSolve() {
	sort(a.begin(), a.end(), cmp);
	for (i64 i=0; i<n; i++) {
		i64 mx = get(1, 1, n, 1, a[i].se-1);
		update(1, 1, n, a[i].se, mx+a[i].fi);
	}
	cout << fixed << setprecision(8) << ((ld)PI * get(1, 1, n, 1, n));
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