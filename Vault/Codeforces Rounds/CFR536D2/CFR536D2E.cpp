#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

const long long Inf = 1000000000000000000LL;

int n, m, k;
vector<tuple<int, int, int, int>> envelopes;
vector<vector<int>> startAt, endAt;

void Input() {
	cin >> n >> m >> k; envelopes.resize(k);
	startAt.resize(n+1); endAt.resize(n+1);
	for (int i=0; i<k; i++) {
		int s, t, d, w; cin >> s >> t >> d >> w;
		envelopes[i] = {s, t, d, w};
		startAt[s].push_back(i); endAt[t].push_back(i);
	}
}

void Solve() {
	vector<vector<long long>> dp(n+1, vector<long long>(m+1, Inf));
	multiset<tuple<int, int, int, int>> Heap; dp[0][0] = 0;
	for (int i=0; i<n; i++) {
		for (auto id: startAt[i+1]) {
			tuple<int, int, int, int> T = envelopes[id];
			int s = get<0>(T), t = get<1>(T), d = get<2>(T), w = get<3>(T);
			Heap.insert({w, d, s, t});
		}
		for (int j=0; j<=m; j++) {
			if (dp[i][j] == Inf) continue;
			if (j < m) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
			if (!Heap.empty()) {
				tuple<int, int, int, int> T = *Heap.rbegin();
				int w = get<0>(T), d = get<1>(T), s = get<2>(T), t = get<3>(T);
				dp[d][j] = min(dp[d][j], dp[i][j] + w);
			}
			else dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
		}
		for (auto id: endAt[i+1]) {
			tuple<int, int, int, int> T = envelopes[id];
			int s = get<0>(T), t = get<1>(T), d = get<2>(T), w = get<3>(T);
			Heap.erase(Heap.find({w, d, s, t}));
		}
	}
	cout << *min_element(dp[n].begin(), dp[n].end()) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
*  Thuy-Trang Tran, #Team4T's Leader     *
*  #Team4T Primary Flagship - Salvation  *
\******************************************/
