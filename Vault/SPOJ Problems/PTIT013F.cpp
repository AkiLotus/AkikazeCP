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
i64 T, n; vector<pii> s(100007);
vi tree(888888), lazy(888888);

/** -----EXTENSIVE FUNCTIONS----- **/
void add(i64 node, i64 st, i64 en, i64 L, i64 R) {
	if (lazy[node] > 0) {
		tree[node] += lazy[node];
		if (st != en) {
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (st > en || en < L || R < st) return;
	if (L <= st && en <= R) {
		tree[node]++;
		if (st != en) {
			lazy[node*2]++;
			lazy[node*2+1]++;
		}
		return;
	}
	add(node*2, st, (st+en)/2, L, R);
	add(node*2+1, (st+en)/2+1, en, L, R);
	tree[node] = max(tree[node*2], tree[node*2+1]);
}

i64 getMax(i64 node, i64 st, i64 en, i64 L, i64 R) {
	if (st > en || en < L || R < st) return -LINF;
	if (lazy[node] > 0) {
		tree[node] += lazy[node];
		if (st != en) {
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (L <= st && en <= R) return tree[node];
	i64 p1 = getMax(node*2, st, (st+en)/2, L, R);
	i64 p2 = getMax(node*2+1, (st+en)/2+1, en, L, R);
	return (max(p1, p2));
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> T;
}

void ProSolve() {
	while (T--) {
		cin >> n; i64 ans = 0; vi lists;
		for (i64 i=0; i<n; i++) {
			cin >> s[i].se >> s[i].fi;
			lists.pub(s[i].fi); lists.pub(s[i].se);
		}
		for (i64 i=0; i<888888; i++) {tree[i] = 0; lazy[i] = 0;}
		sort(lists.begin(), lists.end()); sort(s.begin(), s.begin()+n);
		map<i64, i64> Enum; i64 N = 0;
		for (i64 i=0; i<lists.size(); i++) {
			if (Enum[lists[i]] == 0) Enum[lists[i]] = ++N;
		}
		for (i64 i=0; i<n; i++) {
			add(1, 1, N, Enum[s[i].se], Enum[s[i].fi]);
			ans += getMax(1, 1, N, Enum[s[i].se], Enum[s[i].fi]);
		}
		cout << ans << endl;
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