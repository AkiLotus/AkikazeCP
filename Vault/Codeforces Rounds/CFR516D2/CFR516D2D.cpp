#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define i64 long long
#define ld long double
#define rsz resize
#define pub push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);

template<class T> int cntbit(T s) { return __builtin_popcountll(s); }

void Exit();

#define MultiTest 227420978
#undef MultiTest // Switch this off if submitting multi-test problems.

typedef pair<pii, pii> ppp;
i64 n, m, r, c, x, y; vector<vc> a; vector<vb> vis;

void Input() {
	cin >> n >> m >> r >> c >> x >> y;
	r--; c--; a.rsz(n, vc(m, '.'));
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}
}

void Solve() {
	vis.rsz(n, vb(m, false)); vis[r][c] = true;
	queue<ppp> Q; Q.push(mp(mp(r, c), mp(0LL, 0LL)));
	for (i64 i=r-1; i>=0; i--) {
		if (a[i][c] == '*') break;
		vis[i][c] = true; Q.push(mp(mp(i, c), mp(0LL, 0LL)));
	}
	for (i64 i=r+1; i<n; i++) {
		if (a[i][c] == '*') break;
		vis[i][c] = true; Q.push(mp(mp(i, c), mp(0LL, 0LL)));
	}
	i64 ans = 0;
	while (!Q.empty()) {
		ppp Z = Q.front(); Q.pop(); ans++;
		pii coor = Z.fi; i64 L = Z.se.fi, R = Z.se.se;
		i64 X = coor.fi, Y = coor.se;
		for (i64 i=X-1; i>=0; i--) {
			if (vis[i][Y] || a[i][Y] == '*') break;
			vis[i][Y] = true; Q.push(mp(mp(i, Y), mp(L, R)));
		}
		for (i64 i=X+1; i<n; i++) {
			if (vis[i][Y] || a[i][Y] == '*') break;
			vis[i][Y] = true; Q.push(mp(mp(i, Y), mp(L, R)));
		}
		if (Y-1 >= 0 && !vis[X][Y-1] && a[X][Y-1] != '*' && L+1 <= x) {
			vis[X][Y-1] = true; Q.push(mp(mp(X, Y-1), mp(L+1, R)));
		}
		if (Y+1 < m && !vis[X][Y+1] && a[X][Y+1] != '*' && R+1 <= y) {
			vis[X][Y+1] = true; Q.push(mp(mp(X, Y+1), mp(L, R+1)));
		}
	}
	cout << ans;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	
	#ifndef MultiTest
		Input();
		Solve();
	#else
		int T; cin >> T;
		while(T--) {Input(); Solve();}
	#endif

	return 0;
}

void Exit() {
	exit(0);
}