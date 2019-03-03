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
vector<i64> A(131072, 0);
vector<i64> tree(1000007, 0);
vector<i64> lazy(1000007, 0);

// custom typedef here


// functions here
i64 left(i64 z) {
	return (z << 1);
}

i64 right(i64 z) {
	return (z << 1) + 1;
}

void ST_Build(i64 n, i64 s, i64 e) {
	if (s > e) return;
	if (s == e) {
		tree[n] = A[s];
		return;
	}
	ST_Build(left(n), s, (s+e)/2);
	ST_Build(right(n), (s+e)/2+1, e);
	tree[n] = tree[left(n)] + tree[right(n)];
}

i64 FindSum(i64 n, i64 L, i64 R, i64 s, i64 e) {
	if (lazy[n] != 0) {
		tree[n] += lazy[n]*(R-L+1);
		if (L != R) {
			lazy[left(n)] += lazy[n];
			lazy[right(n)] += lazy[n];
		}
		lazy[n] = 0;
	}
	if (L > R || L > e || R < s) return 0;
	if (L >= s && R <= e) return tree[n];
	i64 p1 = FindSum(left(n), L, (L+R)/2, s, e);
	i64 p2 = FindSum(right(n), (L+R)/2+1, R, s, e);
	return (p1 + p2);
}

void IncUpdate(i64 n, i64 L, i64 R, i64 s, i64 e, i64 x) {
	if (lazy[n] != 0) {
		tree[n] += lazy[n]*(R-L+1);
		if (L != R) {
			lazy[left(n)] += lazy[n];
			lazy[right(n)] += lazy[n];
		}
		lazy[n] = 0;
	}
	if (L > R || L > e || R < s) return;
	if (L >= s && R <= e) {
		tree[n] += x*(R-L+1);
		if (L != R) {
			lazy[left(n)] += x;
			lazy[right(n)] += x;
		}
		return;
	}
	IncUpdate(left(n), L, (L+R)/2, s, e, x);
	IncUpdate(right(n), (L+R)/2+1, R, s, e, x);
	tree[n] = tree[left(n)] + tree[right(n)];
}

int main() {
	ios_base::sync_with_stdio(0); //cin.tie(NULL);
	// code here
	cin >> N >> M;
	for (i64 i=0; i<N; i++) cin >> A[i];
	ST_Build(1, 0, N-1);
	while (M--) {
		i64 cmd, u, v; cin >> cmd >> u >> v;
		if (cmd == 1) {
			cout << FindSum(1, 0, N-1, u-1, v-1) << endl;
		}
		else {
			i64 x; cin >> x;
			IncUpdate(1, 0, N-1, u-1, v-1, x);
		}
	}
	return 0;
}
