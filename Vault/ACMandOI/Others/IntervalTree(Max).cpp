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
int N, M, P;
vector<i64> A(66666, 0);
vector<i64> add(66666, 0);
vector<i64> sub(66666, 0);
vector<i64> tree(666666, 0);
vector<i64> lazy(666666, 0);

// custom typedef here


// functions here
i64 left(i64 z) {
    return (z << 1);
}

i64 right(i64 z) {
    return (z << 1) + 1;
}

void ITBuild(i64 n, i64 s, i64 e) {
    if (s > e) return;
    if (s == e) {
        tree[n] = A[s]; return;
    }
    ITBuild(left(n), s, (s+e)/2);
    ITBuild(right(n), (s+e)/2+1, e);
    tree[n] = max(tree[left(n)], tree[right(n)]);
}

i64 ITLookup(i64 n, i64 L, i64 R, i64 s, i64 e) {
    if (L > R || L > e || R < s) return -1;
    if (L >= s && R <= e) {
        return tree[n];
    }
    i64 p1 = ITLookup(left(n), L, (L+R)/2, s, e);
    //cout << "p1 = " << p1 << " (L = " << L << " | R = " << R << ")\n";
    i64 p2 = ITLookup(right(n), (L+R)/2+1, R, s, e);
    //cout << "p2 = " << p2 << " (L = " << L << " | R = " << R << ")\n";
    return max(p1, p2);
}

int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
    cin >> N >> M;
    while (M--) {
        i64 u,v,k; cin >> u >> v >> k;
        add[u] += k; sub[v+1] += k;
    }
    for (i64 i=2; i<66666; i++) {
        add[i] += add[i-1]; sub[i] += sub[i-1];
    }
    for (i64 i=1; i<66666; i++) A[i] = add[i] - sub[i];
    ITBuild(1, 1, N);
    //for (i64 i=1; i<7; i++) cout << A[i] << " "; cout << endl;
    //for (i64 i=1; i<14; i++) cout << tree[i] << " "; cout << endl;
    cin >> P;
    while (P--) {
        i64 u, v; cin >> u >> v;
        cout << ITLookup(1, 1, N, u, v) << endl;
    }
	return 0;
}
