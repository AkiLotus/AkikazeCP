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
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116L;
const long double EPS = 0.000000001L, Gold = ((1.0L+sqrt(5.0L))/2.0L);
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int MultiTest = 1;

int n; vector<pair<int, int>> A;

void DFS(int z, vector<bool> &vis, vector<vector<int>> &adj, int &siz) {
	siz = siz + 1; vis[z] = true;
	for (auto t: adj[z]) {
		if (vis[t]) continue;
		DFS(t, vis, adj, siz);
	}
}

void Input() {
	cin >> n; A.clear(); A.resize(n);
	for (int i=0; i<n; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}
}

void Solve() {
	sort(A.begin(), A.end());
	vector<vector<int>> adj(n);
	for (int i=0; i<n; i++) {
		adj[i].push_back(A[i].second);
		adj[A[i].second].push_back(i);
	}
	vector<bool> vis(n, false);
	long long ans = 0;
	for (int i=0; i<n; i++) {
		if (vis[i]) continue;
		int siz = 0; DFS(i, vis, adj, siz);
		ans += siz - 1;
	}
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1; if (MultiTest) cin >> T;
	while(T--) {Input(); Solve();}
	return 0;
}