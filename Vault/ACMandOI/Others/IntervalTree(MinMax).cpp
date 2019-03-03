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
int N, Q;
vector<i64> A(66666, 0);
vector<i64> MaxTree(666666, 0);
vector<i64> MinTree(666666, 0);

// custom typedef here


// functions here
i64 left(i64 z) {
    return (z << 1);
}

i64 right(i64 z) {
    return (z << 1) + 1;
}

void MaxITBuild(i64 n, i64 s, i64 e) {
    if (s > e) return;
    if (s == e) {
        MaxTree[n] = A[s]; return;
    }
    MaxITBuild(left(n), s, (s+e)/2);
    MaxITBuild(right(n), (s+e)/2+1, e);
    MaxTree[n] = max(MaxTree[left(n)], MaxTree[right(n)]);
}

i64 MaxITLookup(i64 n, i64 L, i64 R, i64 s, i64 e) {
    if (L > R || L > e || R < s) return -1;
    if (L >= s && R <= e) {
        return MaxTree[n];
    }
    i64 p1 = MaxITLookup(left(n), L, (L+R)/2, s, e);
    //cout << "p1 = " << p1 << " (L = " << L << " | R = " << R << ")\n";
    i64 p2 = MaxITLookup(right(n), (L+R)/2+1, R, s, e);
    //cout << "p2 = " << p2 << " (L = " << L << " | R = " << R << ")\n";
    return max(p1, p2);
}

void MinITBuild(i64 n, i64 s, i64 e) {
    if (s > e) return;
    if (s == e) {
        MinTree[n] = A[s]; return;
    }
    MinITBuild(left(n), s, (s+e)/2);
    MinITBuild(right(n), (s+e)/2+1, e);
    MinTree[n] = min(MinTree[left(n)], MinTree[right(n)]);
}

i64 MinITLookup(i64 n, i64 L, i64 R, i64 s, i64 e) {
    if (L > R || L > e || R < s) return LINF;
    if (L >= s && R <= e) {
        return MinTree[n];
    }
    i64 p1 = MinITLookup(left(n), L, (L+R)/2, s, e);
    //cout << "p1 = " << p1 << " (L = " << L << " | R = " << R << ")\n";
    i64 p2 = MinITLookup(right(n), (L+R)/2+1, R, s, e);
    //cout << "p2 = " << p2 << " (L = " << L << " | R = " << R << ")\n";
    return min(p1, p2);
}

int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
    cin >> N >> Q;
    for (i64 i=1; i<=N; i++) cin >> A[i];
    MaxITBuild(1, 1, N);
    MinITBuild(1, 1, N);
    while (Q--) {
        i64 u, v; cin >> u >> v;
        i64 minimum = MinITLookup(1,1,N,u,v);
        i64 maximum = MaxITLookup(1,1,N,u,v);
        cout << maximum - minimum << endl;
    }
	return 0;
}
