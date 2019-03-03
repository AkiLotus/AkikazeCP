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
i64 n, m, s; vector<vector<vector<pii>>> adj;
bool isDAG = true; vector<vi> vis; vector<vector<pii>> Previous;
i64 deadEnd = -1; stack<i64> pathways;

/** -----EXTENSIVE FUNCTIONS----- **/
void DFStopo(i64 z, i64 parity) {
	if (!isDAG) return;
	vis[z][parity] = 2;
	for (i64 i=0; i<adj[z][parity].size(); i++) {
		if (vis[adj[z][parity][i].fi][adj[z][parity][i].se] == 2) {
			isDAG = false; return;
		}
		else if (vis[adj[z][parity][i].fi][adj[z][parity][i].se] == 0) DFStopo(adj[z][parity][i].fi, adj[z][parity][i].se);
	}
	if (!isDAG) return;
	vis[z][parity] = 1;
}

void DFS(i64 z, i64 parity) {
	//tracker2(z, parity);
	vis[z][parity] = 1;
	if (parity == 0 && adj[z][parity].empty()) {
		deadEnd = z; i64 tmp = deadEnd, par = parity;
		pathways.push(tmp);
		while (Previous[tmp][par] != mp(-1LL, 0LL)) {
			pathways.push(Previous[tmp][par].fi);
			pii zazz = Previous[tmp][par];
			tmp = zazz.fi; par = zazz.se;
		}
		return;
	}
	if (deadEnd != -1) return;
	for (i64 i=0; i<adj[z][parity].size(); i++) {
		if (vis[adj[z][parity][i].fi][adj[z][parity][i].se] == 0) {
			Previous[adj[z][parity][i].fi][adj[z][parity][i].se] = mp(z, parity);
			DFS(adj[z][parity][i].fi, adj[z][parity][i].se);
		}
		if (deadEnd != -1) return;
	}
	if (deadEnd != -1) return;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m; adj.resize(n+1, vector<vector<pii>>(2, vector<pii>(0)));
	for (i64 i=1; i<=n; i++) {
		i64 z; cin >> z;
		for (i64 j=0; j<z; j++) {
			i64 x; cin >> x;
			adj[i][0].pub(mp(x, 1LL));
			adj[i][1].pub(mp(x, 0LL));
		}
	}
	cin >> s;
}

void ProSolve() {
	vis.resize(n+1, vi(2, 0LL));
	DFStopo(s, 1); Previous.resize(n+1, vector<pii>(2, mp(-1LL, 0LL)));
	for (i64 i=0; i<=n; i++) {
		vis[i][0] = 0; vis[i][1] = 0;
	}
	DFS(s, 1);
	if (deadEnd == -1 && !isDAG) cout << "Draw";
	else if (deadEnd == -1 && isDAG) cout << "Lose";
	else {
		cout << "Win\n";
		while (!pathways.empty()) {
			cout << pathways.top() << " ";
			pathways.pop();
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