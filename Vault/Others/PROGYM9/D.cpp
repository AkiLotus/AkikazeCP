// Template by proptit_4t41
// Applied for C++11/C++14
// Add -std=c++14 to your IDE.

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
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

// custom typedef here


// global variables here


// functions here
i64 ftrl(i64 z) {
	//tracker1(z); REcheck;
	if (z == 0) return 1;
	return (z * ftrl(z-1)) % MOD;
}

i64 modPow(i64 a, i64 b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	i64 tmp = modPow(a, b/2);
	if (b % 2 == 0) return (tmp * tmp) % MOD;
	return (((tmp * tmp) % MOD) * a) % MOD;
}

i64 nCr (i64 a, i64 b) {
	if (a < b) return 0;
	//tracker2(a,b); REcheck;
	i64 res = 1;
	for (i64 i=b+1; i<=a; i++) res = (res * i) % MOD;
	res = (res * modPow(ftrl(a-b), MOD-2)) % MOD;
	return res;
}

int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	int T; cin >> T;
	while (T--) {
		i64 N, M, K, D; cin >> N >> M >> K >> D;
		vector<i64> gift(N);
		for (i64 i=0; i<N; i++) cin >> gift[i];
		sort(gift.begin(), gift.end());
		if (N == 0) {
			cout << "1\n"; continue;
		}
		if (K == 0) {
			cout << nCr(N, M) << endl; continue;
		}
		i64 higher = N - (lower_bound(gift.begin(), gift.end(), D) - gift.begin());
		i64 res = 0;
		for (i64 i=N-higher; i<N; i++) {
			//REcheck;
			if (N - i < K) break;// REcheck;
			res = (res + (nCr(N-i-1, K-1) * nCr(i, M-K)) % MOD) % MOD;
		}
		cout << res << endl;
	}
	return 0;
}
