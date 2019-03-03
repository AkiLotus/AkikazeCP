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
i64 N; vector<ppi> event; vi ans;
priority_queue<i64, vi, greater<i64>> heap;
vi tree(1000007, 0);

/** -----EXTENSIVE FUNCTIONS----- **/
void update(i64 node, i64 st, i64 en, i64 pos) {
	if (st > en || en < pos || pos < st) return;
	if (st == en) {tree[node]++; return;}
	update(node*2, st, (st+en)/2, pos);
	update(node*2+1, (st+en)/2+1, en, pos);
	tree[node] = tree[node*2] + tree[node*2+1];
}

i64 get(i64 node, i64 st, i64 en, i64 L, i64 R) {
	if (st > en || en < L || R < st || L > R) return 0;
	if (L <= st && en <= R) return tree[node];
	i64 p1 = get(node*2, st, (st+en)/2, L, R);
	i64 p2 = get(node*2+1, (st+en)/2+1, en, L, R);
	return (p1 + p2);
}

bool cmp(ppi a, ppi b) {
	if (a.fi.fi > b.fi.fi) return true;
	if (a.fi.fi == b.fi.fi && a.fi.se < b.fi.se) return true;
	return false;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> N; event.resize(N); ans.resize(N, 0);
	for (i64 i=0; i<N; i++) {
		cin >> event[i].fi.fi >> event[i].fi.se;
		event[i].se = i; heap.push(event[i].fi.se);
	}
}

void ProSolve() {
	vi mask(N+1, -LINF); i64 cnt = 0;
	map<i64, i64> Map;
	while (!heap.empty()) {
		i64 z = heap.top(); heap.pop();
		if (mask[cnt] == z) continue;
		cnt++; mask[cnt] = z; Map[z] = cnt;
	}
	for (i64 i=0; i<N; i++) event[i].fi.se = Map[event[i].fi.se];
	sort(event.begin(), event.end(), cmp);
	for (i64 i=0; i<N; i++) {
		if (event[i].fi.se == 1) ans[event[i].se] = 0;
		else ans[event[i].se] = get(1, 1, N, 1, event[i].fi.se-1);
		update(1, 1, N, event[i].fi.se);
	}
	for (i64 i=0; i<N; i++) cout << ans[i] << endl;
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