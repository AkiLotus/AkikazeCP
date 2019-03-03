#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define y0 holdtheflower
#define y1 enjoythecolorandscent
#define yn walkthroughthesoulgarden
#define j1 feelthewarmbreathofkindnessandsalvation

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, m; vector<int> a;
vector<long long> ps;

int indexBinsearch(int top, int bot, int d) {
	int res = top;
	while (top <= bot) {
		int mid = (top + bot) / 2;
		int regularCycle = (mid + 1) / d;
		if (a[mid] >= regularCycle) {res = mid; top = mid + 1;}
		else bot = mid - 1;
	}
	return res;
}

bool possible(int d) {
	int maxIndex = indexBinsearch(0, n-1, d);
	long long res = ps[maxIndex];
	int regularCycle = (maxIndex + 1) / d;
	int Rem = (maxIndex + 1) % d;
	res -= (1LL * regularCycle * (regularCycle - 1) / 2) * d;
	res -= regularCycle * Rem;
	return (res >= m);
}

int binsearch(int top, int bot) {
	int res = bot;
	while (top <= bot) {
		int mid = (top + bot) / 2;
		if (possible(mid)) {res = mid; bot = mid - 1;}
		else top = mid + 1;
	}
	return res;
}

void Input() {
	cin >> n >> m; a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	sort(a.rbegin(), a.rend());
	ps.resize(n, a[0]);
	for (int i=1; i<n; i++) ps[i] = ps[i-1] + a[i];
	if (ps[n-1] < m) {cout << "-1\n"; return;}
	cout << binsearch(1, n) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/