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
		double DP?
		first DP: len[i][j] = MAXIMUM length of increasing subarray start from i and end at j (must contain j) {initialize: len[i][j] = 1}
			looping formula: len[i][j] = max(len[i][j], len[i][u] + 1) (only if a[u] < a[j], u runs from i to less than j)
			(Complexity: O(N^2) or O(NlogN), preferably O(N^2) in this case)
		second DP: f[k][r] = count of sub-arrays with length not less than k in array A's first r elements
			looping: i: from 1 to n
				in i-loop: looping r: from i to n
					initialize: f[k][r] = max(f[k][r], f[k][r-1])
					if (len[i][r] >= k) f[k][r] = max(f[k][r], f[k][i-1]+len[i][r]);
		result: f[k][n], k runs from 1 to n
    -------------------------- **/

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
//int T, cas = 0; // for multi-testcase problems
int N;
vector<int> a;
vector<vector<int>> len, f;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> N; a.resize(N+1, 0);
	len.resize(N+1, vector<int>(N+1, 1));
	f.resize(N+1, vector<int>(N+1, 0));
	for (int i=1; i<=N; i++) cin >> a[i];
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	for (int i=1; i<=N; i++) {
		for (int j=0; j<i; j++) len[i][j] = 0;
		for (int j=i; j<=N; j++) {
			for (int u=i; u<j; u++) {
				if (a[u] < a[j]) len[i][j] = max(len[i][j], len[i][u] + 1);
			}
		}
	}
	for (int k=1; k<=N; k++) {
		for (int i=1; i<=N; i++) {
			for (int r=i; r<=N; r++) {
				f[k][r] = max(f[k][r], f[k][r-1]);
				if (len[i][r] >= k) f[k][r] = max(f[k][r], f[k][i-1]+len[i][r]);
			}
		}
		cout << f[k][N] << " ";
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	freopen("SUBSEQ.INP", "r", stdin);
	freopen("SUBSEQ.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
