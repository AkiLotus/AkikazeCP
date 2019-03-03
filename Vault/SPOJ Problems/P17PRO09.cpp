/**
	Template by proptit_4t41
	Applied for C++11/C++14
	Add -std=c++14 to your IDE.
**/

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

template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
//int T, cas = 0; // for multi-testcase problems
i64 N, M, len; vector<vector<i64>> adj(111111);
i64 nChain = 0, nBase;
vector<vector<i64>> chain;
vector<i64> chainHead(111), chainInd(111111), parent(111111);
vector<i64> posInBase(111111), linearVertex;
vector<i64> linearArr, tree(2222222), lazy(2222222);

/** -----EXTENSIVE FUNCTIONS----- **/
i64 left(i64 z) {
	return (z << 1);
}

i64 right(i64 z) {
	return (z << 1) + 1;
}

// nChain chuỗi hiện tại. Sau khi kết thúc việc phân tách thì đây sẽ là tổng số chuỗi.
// chainHead[c] đỉnh đầu của chuỗi c
// chainInd[u] chuỗi mà đỉnh u nằm trong.

void hld(int u) {
	//tracker1(u);
    // Nếu chuỗi hiện tại chưa có đỉnh đầu (đỉnh gần gốc nhất) thì đặt u làm đỉnh đầu của nó.
	if (chainHead[nChain] == 0) {
		chainHead[nChain] = u;
		chain.pub(vector<i64>(0));
	}

    // Gán chuỗi hiện tại cho u
	chainInd[u] = nChain;

    // Giải thích bên dưới
	posInBase[u] = nBase++;
	linearVertex.pub(u);
	chain[nChain].pub(u);

    // Biến lưu đỉnh con đặc biệt của u
	int mxVtx = -1;

    // Tìm đỉnh con đặc biệt trong số những đỉnh con của u
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != parent[u]) {
			parent[v] = u;
			if (mxVtx == -1) {
				mxVtx = v;
			}
		}
	}

    // Nếu tìm ra đỉnh con đặc biệt (u không phải là đỉnh lá) thì di chuyển đến đỉnh đó
	if (mxVtx > -1)
		hld(mxVtx);

    // Sau khi đi hết một chuỗi thì tăng nChain lên và bắt đầu một chuỗi mới
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != parent[u] && v != mxVtx) {
			nChain++;
			hld(v);
		}
	}
}

void ITUpdate(i64 n, i64 L, i64 R, i64 s, i64 e, i64 x) {
	if (lazy[n] != 0) {
		tree[n] += lazy[n];
		if (L != R) {
			lazy[left(n)] += lazy[n];
			lazy[right(n)] += lazy[n];
		}
		lazy[n] = 0;
	}
	if (L > R || L > e || R < s) return;
	if (L >= s && R <= e) {
		tree[n] += x;
		if (L != R) {
			lazy[left(n)] += x;
			lazy[right(n)] += x;
		}
		return;
	}
	ITUpdate(left(n), L, (L+R)/2, s, e, x);
	ITUpdate(right(n), (L+R)/2+1, R, s, e, x);
	tree[n] = max(tree[left(n)], tree[right(n)]);
}

