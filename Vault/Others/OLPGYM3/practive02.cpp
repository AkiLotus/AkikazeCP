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
i64 N; vector<vector<i64>> dist;
i64 ans = LINF;
vector<ppi> coor;
vector<bool> visited;
vector<i64> mindist, mini, maxi;

/** -----EXTENSIVE FUNCTIONS----- **/
bool custom(ppi a, ppi b) {
	return (maxi[a.se] > maxi[b.se]);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> N; dist.resize(N, vector<i64>(N, LINF));
	coor.resize(N, mp(mp(0LL, 0LL), 0LL)); visited.resize(N, false);
	mindist.resize(N, LINF); mini.resize(N, LINF); maxi.resize(N, -LINF);
	for (i64 i=0; i<N; i++) {
		cin >> coor[i].fi.fi >> coor[i].fi.se;
		coor[i].se = i;
	}
	for (i64 i=0; i<N; i++) {
		for (i64 j=0; j<N; j++) {
			if (i == j) continue;
			dist[i][j] = (coor[i].fi.fi-coor[j].fi.fi)*(coor[i].fi.fi-coor[j].fi.fi) + (coor[i].fi.se-coor[j].fi.se)*(coor[i].fi.se-coor[j].fi.se);
			mini[i] = min(mini[i], dist[i][j]); maxi[i] = max(maxi[i], dist[i][j]);
		}
	}
	sort(coor.begin(), coor.end(), custom);
	for (i64 i=0; i<N; i++) {
		for (i64 j=0; j<N; j++) {
			if (i == j) continue;
			dist[i][j] = (coor[i].fi.fi-coor[j].fi.fi)*(coor[i].fi.fi-coor[j].fi.fi) + (coor[i].fi.se-coor[j].fi.se)*(coor[i].fi.se-coor[j].fi.se);
		}
	}
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	if (N == 1) {
		cout << 0; return;
	}
	queue<i64> Q; Q.push(0);
	visited[0] = true;
	while (!Q.empty()) {
		i64 z = Q.front(); Q.pop();
		for (i64 i=0; i<N; i++) {
			if (dist[z][i] < mindist[i]) mindist[i] = dist[z][i];
		}
		vector<pii> tmp(N);
		for (i64 i=0; i<N; i++) tmp[i] = mp(mindist[i], i);
		sort(tmp.begin(), tmp.end());
		i64 next = 0; while (next < N && visited[next]) next++;
		if (next != N) {
			visited[next] = true; Q.push(next);
		}
	}
	for (i64 i=0; i<N; i++) {
		if (mindist[i] == LINF) mindist[i] = -LINF;
	}
	cout << *max_element(mindist.begin(), mindist.end());
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
