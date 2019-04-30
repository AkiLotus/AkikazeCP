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
	vector<int> Odd, Even;
	for (auto z: a) {
		if (z % 2 != 0) Odd.push_back(z);
		else Even.push_back(z);
	}
	sort(Odd.begin(), Odd.end());
	sort(Even.begin(), Even.end());
	if (abs((int)Odd.size() - (int)Even.size()) <= 1) {cout << "0\n"; return;}
	int odd = 0, even = 0;
	if (Odd.size() < Even.size()) {
		odd = Odd.size();
		even = odd + 1;
	}
	else if (Odd.size() > Even.size()) {
		even = Even.size();
		odd = even + 1;
	}
	for (int i=0; i<odd; i++) Odd.pop_back();
	for (int i=0; i<even; i++) Even.pop_back();
	int sum = 0;
	for (auto z: Odd) sum += z;
	for (auto z: Even) sum += z;
	cout << sum << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/