i64 ITQuery(i64 n, i64 L, i64 R, i64 s, i64 e) {
	if (lazy[n] != 0) {
		tree[n] += lazy[n];
		if (L != R) {
			lazy[left(n)] += lazy[n];
			lazy[right(n)] += lazy[n];
		}
		lazy[n] = 0;
	}
	if (L > R || L > e || R < s) return -LINF;
	if (L >= s && R <= e) return tree[n];
	i64 p1 = ITQuery(left(n), L, (L+R)/2, s, e);
	i64 p2 = ITQuery(right(n), (L+R)/2+1, R, s, e);
	return max(p1, p2);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> N;
	for (i64 i=1; i<N; i++) {
		i64 x, y; cin >> x >> y;
		adj[x].pub(y); adj[y].pub(x);
	}
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	hld(1); nChain++; len = linearVertex.size(); cin >> M;
	//for (i64 i=0; i<len; i++) cout << linearVertex[i] << " "; cout << endl;
	//cout << nChain << endl;
	//for (i64 i=0; i<nChain; i++) {
	//	for (i64 j=0; j<chain[i].size(); j++) cout << chain[i][j] << " "; cout << endl;
	//}
	linearArr.resize(len, 0);
	while (M--) {
		string cmd; i64 p1, p2; cin >> cmd >> p1 >> p2;
		if (cmd == "add") {
			if (adj[p1].size() == 1) { // leaf node
				i64 z = posInBase[p1];
				ITUpdate(1, 0, len-1, z, z, p2);
			}
			else if (p1 == 1) { // root node
				ITUpdate(1, 0, len-1, 0, len-1, p2);
			}
			else {
				i64 zazz = parent[p1], azaa = p1;
				i64 L = posInBase[p1];
				while (zazz != 1 && lower_bound(adj[zazz].begin(), adj[zazz].end(), azaa) == adj[zazz].end()-1) {
					azaa = zazz; zazz = parent[azaa];
				}
				if (zazz == 1 && lower_bound(adj[zazz].begin(), adj[zazz].end(), azaa) == adj[zazz].end()-1) {
					//cout << L << " " << len-1 << endl;
					ITUpdate(1, 0, len-1, L, len-1, p2);
				}
				else {
					i64 tmp = lower_bound(adj[zazz].begin(), adj[zazz].end(), azaa) - adj[zazz].begin() + 1;
					i64 R = posInBase[adj[zazz][tmp]] - 1;
					//cout << L << " " << R << endl;
					ITUpdate(1, 0, len-1, L, R, p2);
				}
			}
		}
		else if (cmd == "max") {
			if (chainInd[p1] == chainInd[p2]) {
				i64 L = posInBase[p1], R = posInBase[p2];
				if (L > R) {
					i64 tmp = L; L = R; R = tmp;
				}
				cout << ITQuery(1, 0, len-1, L, R) << endl;
			}
			else {
				i64 x = p1, y = p2;
				stack<i64> sx, sy;
				while (x != 1) {
					//cout << "x = " << x << endl;
					//cout << "chainInd[" << x << "] = " << chainInd[x] << endl;
					//cout << "chainHead[" << chainInd[x] << "] = " << chainHead[chainInd[x]] << endl;
					sx.push(x);
					if (chainHead[chainInd[x]] != x) x = chainHead[chainInd[x]];
					else x = parent[x];
					//cout << "x = " << x << endl;
				}
				while (y != 1) {
					//cout << "y = " << y << endl;
					//cout << "chainInd[" << y << "] = " << chainInd[y] << endl;
					//cout << "chainHead[" << chainInd[y] << "] = " << chainHead[chainInd[y]] << endl;
					sy.push(y);
					if (chainHead[chainInd[y]] != y) y = chainHead[chainInd[y]];
					else y = parent[y];
					//cout << "y = " << y << endl;
				}
				i64 lastx = 1, lasty = 1;
				while (!sx.empty() && !sy.empty() && chainInd[sx.top()] == chainInd[sy.top()]) {
					lastx = sx.top(); lasty = sy.top();
					sx.pop(); sy.pop();
				}
				i64 LCA = lastx;
				if (posInBase[lastx] < posInBase[lasty]) LCA = lasty;
				i64 ans = -LINF;
				i64 tmp = LCA;
				while (!sx.empty()) {
					i64 qq = sx.top(); sx.pop();
					//cout << tmp << " " << qq << endl;
					if (chainInd[tmp] == chainInd[qq]) {
						i64 L = posInBase[tmp], R = posInBase[qq];
						if (L > R) {
							i64 tmp = L; L = R; R = tmp;
						}
						ans = max(ans, ITQuery(1, 0, len-1, L, R));
						//cout << L << " " << R << endl;
						//cout << "ans = " << ans << endl;
					}
					tmp = qq;
				}
				tmp = LCA;
				while (!sy.empty()) {
					i64 qq = sy.top(); sy.pop();
					//cout << tmp << " " << qq << endl;
					if (chainInd[tmp] == chainInd[qq]) {
						i64 L = posInBase[tmp], R = posInBase[qq];
						if (L > R) {
							i64 tmp = L; L = R; R = tmp;
						}
						ans = max(ans, ITQuery(1, 0, len-1, L, R));
						//cout << L << " " << R << endl;
						//cout << "ans = " << ans << endl;
					}
					tmp = qq;
				}
				cout << ans << endl;
			}
		}
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
