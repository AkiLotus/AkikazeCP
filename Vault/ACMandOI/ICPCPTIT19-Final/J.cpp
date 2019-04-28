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

int n; string polynomial;
int initmask = 0;

int square(int mask) {
	vector<int> a(n+1, 0);
	vector<int> b(n+1, 0);
	vector<int> c(n+1, 0);
	for (int i=0; i<=n; i++) {
		a[i] = ((initmask >> i) & 1);
	}
	for (int i=0; i<=n; i++) {
		b[i] = ((mask >> i) & 1);
	}
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=n; j++) {
			c[(i + j) % n] = (c[(i + j) % n] + a[i] * b[j]) % 2;
		}
	}
	int newmask = 0;
	for (int i=0; i<=n; i++) {
		if (c[i] == 1) newmask += (1 << i);
	}
	return newmask;
}

void proceedMask(vector<bool> &vis, int &mask) {
	vis[mask] = true;
	mask = square(mask);
}

void Input() {
	cin >> n >> polynomial;
	polynomial += '+';
}

void Solve() {
	int mask = 0;

	bool isX = false; int exp = -1;
	for (auto ch: polynomial) {
		if (ch == 'x') isX = true;
		else if (ch == '^') exp = 0;
		else if (ch >= '0' && ch <= '9' && exp >= 0) {
			exp *= 10; exp += (ch - '0');
		}
		else if (ch == '+') {
			if (!isX) mask += (1 << 0);
			else if (isX && exp <= 0) mask += (1 << 1);
			else mask += (1 << exp);
			isX = false; exp = -1;
		}
	}

	initmask = mask;

	vector<bool> vis(4444444, false); int ans = 0;
	while (!vis[mask]) {
		ans++; proceedMask(vis, mask);
	}
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1; if (MultiTest) cin >> T;
	while(T--) {Input(); Solve();}
	return 0;
}