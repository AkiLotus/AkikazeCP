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

void Input() {
	cin >> n; a.clear(); a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	int Max = INT_MIN;
	priority_queue<int> ansList;
	for (int i=n-1; i>=0; i--) {
		if (a[i] > Max) ansList.push(a[i]);
		Max = max(Max, a[i]);
	}
	while (!ansList.empty()) {
		cout << ansList.top() << " ";
		ansList.pop();
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1; if (MultiTest) cin >> T;
	while(T--) {Input(); Solve();}
	return 0;
}