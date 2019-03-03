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


// global variables here
vector<pii> prime[151];
i64 tree[35][555555], lazy[35][555555];
i64 snt[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149}; // 35 elements

// functions here
void PrimeInitialize() {
	for (i64 i=1; i<151; i++) {
		i64 tmp = i;
		for (i64 j=0; j<35; j++) {
			if (snt[j] > tmp) break;
			i64 cc = 0;
			while (tmp % snt[j] == 0) {
				tmp /= snt[j]; cc++;
			}
			if (cc > 0) prime[i].pub(mp(j, cc));
		}
	}
}

void MultiplyUpdate(i64 node, i64 left, i64 right, i64 st, i64 en, i64 layer, i64 val) {
	if (lazy[layer][node] != 0) {
		tree[layer][node] += lazy[layer][node] * (right - left + 1);
		if (left != right) {
			lazy[layer][node*2] += lazy[layer][node];
			lazy[layer][node*2+1] += lazy[layer][node];
		}
		lazy[layer][node] = 0;
	}
	if (left > right || left > en || right < st) return;
	if (left >= st && right <= en) {
		tree[layer][node] += val * (right - left + 1);
		if (left != right) {
			lazy[layer][node*2] += val;
			lazy[layer][node*2+1] += val;
		}
		return;
	}
	MultiplyUpdate(node*2, left, (left+right)/2, st, en, layer, val);
	MultiplyUpdate(node*2+1, (left+right)/2+1, right, st, en, layer, val);
	tree[layer][node] = tree[layer][node*2] + tree[layer][node*2+1];
}

i64 get(i64 node, i64 left, i64 right, i64 st, i64 en, i64 layer, i64 modulo) {
	if (lazy[layer][node] != 0) {
		tree[layer][node] += lazy[layer][node] * (right - left + 1);
		if (left != right) {
			lazy[layer][node*2] += lazy[layer][node];
			lazy[layer][node*2+1] += lazy[layer][node];
		}
		lazy[layer][node] = 0;
	}
	if (left > right || left > en || right < st) return 0;
	if (left >= st && right <= en) return tree[layer][node];
	i64 p1 = get(node*2, left, (left+right)/2, st, en, layer, modulo);
	i64 p2 = get(node*2+1, 1+(left+right)/2, right, st, en, layer, modulo);
	return (p1 + p2);
}

i64 modPow(i64 a, i64 b, i64 m) {
	if (b == 0) return 1;
	if (b == 1) return a;
	i64 tmp = modPow(a, b/2, m);
	if (b % 2 == 0) return ((tmp * tmp) % m);
	if (b % 2 == 1) return ((((tmp * tmp) % m) * a) % m);
}

i64 GetProduct(i64 node, i64 left, i64 right, i64 st, i64 en, i64 modulo) {
	vector<i64> ans(35, 0);
	for (i64 layer=0; layer<35; layer++) ans[layer] = get(node, left, right, st, en, layer, modulo);
	i64 answer = 1;
	for (i64 i=0; i<35; i++) {
		answer = (answer * modPow(snt[i], ans[i], modulo)) % modulo;
	}
	return answer;
}

int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	PrimeInitialize();
	int T; cin >> T;
	while (T--) {
		i64 N, M; cin >> N >> M;
		for (i64 j=0; j<35; j++) {
			for (i64 i=0; i<555555; i++) tree[j][i] = 0;
			for (i64 i=0; i<555555; i++) lazy[j][i] = 0;
		}
		while (M--) {
			i64 cmd, L, R, q; cin >> cmd >> L >> R >> q;
			if (cmd == 0) {
				if (L <= R) cout << GetProduct(1, 1, N, L, R, q) << endl;
				else {
					i64 tmp1 = GetProduct(1, 1, N, L, N, q);
					i64 tmp2 = GetProduct(1, 1, N, 1, R, q);
					i64 ans = (tmp1 * tmp2) % q;
					cout << ans << endl;
				}
			}
			else if (cmd == 1) {
				for (i64 i=0; i<prime[q].size(); i++) {
					pii zz = prime[q][i];
					if (L <= R) MultiplyUpdate(1, 1, N, L, R, zz.fi, zz.se);
					else {
						MultiplyUpdate(1, 1, N, L, N, zz.fi, zz.se);
						MultiplyUpdate(1, 1, N, 1, R, zz.fi, zz.se);
					}
				}
			}
			else if (cmd == 2) {
				for (i64 i=0; i<prime[q].size(); i++) {
					pii zz = prime[q][i];
					if (L <= R) MultiplyUpdate(1, 1, N, L, R, zz.fi, -zz.se);
					else {
						MultiplyUpdate(1, 1, N, L, N, zz.fi, -zz.se);
						MultiplyUpdate(1, 1, N, 1, R, zz.fi, -zz.se);
					}
				}
			}
		}
	}
	return 0;
}
