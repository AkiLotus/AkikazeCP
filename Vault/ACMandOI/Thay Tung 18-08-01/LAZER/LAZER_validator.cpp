// Template by proptit_4t41
// Applied for C++11/C++14
// Add -std=c++14 to your IDE.

#include <iostream>
#include "testlib.h"
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
struct Query {
	i64 x, y1, y2, type;
	Query() {}
	Query(i64 _x, i64 _y1, i64 _y2, i64 _type) {
		x = _x; y1 = _y1; y2 = _y2; type = _type;
	}
};

struct Node {
	i64 cc, len;
	Node() {}
	Node(i64 _cc, i64 _len) {
		cc = _cc; len = _len;
	}
};

// global variables here
i64 N, trueArea = 0, area = 0;
Query A[888888];
Node tree[888888];

// functions here
bool qSort(Query a, Query b) {
	if (a.x < b.x) return true;
	if (a.x == b.x && a.type < b.type) return true;
	return false;
}

void treeUpdate(i64 node, i64 L, i64 R, i64 s, i64 e, i64 T) {
	if (R < s || e < L) return;
	if (s <= L && R <= e) {
		tree[node].cc += T;
		if (T == 1) tree[node].len = R - L + 1;
		else if (tree[node].cc == 0) tree[node].len = tree[2*node].len + tree[2*node+1].len;
		return;
	}
	treeUpdate(node*2, L, (L+R)/2, s, e, T);
	treeUpdate(node*2+1, (L+R)/2+1, R, s, e, T);
	if (tree[node].cc == 0) tree[node].len = tree[2*node].len + tree[2*node+1].len;
}

int main(int argc, char* argv[]) {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	registerValidation(argc, argv);
	// code here
	N = inf.readLong(1LL, 100000LL, "N"); inf.readEoln();
	for (i64 i=1; i<=N; i++) {
		i64 x1, y1, x2, y2;
		x1 = inf.readLong(1LL, 99999LL, "x1"), inf.readSpace();
		y1 = inf.readLong(1LL, 99999LL, "y1"), inf.readSpace();
		x2 = inf.readLong(x1+1, 100000LL, "x2"), inf.readSpace();
		y2 = inf.readLong(y1+1, 100000LL, "y2"), inf.readEoln();
		area += (x2 - x1) * (y2 - y1);
		A[i] = Query(x1, y1, y2, 1); A[i+N] = Query(x2, y1, y2, -1);
	}
	sort(A+1, A+2*N+1, qSort);
	i64 last = 0;
	for (i64 i=1; i<=2*N; i++) {
		trueArea += (A[i].x - last) * (tree[1].len);
		last = A[i].x; treeUpdate(1, 0, 100000, A[i].y1, A[i].y2-1, A[i].type);
	}
	ensuref(trueArea == area, "No rectangle pair should have non-zero intersection area! Area = %lld | TrueArea = %lld", area, trueArea);

	i64 T = inf.readLong(1LL, 100000LL, "T"); inf.readEoln();
	for (i64 i=1; i<=T; i++) {
		i64 x = inf.readLong(-100000LL, 100000LL, "x"); inf.readSpace();
		i64 d = inf.readLong(1LL, 3LL, "d"); inf.readEoln();
	}

	inf.readEof();
	return 0;
}