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

int r, c, k;
vector<vector<char>> a;
string charset = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

void Input() {
	cin >> r >> c >> k; a.clear();
	a.resize(r, vector<char>(c, '.'));
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			cin >> a[i][j];
		}
	}
}

void Solve() {
	int rice = 0;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			rice += (a[i][j] == 'R');
		}
	}
	int standard = rice / k, remnants = rice % k;
	vector<pair<int, int>> cellOrder;
	for (int i=0; i<r; i++) {
		if (i % 2 == 0) {for (int j=0; j<c; j++) cellOrder.push_back({i, j});}
		if (i % 2 != 0) {for (int j=c-1; j>=0; j--) cellOrder.push_back({i, j});}
	}
	int currentChicken = 0, tmpRice = 0;
	vector<vector<char>> allocation(r, vector<char>(c, '.'));
	for (auto cell: cellOrder) {
		int x = cell.first, y = cell.second;
		allocation[x][y] = charset[currentChicken];
		tmpRice += (a[x][y] == 'R');
		if (tmpRice == standard + (currentChicken < remnants) && currentChicken < k-1) {
			currentChicken += 1; tmpRice = 0;
		}
	}
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			cout << allocation[i][j];
		}
		cout << endl;
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/