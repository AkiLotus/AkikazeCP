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
#define MOD 1000000009LL
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
i64 N, M, K, ans = 0;
vector<i64> a, b;
vector<vector<i64>> cc, sum, prefixSum;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> N >> M >> K;
	a.resize(N); b.resize(M);
	cc.resize(K, vector<i64>(N, 0));
	sum.resize(K, vector<i64>(N, 0));
	prefixSum.resize(K, vector<i64>(N, 0));
	for (i64 i=0; i<N; i++) cin >> a[i];
	for (i64 i=0; i<M; i++) cin >> b[i];
	sort(a.begin(), a.end()); sort(b.begin(), b.end());
	for (i64 i=0; i<=N-K; i++) {
		cc[0][i] = max((i64)(lower_bound(b.begin(), b.end(), a[i]) - b.begin()), 0LL);
		sum[0][i] = cc[0][i];
		if (i == 0) prefixSum[0][i] = sum[0][i];
		else prefixSum[0][i] = (prefixSum[0][i-1] + sum[0][i]) % MOD;
	}
	for (i64 i=N-K+1; i<N; i++) prefixSum[0][i] = prefixSum[0][i-1];
	for (i64 i=0; i<N; i++) cout << sum[0][i] << " "; cout << endl;
	for (i64 i=0; i<N; i++) cout << cc[0][i] << " "; cout << endl;
	for (i64 i=0; i<N; i++) cout << prefixSum[0][i] << " "; cout << endl;
	for (i64 k=1; k<K; k++) {
		for (i64 i=0; i<=N-K+k; i++) {
			if (i == N-K+k) cc[k][i] = max(lower_bound(b.begin(), b.end(), a[i]) - b.begin() - k, 0LL);
			else cc[k][i] = max(cc[k-1][i]-1, 0LL);
			sum[k][i] = (prefixSum[k-1][i-1] * cc[k][i]) % MOD;
			if (i == 0) prefixSum[k][i] = sum[k][i];
			else prefixSum[k][i] = (prefixSum[k][i-1] + sum[k][i]) % MOD;
		}
		for (i64 i=N-K+k+1; i<N; i++) prefixSum[k][i] = prefixSum[k][i-1];
		for (i64 i=0; i<N; i++) cout << sum[k][i] << " "; cout << endl;
		for (i64 i=0; i<N; i++) cout << cc[k][i] << " "; cout << endl;
		for (i64 i=0; i<N; i++) cout << prefixSum[k][i] << " "; cout << endl;
	}
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	for (i64 i=0; i<N; i++) ans = (ans + sum[K-1][i]) % MOD;
	cout << ans;
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
