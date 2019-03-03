#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

struct SegTree_Sum {
	int n; vector<long long> Tree, Lazy;
	SegTree_Sum() {}
	SegTree_Sum(int _n) {
		n = _n;
		Tree.resize(n*4);
		Lazy.resize(n*4);
	}
	
	void Propagate(int node, int st, int en) {
		if (Lazy[node] == 0) return;
		Tree[node] += Lazy[node] * (en - st + 1);
		if (st != en) {
			Lazy[node*2+1] += Lazy[node];
			Lazy[node*2+2] += Lazy[node];
		}
		Lazy[node] = 0;
	}
	
	void Update(int node, int st, int en, int L, int R, long long val) {
		Propagate(node, st, en);
		if (en < st || R < st || en < L) return;
		if (L <= st && en <= R) {
			Lazy[node] += val;
			Propagate(node, st, en); return;
		}
		Update(node*2+1, st, (st+en)/2+0, L, R, val);
		Update(node*2+2, (st+en)/2+1, en, L, R, val);
		Tree[node] = Tree[node*2+1] + Tree[node*2+2];
	}
	
	long long Sum(int node, int st, int en, int L, int R) {
		Propagate(node, st, en);
		if (en < st || R < st || en < L) return 0LL;
		if (L <= st && en <= R) return Tree[node];
		long long p1 = Sum(node*2+1, st, (st+en)/2+0, L, R);
		long long p2 = Sum(node*2+2, (st+en)/2+1, en, L, R);
		return (p1 + p2);
	}
	
	void RangeUpdate(int L, int R, long long val) {
		Update(0, 0, n-1, L, R, val);
	}
	
	long long RangeSum(int L, int R) {
		return Sum(0, 0, n-1, L, R);
	}
};

int n, m, w;
int t, x1, y1, x2, y2, v;
SegTree_Sum TreeRow, TreeCol;

long long Total = 0;

void Input() {
	cin >> n >> m >> w;
	TreeRow = SegTree_Sum(n);
	TreeCol = SegTree_Sum(m);
}

void Solve() {
	while (w--) {
		cin >> t >> x1 >> y1 >> x2 >> y2;
		x1--; x2--; y1--; y2--;
		if (t == 0) {
			cin >> v;
			Total += 1LL * (x2 - x1 + 1) * (y2 - y1 + 1) * v;
			TreeRow.RangeUpdate(x1, x2, 1LL * v * (y2 - y1 + 1));
			TreeCol.RangeUpdate(y1, y2, 1LL * v * (x2 - x1 + 1));
		}
		else if (t == 1) {
			long long res = 0;
			res += TreeRow.RangeSum(x1, x2);
			res += TreeCol.RangeSum(y1, y2);
			res -= Total;
			cout << res << endl;
		}
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
*  Thuy-Trang Tran, #Team4T's Leader     *
*  #Team4T Primary Flagship - Salvation  *
\******************************************/
