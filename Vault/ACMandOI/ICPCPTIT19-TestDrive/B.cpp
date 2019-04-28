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

i64 solve (i64 a, i64 b, i64 m) {
	i64 n = (i64) sqrt (m + .0) + 1;
	i64 an = 1;
	for (i64 i=0; i<n; ++i)
		an = (an * a) % m;
	map<i64,i64> vals;
	for (i64 i=1, cur=an; i<=n; ++i) {
		if (!vals.count(cur))
			vals[cur] = i;
		cur = (cur * an) % m;
	}
	vector<i64> ansList;
	for (i64 i=0, cur=b; i<=n; ++i) {
		if (vals.count(cur)) {
			i64 ans = vals[cur] * n - i;
			if (ans < m) ansList.push_back(ans);
		}
		cur = (cur * a) % m;
	}
	if (ansList.empty()) return -1;
	return (*min_element(ansList.begin(), ansList.end()));
}

i64 a, b, M;

void Input() {
	cin >> a >> b >> M;
}

void Solve() {
	cout << solve(a, b, M) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1; if (MultiTest) cin >> T;
	while(T--) {Input(); Solve();}
	return 0;
}