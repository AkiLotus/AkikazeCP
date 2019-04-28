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

int n; vector<int> a;
vector<bool> is235;
vector<bool> num235(100001, false);

void Preprocess() {
	for (int i=1; i<100001; i++) {
		int x = i;
		while (x % 2 == 0) x /= 2;
		while (x % 3 == 0) x /= 3;
		while (x % 5 == 0) x /= 5;
		if (x == 1) num235[i] = true;
	}
}

void Input() {
	cin >> n; a.clear(); is235.clear();
	a.resize(n); is235.resize(n, false); int id = 0;
	for (auto &z: a) {
		cin >> z;
		is235[id] = num235[z];
		id += 1;
	}
}

void Solve() {
	int ans = 0;
	for (int i=0; i<n; i++) {
		if (!is235[i]) continue;
		int j = i;
		while (j+1 < n && is235[j+1]) j++;
		ans = max(ans, j-i+1); i = j;
	}
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Preprocess();
	int T = 1; if (MultiTest) cin >> T;
	while(T--) {Input(); Solve();}
	return 0;
}