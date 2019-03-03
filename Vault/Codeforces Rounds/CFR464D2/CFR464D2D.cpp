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
i64 n; string s1, s2;
vector<i64> parent(26, -1);
vector<vi> children(26, vi(0));
vector<i64> DSUsize(26, 1);
vb visited(26, false);
vector<vi> DSU(26, vi(0));
vector<pii> ans; vi tmp;

/** -----EXTENSIVE FUNCTIONS----- **/
i64 DSUfind(i64 x) {
	while (parent[x] != -1) x = parent[x];
	return x;
}

void DSUmerge(i64 x, i64 y) {
	i64 a = DSUfind(x), b = DSUfind(y);
	if (a == b) return;
	if (DSUsize[a] < DSUsize[b]) {
		i64 tmp = a; a = b; b = tmp;
	}
	DSUsize[a] += DSUsize[b];
	parent[b] = a;
}

void DFS(i64 z) {
	tmp.pub(z); visited[z] = true;
	for (i64 i=0; i<children[z].size(); i++) {
		if (!visited[children[z][i]]) DFS(children[z][i]);
	}
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n >> s1 >> s2;
}

void ProSolve() {
	for (i64 i=0; i<n; i++) {
		i64 z1 = s1[i] - 'a';
		i64 z2 = s2[i] - 'a';
		if (z2 < z1) {
			i64 tmp = z1;
			z1 = z2; z2 = tmp;
		}
		DSUmerge(z1, z2);
	}
	for (i64 i=0; i<26; i++) {
		DSU[DSUfind(i)].pub(i);
	}
	for (i64 i=0; i<26; i++) {
		if (DSU[i].size() == 1) continue;
		for (i64 j=1; j<DSU[i].size(); j++) {
			ans.pub(mp(DSU[i][j-1], DSU[i][j]));
		}
	}
	cout << ans.size() << endl;
	for (i64 i=0; i<ans.size(); i++) {
		cout << char(97+ans[i].fi) << " " << char(97+ans[i].se) << endl;
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}