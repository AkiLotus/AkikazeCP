#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define y0 takethescythe
#define y1 reapyourenemies
#define yn feedontheirflesh
#define j1 ascendthroughtheirblood

#define endl '\n'
typedef long long i64;
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> lights;
vector<int> switchAt;

vector<int> ask(vector<int> switches) {
	cout << "ASK " << switches.size();
	for (auto z: switches) cout << " " << (z + 1);
	cout << endl; cout.flush();
	vector<int> result;
	for (int i=0; i<switches.size(); i++) {
		int z; cin >> z; z--;
		result.push_back(z);
	}
	return result;
}

void answer() {
	cout << "ANSWER";
	for (int i=0; i<n; i++) switchAt[lights[i]] = i;
	for (auto z: switchAt) cout << " " << (z + 1);
	cout << endl; cout.flush();
}

void Input() {
	cin >> n; lights.resize(n);
	switchAt.resize(n);
	for (int i=0; i<n; i++) lights[i] = i;
}

void Solve() {
	vector<pair<int, int>> segs;
	if (n > 1) segs.push_back({0, n-1});
	vector<pair<int, int>> newLeft, newRight;
	while (!segs.empty()) {
		vector<int> left;
		for (int i=0; i<segs.size(); i++) {
			int L = segs[i].first, R = segs[i].second, x = (L + R) / 2;

			for (int id=L; id<=x; id++) left.push_back(id);

			if (L < x) newLeft.push_back({L, x}); // always valid
			if (x+1 < R) newRight.push_back({x+1, R});
		}

		vector<int> affected = ask(left);
		vector<bool> vis(n, false);
		for (auto z: affected) vis[z] = true;

		for (int i=0; i<segs.size(); i++) {
			int L = segs[i].first, R = segs[i].second, x = (L + R) / 2;
			vector<int> items;
			for (int id=L; id<=R; id++) items.push_back(lights[id]);

			int leftPtr = L, rightPtr = x + 1;
			for (auto z: items) {
				if (vis[z]) {lights[leftPtr] = z; leftPtr++;}
				else {lights[rightPtr] = z; rightPtr++;}
			}
		}

		segs.clear();
		for (auto P: newLeft) segs.push_back(P);
		for (auto P: newRight) segs.push_back(P);
		newLeft.clear(); newRight.clear();
	}
	answer();
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0);
	Input(); Solve(); return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/