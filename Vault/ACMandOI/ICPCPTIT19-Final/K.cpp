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

string s; vector<int> cnt;

void Input() {
	cin >> s; cnt.clear(); cnt.resize(10, 0);
	for (auto &ch: s) cnt[ch-'0']++;
}

void Solve() {
	vector<pair<int, int>> even, odd;
	for (int i=0; i<10; i++) {
		if (cnt[i] == 0) continue;
		if (cnt[i] % 2 == 0) even.push_back({cnt[i], i});
		else odd.push_back({cnt[i], i});
	}
	sort(odd.rbegin(), odd.rend());
	if (even.empty() || (even.size() == 1 && even[0].second == 0)) {
		if (odd.size() == 1 && odd[0].second == 0) {cout << "0\n"; return;}
		int id = 0; while (odd[id].second == 0) id++;
		int k = odd[id].second, v = odd[id].first;
		for (int i=0; i<v; i++) cout << k; cout << endl; return;
	}
	vector<bool> chosen(10, false);
	for (int i=0; i<10; i++) {
		if (cnt[i] > 0 && cnt[i] % 2 == 0) {
			chosen[i] = true;
		}
	}
	if (!odd.empty()) {
		int k = odd[0].second;
		chosen[k] = true;
	}
	for (int i=9; i>=0; i--) {
		if (!chosen[i]) continue;
		for (int x=0; x<cnt[i]/2; x++) cout << i;
	}
	if (!odd.empty()) {
		int k = odd[0].second, v = odd[0].first;
		cout << k;
	}
	for (int i=0; i<10; i++) {
		if (!chosen[i]) continue;
		for (int x=0; x<cnt[i]/2; x++) cout << i;
	}
	cout << endl; return;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1; if (MultiTest) cin >> T;
	while(T--) {Input(); Solve();}
	return 0;
}