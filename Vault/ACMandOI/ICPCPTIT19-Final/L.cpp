#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define y0 withindarkness
#define y1 apinklotusbloomed
#define yn carryingapurplesoul
#define j1 togetherformingtheTeam

#define endl '\n'
#define i64 long long
#define ld long double
const long long Mod = 1000000009LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116L;
const long double EPS = 0.000000001L, Gold = ((1.0L+sqrt(5.0L))/2.0L);
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int MultiTest = 0;

int N, M, S; vector<vector<int>> Q;
vector<i64> Tree, Lazy;

void Propagate(int node, int st, int en) {
	Tree[node] += ((1LL * Lazy[node] * (en - st + 1)) % Mod);
	if (st != en) {
		Lazy[node*2+1] += Lazy[node];
		Lazy[node*2+1] %= Mod;
		Lazy[node*2+2] += Lazy[node];
		Lazy[node*2+2] %= Mod;
	}
	Lazy[node] = 0;
}

void Update(int node, int st, int en, int L, int R, i64 x) {
	Propagate(node, st, en);
	if (st > en || en < L || R < st) return;
	if (L <= st && en <= R) {Lazy[node] += x; Propagate(node, st, en); return;}
	Update(node*2+1, st, (st+en)/2+0, L, R, x);
	Update(node*2+2, (st+en)/2+1, en, L, R, x);
	Tree[node] = Tree[node*2+1] + Tree[node*2+2];
}

i64 Get(int node, int st, int en, int L, int R) {
	Propagate(node, st, en);
	if (st > en || en < L || R < st) return 0LL;
	if (L <= st && en <= R) return Tree[node];
	i64 p1 = Get(node*2+1, st, (st+en)/2+0, L, R);
	i64 p2 = Get(node*2+2, (st+en)/2+1, en, L, R);
	return ((p1 + p2) % Mod);
}

void Input() {
	cin >> N >> M >> S; Q.resize(S);
	Tree.resize(N*4); Lazy.resize(N*4);
	for (auto &Subset: Q) {
		int G; cin >> G; Subset.resize(G);
		for (auto &z: Subset) {cin >> z; z--;}
		sort(Subset.begin(), Subset.end());
	}
}

void Solve() {
	vector<vector<pair<int, int>>> RangeList(S);
	for (int x=0; x<S; x++) {
		for (int i=0; i<Q[x].size(); i++) {
			int j = i;
			while (j+1 < N && Q[x][j] + 1 == Q[x][j+1]) j++;
			RangeList[x].push_back({Q[x][i], Q[x][j]}); i = j;
		}
	}
	while (M--) {
		int type; cin >> type;
		if (type == 1) {
			int U, T; cin >> U >> T; U--;
			for (auto Pair: RangeList[U]) {
				int L = Pair.first, R = Pair.second;
				Update(0, 0, N-1, L, R, T);
			}
		}
		else if (type == 2) {
			int U; i64 ans = 0; cin >> U; U--;
			for (auto Pair: RangeList[U]) {
				int L = Pair.first, R = Pair.second;
				ans += Get(0, 0, N-1, L, R) % Mod; ans %= Mod;
			}
			cout << (ans % Mod) << endl;
		}
		else if (type == 3) {
			int L, R, T; cin >> L >> R >> T; L--; R--;
			Update(0, 0, N-1, L, R, T);
		}
		else if (type == 4) {
			int L, R; cin >> L >> R; L--; R--;
			cout << (Get(0, 0, N-1, L, R) % Mod) << endl;
		}
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1; if (MultiTest) cin >> T;
	while(T--) {Input(); Solve();}
	return 0;
}