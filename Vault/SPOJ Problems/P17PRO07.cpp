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
struct Node {
    i64 it[3], lazy;
    Node() {}
    Node(i64 _a, i64 _b, i64 _c, i64 _d) {
        it[0] = _a; it[1] = _b; it[2] = _c; lazy = _d;
    }
};

Node operator + (Node A, Node B) {
    Node Res = {0, 0, 0, 0};
    for (i64 i=0; i<3; i++) Res.it[i] = (A.it[i] + B.it[i]) % 3;
    return Res;
}

// global variables here
i64 N, M; string S;
i64 presum[1111111];
Node tree[1111111];

// functions here
void ITbuild(i64 n, i64 l, i64 r) {
    if (l == r) {
        tree[n] = Node(presum[l] == 0, presum[l] == 1, presum[l] == 2, 0);
        return;
    }
    ITbuild(2*n, l, (l+r)/2);
    ITbuild(2*n+1, (l+r)/2+1, r);
    tree[n] = tree[2*n] + tree[2*n+1];
}

void treeRotate(i64 n, i64 cnt) {
	for (i64 i=0; i<cnt; i++) {
		swap(tree[i].it[2], tree[i].it[1]);
		swap(tree[i].it[1], tree[i].it[0]);
	}
}

void fallout(i64 n) {
	treeRotate(2*n, tree[2*n].lazy);
	treeRotate(2*n+1, tree[2*n+1].lazy);
	tree[n*4].lazy = (tree[n*4].lazy + tree[n*2].lazy) % 3;
    tree[n*4+1].lazy = (tree[n*4+1].lazy + tree[n*2].lazy) % 3;
    tree[n*4+2].lazy = (tree[n*4+2].lazy + tree[n*2+1].lazy) % 3;
    tree[n*4+3].lazy = (tree[n*4+3].lazy + tree[n*2+1].lazy) % 3;
    tree[n*2].lazy = tree[n*2+1].lazy = 0;
}

void ITupdate(i64 n, i64 l, i64 r, i64 s, i64 e, i64 x) {
	if (x == 0) return;
	if (l > e || r < s) return;
	if (l >= s && r <= e) {
		tree[n].lazy = (tree[n].lazy + x) % 3;
        treeRotate(n, tree[n].lazy);
        tree[n*2].lazy = (tree[n*2].lazy + tree[n].lazy) % 3;
        tree[n*2+1].lazy = (tree[n*2+1].lazy + tree[n].lazy) % 3;
        tree[n].lazy = 0;
        return;
	}
	fallout(n);
	ITupdate(2*n, l, (l+r)/2, s, e, x);
	ITupdate(2*n+1, (l+r)/2+1, r, s, e, x);
	tree[n] = tree[2*n] + tree[2*n+1];
}

Node getNode(i64 n, i64 l, i64 r, i64 s, i64 e) {
	if (l > e || r < s) {
		return Node(0,0,0,0);
	}
	if (l >= s && r <= e) return tree[n];
	fallout(n);
	Node n1 = getNode(2*n, l, (l+r)/2, s, e);
	Node n2 = getNode(2*n+1, (l+r)/2+1, r, s, e);
	return (n1 + n2);
}

int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
    cin >> N >> M >> S;
    for (i64 i=0; i<N; i++) {
        if (i == 0) presum[i] = (S[i] - '0') % 3;
        else presum[i] = (presum[i-1] + (S[i] - '0')) % 3;
    }
    ITbuild(1, 0, N-1);
    for (i64 i=1; i<9; i++) cout << tree[i].it[0] << "-" << tree[i].it[1] << "-" << tree[i].it[2] << " "; cout << endl;
    while (M--) {
		i64 cmd, u, z; cin >> cmd >> u >> z;
		if (cmd == 1) {
			z %= 3; i64 diff = (z - (S[u] - '0') + 12) % 3;
			ITupdate(1,0,N-1,u,N-1,diff);
			S[u] = ('0' + z);
			for (i64 i=1; i<9; i++) cout << tree[i].it[0] << "-" << tree[i].it[1] << "-" << tree[i].it[2] << " "; cout << endl;
		}
		else if (cmd == 2) {
			i64 ans = 0;
			Node tmp = getNode(1,0,N-1,u,z+1);
			cout << tmp.it[0] << " " << tmp.it[1] << " " << tmp.it[2] << endl;
			for (i64 i=0; i<3; i++) ans += tmp.it[i] * (tmp.it[i] - 1) / 2;
			cout << ans << endl;
		}
    }
	return 0;
}
