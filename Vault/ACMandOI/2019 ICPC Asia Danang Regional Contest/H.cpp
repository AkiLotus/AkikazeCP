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

int n, m, ans = 0; vector<vector<int>> a;
vector<vector<int>> rowClues, colClues;
vector<vector<int>> rowFormations;

bool validRowMask(int mask, int i) {
	vector<int> clue; int tmp = 0;
	for (int j=0; j<=m; j++) {
		if (j < m && ((mask >> j) & 1)) tmp++;
		else {
			if (tmp > 0) clue.push_back(tmp);
			tmp = 0;
		}
	}
	return (rowClues[i] == clue);
}

bool validCol(int j) {
	vector<int> clue; int tmp = 0;
	for (int i=0; i<=n; i++) {
		if (i < n && a[i][j] == 1) tmp++;
		else {
			if (tmp > 0) clue.push_back(tmp);
			tmp = 0;
		}
	}
	return (colClues[j] == clue);
}

bool validBoard() {
	for (int j=0; j<m; j++) {
		if (!validCol(j)) return false;
	}
	return true;
}

void Try(int filledRow) {
	if (filledRow == n) {ans += validBoard(); return;}

	for (auto mask: rowFormations[filledRow]) {
		for (int j=0; j<m; j++) {
			if ((mask >> j) & 1) a[filledRow][j] = 1;
		}
		Try(filledRow + 1);
		for (int j=0; j<m; j++) {
			if ((mask >> j) & 1) a[filledRow][j] = 0;
		}
	}
}

void Input() {
	cin >> n >> m; a.resize(n, vector<int>(m, 0));
	rowClues.resize(n); colClues.resize(m); rowFormations.resize(n);
	for (auto &row: rowClues) {
		int siz; cin >> siz; row.resize(siz);
		for (auto &z: row) cin >> z;
	}
	for (auto &col: colClues) {
		int siz; cin >> siz; col.resize(siz);
		for (auto &z: col) cin >> z;
	}
}

void Solve() {
	for (int mask=0; mask<(1 << m); mask++) {
		for (int i=0; i<n; i++) {
			if (validRowMask(mask, i)) rowFormations[i].push_back(mask);
		}
	}

	Try(0);
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/