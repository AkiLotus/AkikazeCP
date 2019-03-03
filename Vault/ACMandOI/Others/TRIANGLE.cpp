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
const long double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

// custom typedef here


// global variables here
i64 tree[66666666];

// functions here
void VoidUpdate(i64 node, i64 lx, i64 rx, i64 ly, i64 ry, i64 x, i64 y) {
	//cout << "Working at " << lx << " -> " << rx << " | " << ly << " -> " << ry << endl;
	if (lx > rx || lx > x || rx < x || ly > ry || ly > y || ry < y) return;
	if (lx == rx && lx == x && ly == ry && ly == y) {
		//cout << "Return your val\n";
		tree[node] = 1; return;
	}
	VoidUpdate(node*4-2, lx, (lx+rx)/2, ly, (ly+ry)/2, x, y);
	VoidUpdate(node*4+0, lx, (lx+rx)/2, (ly+ry)/2+1, ry, x, y);
	VoidUpdate(node*4-1, (lx+rx)/2+1, rx, ly, (ly+ry)/2, x, y);
	VoidUpdate(node*4+1, (lx+rx)/2+1, rx, (ly+ry)/2+1, ry, x, y);
	//cout << tree[node*4-2] << " + " << tree[node*4+0] << " + " << tree[node*4-1] << " + " << tree[node*4+1] << endl;
	tree[node] = tree[node*4-2] + tree[node*4+0] + tree[node*4-1] + tree[node*4+1];
}

i64 VoidGet(i64 node, i64 lx, i64 rx, i64 ly, i64 ry, i64 sx, i64 sy, i64 ex, i64 ey) {
	if (lx > rx || rx < sx || ex < lx || ly > ry || ry < sy || ey < ly) return 0;
	if (lx >= sx && ex >= rx && ly >= sy && ey >= ry) {
		return tree[node];
	}
	i64 p1 = VoidGet(node*4-2, lx, (lx+rx)/2, ly, (ly+ry)/2, sx, sy, ex, ey);
	i64 p2 = VoidGet(node*4+0, lx, (lx+rx)/2, (ly+ry)/2+1, ry, sx, sy, ex, ey);
	i64 p3 = VoidGet(node*4-1, (lx+rx)/2+1, rx, ly, (ly+ry)/2, sx, sy, ex, ey);
	i64 p4 = VoidGet(node*4+1, (lx+rx)/2+1, rx, (ly+ry)/2+1, ry, sx, sy, ex, ey);
	return (p1 + p2 + p3 + p4);
}

int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	i64 Q; cin >> Q;
	while (Q--) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			i64 x, y; cin >> x >> y;
			VoidUpdate(1, 1, 1000, 1, 1000, x, y);
		}
		else if (cmd == 2) {
			i64 a, b, u, v; cin >> a >> b >> u >> v;
			i64 cc = VoidGet(1, 1, 1000, 1, 1000, a, b, u, v);
			//cout << "cc = " << cc << endl;
			cout << (cc * (cc - 1) * (cc - 2)) / 6 << endl;
		}
	}
	return 0;
}
