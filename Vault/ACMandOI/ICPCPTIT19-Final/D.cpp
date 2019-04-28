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

string s; int n;

bool check(int st, int i, int j, vector<vector<int>> &Hash) {
	if (st > 0 && j == n-1) return true;
	int p1 = Hash[st][i], p2 = Hash[i+1][j];
	int maxLen = max(i-st+1, j-i);
	if (j + maxLen >= n) return false;
	int p3 = Hash[j+1][j+maxLen];
	if ((p1 + p2) % Mod == p3) return check(i+1, j, j+maxLen, Hash);
	if (j + maxLen + 1 >= n) return false;
	p3 = Hash[j+1][j+maxLen+1];
	if ((p1 + p2) % Mod == p3) return check(i+1, j, j+maxLen+1, Hash);
	return false;
}

void Input() {
	cin >> s; n = s.size();
}

void Solve() {
	vector<vector<int>> Hash(n, vector<int>(n, 0));
	for (int i=0; i<n; i++) {
		for (int j=i; j<n; j++) {
			if (j > i) Hash[i][j] = Hash[i][j-1];
			Hash[i][j] = (1LL * Hash[i][j] * 10 + (s[j] - '0')) % Mod;
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			if (check(0, i, j, Hash)) {cout << "Yes\n"; return;}
		}
	}
	cout << "No\n";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1; if (MultiTest) cin >> T;
	while(T--) {Input(); Solve();}
	return 0;
}