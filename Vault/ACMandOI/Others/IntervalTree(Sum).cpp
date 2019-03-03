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

// global variables here
i64 N, M;
i64 A[131072];
i64 tree[1000007];
i64 MaxSum[1000007];

// custom typedef here


// functions here
i64 left(i64 z) {
	return (z << 1);
}

i64 right(i64 z) {
	return (z << 1) + 1;
}

i64 ReturnMaxSum(i64 n, i64 L, i64 R, i64 s, i64 e) {
	if (s > R || e < L || L > R) return -LINF;
	if (L >= s && R <= e) return MaxSum[n];
	i64 p1 = ReturnMaxSum(left(n), L, (L+R)/2, s, e);
	//cout << "p1 = " << p1 << " | working at L = " << L << ", R = " << R << endl;
	i64 p2 = ReturnMaxSum(right(n), (L+R)/2+1, R, s, e);
	//cout << "p2 = " << p2 << " | working at L = " << L << ", R = " << R << endl;
	return max(p1, p2);
}

void ITbuild(i64 n, i64 s, i64 e) {
	if (s > e) return;
	if (s == e) tree[n] = A[s];
	else {
		ITbuild(left(n), s, (s+e)/2);
		ITbuild(right(n), (s+e)/2+1, e);
		tree[n] = tree[left(n)] + tree[right(n)];
	}
}

void MSbuild(i64 n, i64 s, i64 e) {
    if (s > e) return;
	if (s == e) MaxSum[n] = tree[n];
	else {
		MSbuild(left(n), s, (s+e)/2);
		MSbuild(right(n), (s+e)/2+1, e);
		MaxSum[n] = max(tree[n], max(MaxSum[left(n)], MaxSum[right(n)]));
	}
}

int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); //cin.tie(NULL);
	// code here
	cin >> N;
	for (i64 i=0; i<N; i++) cin >> A[i];
	ITbuild(1,0,N-1); MSbuild(1,0,N-1);
	//for (i64 i=0; i<8; i++) cout << A[i] << " "; cout << endl;
	//for (i64 i=1; i<16; i++) cout << tree[i] << " "; cout << endl;
	//for (i64 i=1; i<16; i++) cout << MaxSum[i] << " "; cout << endl;
	cin >> M;
	while (M--) {
		i64 u, v; cin >> u >> v;
		cout << ReturnMaxSum(1, 0, N-1, u-1, v-1) << endl;
	}
	return 0;
}
