#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

struct Tree {
	int n, k; vector<vector<int>> TreeMax;
	
	Tree() {}
	
	Tree(int __n, int __k) {
		n = __n; k = __k;
		TreeMax.resize(1 << k, vector<int>(n*4, 0));
	}
	
	void Update(int mask, int node, int st, int en, int id, int val) {
		if (st > en || en < id || id < st) return;
		if (st == id && id == en) {TreeMax[mask][node] = val; return;}
		Update(mask, node*2, st, (st+en)/2, id, val);
		Update(mask, node*2+1, (st+en)/2+1, en, id, val);
		TreeMax[mask][node] = max(TreeMax[mask][node*2+0], TreeMax[mask][node*2+1]);
	}
	
	int GetMax(int mask, int node, int st, int en, int L, int R) {
		if (st > en || en < L || R < st) return -1000000000;
		if (L <= st && en <= R) return TreeMax[mask][node];
		int p1 = GetMax(mask, node*2, st, (st+en)/2, L, R);
		int p2 = GetMax(mask, node*2+1, (st+en)/2+1, en, L, R);
		return max(p1, p2);
	}
};

int n, k, q, t; Tree ST; vector<int> Point;

int value(vector<int> &vec, int mask) {
	int res = 0;
	for (int i=0; i<vec.size(); i++) {
		if ((mask & (1 << i)) == 0) res += vec[i];
		else res -= vec[i];
	}
	return res;
}

void Input() {
	cin >> n >> k; ST = Tree(n, k); Point.resize(k);
	for (int i=0; i<n; i++) {
		for (int j=0; j<k; j++) cin >> Point[j];
		for (int x=0; x<(1<<k); x++) ST.Update(x, 1, 0, n-1, i, value(Point, x));
	}
}

void Solve() {
	cin >> q;
	while (q--) {
		cin >> t;
		if (t == 1) {
			int id; cin >> id; id--;
			for (int x=0; x<k; x++) cin >> Point[x];
			for (int x=0; x<(1<<k); x++) ST.Update(x, 1, 0, n-1, id, value(Point, x));
		}
		else if (t == 2) {
			int l, r; cin >> l >> r; l--; r--;
			int answer = 0;
			for (int x=0; x<(1<<(k-1)); x++) {
				int p1 = ST.GetMax((1LL<<k)-1-x, 1, 0, n-1, l, r);
				int p2 = ST.GetMax(x, 1, 0, n-1, l, r);
				answer = max(answer, (int)abs(p1 + p2));
			}
			cout << answer << endl;
		}
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
