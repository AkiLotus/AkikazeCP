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
i64 N, q;
vector<vector<i64>> val, white, black, psw, psb;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> N;
	val.resize(N, vector<i64>(N, 0LL));
	white.resize(N, vector<i64>(N, 0LL));
	black.resize(N, vector<i64>(N, 0LL));
	psw.resize(N, vector<i64>(N, 0LL));
	psb.resize(N, vector<i64>(N, 0LL));
	for (i64 i=0; i<N; i++) {
		for (i64 j=0; j<N; j++) {
			cin >> val[i][j];
			if ((i + j) % 2 == 0) white[i][j] = val[i][j];
			else black[i][j] = val[i][j];
			if (j == 0) {
				psw[i][j] = white[i][j];
				psb[i][j] = black[i][j];
			}
			else {
				psw[i][j] = psw[i][j-1] + white[i][j];
				psb[i][j] = psb[i][j-1] + black[i][j];
			}
		}
	}
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	cin >> q;
	while (q--) {
		i64 i1, j1, i2, j2; cin >> i1 >> j1 >> i2 >> j2;
		i64 wh = 0, bl = 0;
		for (i64 i=i1-1; i<i2; i++) {
			i64 twh = psw[i][j2-1], tbl = psb[i][j2-1];
			if (j1-1 != 0) {
				twh -= psw[i][j1-2]; tbl -= psb[i][j2-2];
			}
			wh += twh; bl += tbl;
		}
		cout << wh << " " << bl << endl;
		cout << abs(wh-bl) << endl;
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
