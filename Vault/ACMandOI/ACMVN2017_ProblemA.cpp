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
	First, to recap, for each updating query, it's in fact:
		The i-th index (1-indexed) will be added/subtracted by (i-u+1)(i-u+2)(i-u+3)
			(provided it is inside the selected segment).
		Or, in another meaning (to make the value NOT dependent on i, since i is NOT static,
			provided that the selected segment is [u,v], we can see the value is as following:
		i^3 + (-3u+6) * i^2 + (3u^2 - 12u + 11) * i + (-u^3 + 6u^2 - 11u + 6)
								
	With the new expression, we can store a few information inside each node of a segment tree:
		First, the value of that node (given by the initial A array).
		Second, the coefficients of i^3.
		Third, the coefficients of i^2.
		Fourth, the coefficients of i^1.
		Fifth, the coefficients of i.
		Each of the 4 aforementioned arguments is used as lazy-propagation value.
    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/
class Node {
	public:
	i64 value = 0;
	vi lazy{vi(4, 0)};
};

/** -----GLOBAL VARIABLES----- **/
vector<vi> power(4, vi(100007, 0));
vector<Node> mainST(666666);
i64 N, M;

/** -----EXTENSIVE FUNCTIONS----- **/
i64 lookup(i64 arg, i64 num) {
	if (num == 0) return (-arg*arg*arg + 6*arg*arg - 11*arg + 6);
	if (num == 1) return (3*arg*arg - 12*arg + 11);
	if (num == 2) return (-3*arg + 6);
	if (num == 3) return 1;
}

void add(i64 node, i64 val, i64 num, i64 st, i64 en) {
	mainST[node].value += val * (power[num][en] - power[num][st-1]);
	mainST[node].value %= MOD; while (mainST[node].value < 0) mainST[node].value += MOD;
}

void flow(i64 node, i64 val, i64 num) {
	for (i64 j=0; j<2; j++) {
		mainST[node*2+j].lazy[num] += val;
		mainST[node*2+j].lazy[num] %= MOD;
	}
}

void update(i64 node, i64 st, i64 en, i64 L, i64 R, bool positive) {
	for (i64 i=0; i<4; i++) {
		add(node, mainST[node].lazy[i], i, st, en);
		if (st != en) flow(node, mainST[node].lazy[i], i);
		mainST[node].lazy[i] = 0;
	}
	if (st > en || en < L || st > R) return;
	if (L <= st && en <= R) {
		for (i64 i=0; i<4; i++) {
			i64 tmp = lookup(L, i);
			if (!positive) tmp = -tmp;
			add(node, tmp, i, st, en);
			if (st != en) flow(node, tmp, i);
		}
		return;
	}
	update(node*2+0, st, (st+en)/2, L, R, positive);
	update(node*2+1, (st+en)/2+1, en, L, R, positive);
	mainST[node].value = (mainST[node*2+0].value + mainST[node*2+1].value) % MOD;
	while (mainST[node].value < 0) mainST[node].value += MOD;
}

i64 get(i64 node, i64 st, i64 en, i64 L, i64 R) {
	if (st > en || en < L || st > R) return 0;
	for (i64 i=0; i<4; i++) {
		add(node, mainST[node].lazy[i], i, st, en);
		if (st != en) flow(node, mainST[node].lazy[i], i);
		mainST[node].lazy[i] = 0;
	}
	if (L <= st && en <= R) return mainST[node].value;
	i64 p1 = get(node*2, st, (st+en)/2, L, R);
	i64 p2 = get(node*2+1, (st+en)/2+1, en, L, R);
	i64 ans = ((p1 + p2) % MOD);
	while (ans < 0) ans += MOD;
	return ans;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	for (i64 i=0; i<100007; i++) {
		power[0][i] = (power[0][i-1] + 1) % MOD;
		power[1][i] = (power[1][i-1] + i) % MOD;
		power[2][i] = (power[2][i-1] + (i * i)) % MOD;
		power[3][i] = (power[3][i-1] + (i * i * i)) % MOD;
	}
	cin >> N >> M;
}

void ProSolve() {
	while (M--) {
		i64 cmd, x, y; cin >> cmd >> x >> y;
		if (cmd == 0) cout << get(1, 1, N, x, y) << endl;
		else if (cmd == 1) update(1, 1, N, x, y, true);
		else update(1, 1, N, x, y, false);
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}