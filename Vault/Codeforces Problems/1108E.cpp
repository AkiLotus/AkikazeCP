#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, m; vector<int> a;
vector<pair<int, int>> seg;

void Input() {
	cin >> n >> m; a.resize(n);
	for (auto &z: a) cin >> z;
	for (int i=0; i<m; i++) {
		int l, r; cin >> l >> r; l--; r--;
		seg.push_back({l, r});
	}
}

void Solve() {
	vector<int> L = a, R = a;
	vector<vector<int>> LList(n), RList(n);
	vector<int> MinL(n, 1000000000), MinR(n, 1000000000);
	for (int i=1; i<n; i++) MinL[i] = min(MinL[i-1], a[i-1]);
	for (int i=n-2; i>=0; i--) MinR[i] = min(MinR[i+1], a[i+1]);
	vector<vector<int>> SegR(n), SegL(n);
	for (int i=0; i<m; i++) {
		int l = seg[i].first, r = seg[i].second;
		SegR[r].push_back(i); SegL[l].push_back(i);
	}
	for (int i=1; i<n; i++) {
		MinL[i] = min(MinL[i], MinL[i-1]);
		for (auto x: LList[i-1]) LList[i].push_back(x);
		for (auto id: SegR[i-1]) {
			LList[i].push_back(id+1);
			for (int z=seg[id].first; z<=seg[id].second; z++) {
				L[z]--; MinL[i] = min(MinL[i], L[z]);
			}
		}
	}
	for (int i=n-2; i>=0; i--) {
		MinR[i] = min(MinR[i], MinR[i+1]);
		for (auto x: RList[i+1]) RList[i].push_back(x);
		for (auto id: SegL[i+1]) {
			RList[i].push_back(id+1);
			for (int z=seg[id].first; z<=seg[id].second; z++) {
				R[z]--; MinR[i] = min(MinR[i], R[z]);
			}
		}
	}
	pair<int, int> optimal = {0, -1};
	for (int i=0; i<n; i++) {
		optimal = max(optimal, {a[i] - min(MinL[i], MinR[i]), i});
	}
	if (optimal == make_pair(0, -1)) {cout << "0\n0\n\n"; return;}
	cout << optimal.first << endl;
	cout << LList[optimal.second].size() + RList[optimal.second].size() << endl;
	for (auto x: LList[optimal.second]) cout << x << " ";
	for (auto x: RList[optimal.second]) cout << x << " ";
	cout << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
*  Thuy-Trang Tran, #Team4T's Leader     *
*  #Team4T Primary Flagship - Salvation  *
\******************************************/
