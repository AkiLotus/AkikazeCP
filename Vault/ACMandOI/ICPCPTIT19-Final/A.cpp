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

i64 K;

pair<i64, i64> lim[] = {{0LL, 0LL}, {1LL, 9LL}, {10LL, 99LL}, {100LL, 999LL}, {1000LL, 9999LL},
{10000LL, 99999LL},  {100000LL, 999999LL}, {1000000LL, 9999999LL}, {10000000LL, 99999999LL}, 
{100000000LL, 999999999LL}, {1000000000LL, 9999999999LL}};

i64 calc(i64 N) {
	i64 res = 0;
	for (int i=1; i<=10; i++) {
		if (N < lim[i].first) break;
		i64 L = lim[i].first, R = min(lim[i].second, N);
		i64 qq = (R + L) * (R - L + 1) / 2; qq *= i;
		res += qq;
	}
	return res;
}

i64 binsearch(i64 L, i64 R) {
	i64 res = R;
	while (L <= R) {
		i64 mid = (L + R) / 2;
		if (calc(mid) >= K) {
			res = mid; R = mid - 1;
		}
		else L = mid + 1;
	}
	return res;
}

void Input() {
	cin >> K;
}

void Solve() {
	cout << binsearch(1LL, K) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1; if (MultiTest) cin >> T;
	while(T--) {Input(); Solve();}
	return 0;
}