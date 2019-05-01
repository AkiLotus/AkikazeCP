#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define y0 takethescythe
#define y1 reapyourenemies
#define yn feedontheirflesh
#define j1 ascendthroughtheirblood

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, k; vector<int> a;

void Input() {
	cin >> n >> k; a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	vector<int> team(n, 0);
	set<pair<int, int>> StudentValue;
	set<int> StudentID;
	for (int i=0; i<n; i++) {
		StudentID.insert(i);
		StudentValue.insert({a[i], i});
	}
	int turn = 1;
	while (!StudentID.empty()) {
		pair<int, int> MaxToken = *StudentValue.rbegin();
		int id = MaxToken.second; team[id] = turn;
		StudentValue.erase(MaxToken); StudentID.erase(id);
		int tmp = k;
		auto it1 = StudentID.lower_bound(id);
		while (tmp > 0 && it1 != StudentID.begin()) {
			it1--; int newID = *it1; tmp--;
			team[newID] = turn;
			StudentID.erase(newID);
			StudentValue.erase({a[newID], newID});
			it1 = StudentID.lower_bound(id);
		}
		tmp = k;
		auto it2 = StudentID.upper_bound(id);
		while (tmp > 0 && it2 != StudentID.end()) {
			int newID = *it2; tmp--; it2++;
			team[newID] = turn;
			StudentID.erase(newID);
			StudentValue.erase({a[newID], newID});
			it2 = StudentID.upper_bound(id);
		}
		turn ^= 3;
	}
	for (auto z: team) cout << z; cout << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/