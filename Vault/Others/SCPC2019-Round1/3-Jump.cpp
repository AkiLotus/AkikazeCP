#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int test = 0;
long long L, R;
int stepsRequired[450000];
vector<int> Start[450000];
vector<int> End[450000];

void Preprocess() {
	stepsRequired[1] = 1;
	for (int x=2; x<450000; x++) {
		int sum = 0;
		stepsRequired[x] = INT_MAX;
		for (int i=1; i<=x; i++) {
		    sum += i;
		    if (sum > x) break;
		    stepsRequired[x] = min(stepsRequired[x], stepsRequired[x-sum] + i);
		}
	}
}

void Input() {
	cin >> L >> R;
	for (int i=0; i<450000; i++) {
		Start[i].clear(); End[i].clear();
	}
}

void Solve() {
	int ans = 0;

	if (L < 450000) {
		for (int x=L; x<=min(449999LL, R); x++) {
			ans = max(ans, stepsRequired[x]);
		}
		L = min(449999LL, R) + 1;
	}

	if (L <= R) {
		long long sum = 0;
		for (int i=1; i<450000; i++) {
			sum += i;
			long long Mn = sum, Mx = sum + i;
			if (Mx < L) continue;
			if (R < Mn) break;
			Mn = max(Mn, L); Mx = min(R, Mx);
			//cout << i << " " << sum << " " << Mn << " " << Mx << endl;
			Start[Mn-sum].push_back(i);
			End[Mx-sum].push_back(i);
		}
		set<int> Set;
		for (int i=0; i<450000; i++) {
			for (auto z: Start[i]) Set.insert(z);
			if (!Set.empty()) {
				int Max = *Set.rbegin();
				ans = max(ans, Max + stepsRequired[i]);
			}
			for (auto z: End[i]) Set.erase(z);
		}
	}
	
	cout << "Case #" << (++test) << endl;
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL); Preprocess();
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}