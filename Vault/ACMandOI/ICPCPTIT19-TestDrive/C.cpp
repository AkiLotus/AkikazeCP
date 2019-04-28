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

int MultiTest = 0;

int N; long long ans = 0; vector<int> a;
vector<long long> sum(2000007, 0);

void Preprocess() {
	for (int i=2; i<2000007; i++) {
		if (sum[i] != 0) continue;
		for (long long exp=1, d=i; d < 2000007; exp++, d*=i) {
			for (int j=1; j<=2000006/d; j++) {
				if (j % i == 0) continue;
				sum[d*j] += 1LL * i * exp;
			}
		}
	}
}

void Input() {
	cin >> N; a.resize(N);
	for (auto &z: a) {
		cin >> z;
		ans += sum[z];
	}
}

void Solve() {
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1; if (MultiTest) cin >> T; Preprocess();
	while(T--) {Input(); Solve();}
	return 0;
}