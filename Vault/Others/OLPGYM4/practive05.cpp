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
i64 N; vector<pii> mirror;
i64 xA, yA, xB, yB;
vector<vector<i64>> dp;
queue<pii> light;
map<pii, stack<i64>> M;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> N; mirror.resize(N+1, mp(0LL, 0LL));
	dp.resize(N+1, vector<i64>(2, 0));
	cin >> xA >> yA >> xB >> yB;
	M[mp(xB, 0LL)].push(-1); M[mp(yB, 1LL)].push(-1);
	for (i64 i=0; i<N; i++) {
		cin >> mirror[i].fi >> mirror[i].se;
		M[mp(mirror[i].fi, 0LL)].push(i);
		M[mp(mirror[i].se, 1LL)].push(i);
	}
	mirror[N] = mp(xA, yA);
	light.push(mp(N, 0LL)); light.push(mp(N, 1LL));
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	while (!light.empty()) {
		pii current = light.front(); light.pop();
		pii coor = mirror[current.fi]; i64 dim = current.se;
		i64 pos = coor.fi; if (dim) pos = coor.se;
		while (!M[mp(pos, dim)].empty()) {
			i64 ite = M[mp(pos, dim)].top(); M[mp(pos, dim)].pop();
			if (ite == -1) {
				cout << dp[current.fi][dim]; return;
			}
			dp[ite][1-dim] = dp[current.fi][dim] + 1;
			light.push(mp(ite, 1-dim));
		}
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
