/**
	Template by proptit_4t41
	Applied for C++11/C++14
	Add -std=c++14 to your IDE.
**/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define i64 long long
#define u64 unsigned long long
#define ld long double
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define MOD 1000000007LL
#define INF 1e9
#define LINF 1e18
#define EPS 1e-9
#define GOLD ((1+sqrt(5))/2)
#define REcheck cout << "RE here?\n"
#define tracker1(i) cout << "working at " << i << endl;
#define tracker2(i,j) cout << "working at " << i << "-" << j << endl;
#define tracker3(i,j,k) cout << "working at " << i << "-" << j << "-" << k << endl;
const long double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
//int T, cas = 0; // for multi-testcase problems
i64 N, M, K, A, B;
vector<vector<pii>> adjRoute;
vector<pii> prev;
deque<i64> path;
bool valid = false;

/** -----EXTENSIVE FUNCTIONS----- **/
void DFS(i64 node, i64 dist) {
	if (valid) return;
	//tracker2(node, dist);
	if (dist > K) return;
	path.pub(node);
	if (node == B-1 && dist == K) {
		while (!path.empty()) {
			i64 tmp = path.front(); path.pof();
			cout << tmp+1 << " ";
		}
		valid = true; return;
	}
	for (i64 i=0; i<adjRoute[node].size(); i++) {
		pii index = adjRoute[node][i];
		if (dist + index.se <= K) DFS(index.fi, dist+index.se);
		if (valid) return;
	}
	if (valid) return;
	path.pob();
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> N >> M >> K >> A >> B;
	adjRoute.resize(N, vector<pii>(0));
	for (i64 i=0; i<M; i++) {
		i64 X, Y, L; cin >> X >> Y >> L;
		adjRoute[X-1].pub(mp(Y-1, L));
		adjRoute[Y-1].pub(mp(X-1, L));
	}
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	DFS(A-1, 0LL);
	if (!valid) cout << "Impossible";
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
