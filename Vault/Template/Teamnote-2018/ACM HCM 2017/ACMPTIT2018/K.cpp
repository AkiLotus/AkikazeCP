#include <bits/stdc++.h>
using namespace std;
const int nn = 1008;
vector<int> pos[nn];
int q[nn];
int d[nn];

int n, a, b;
int p[nn];

int bfs() {
	memset(d, 0, sizeof d);
	int l, r;
	l = r = 0;
	q[0] = a;
	d[a] = 1;
	while (l <= r) {
		int u = q[l++];
		if (u == b) return d[u] - 1;
		if (u + 1 <= n && d[u + 1] == 0)  {
			q[++r] = u + 1;
			d[u + 1] = d[u] + 1;
		}
		if (u - 1 > 0 && d[u - 1] == 0)  {
			q[++r] = u - 1;
			d[u - 1] = d[u] + 1;
		}
		for (int i = 0; i < pos[p[u]].size(); i++) {
			int v = pos[p[u]][i];
			if (d[v] == 0) {
				d[v] = d[u] + 1;
				q[++r] = v;
			}
		}
	}
}

int main() {
	int test;
	cin >> test;
	while (test--) {
		cin >> n >> a >> b;
		for (int i = 0; i < nn; i++) {
			pos[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
			pos[p[i]].push_back(i);
		}
		cout << bfs() << endl;
	}
}