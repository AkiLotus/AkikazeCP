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

int n; vector<int> a;

void Input() {
	cin >> n; a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	set<int> Set;
	for (auto z: a) Set.insert(z);
	if (Set.size() == 1) {cout << "0\n"; return;}
	if (Set.size() == 2) {
		int Min = *Set.begin(), Max = *Set.rbegin();
		if ((Max - Min) % 2 != 0) cout << (Max - Min) << endl;
		else cout << ((Max - Min) / 2) << endl; return;
	}
	if (Set.size() == 3) {
		vector<int> A(3); int id = 0;
		for (auto it=Set.begin(); it!=Set.end(); it++) A[id++] = *it;
		if (A[1] - A[0] != A[2] - A[1]) {cout << "-1\n"; return;}
		cout << (A[2] - A[1]) << endl; return;
	}
	cout << "-1\n"; return;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/