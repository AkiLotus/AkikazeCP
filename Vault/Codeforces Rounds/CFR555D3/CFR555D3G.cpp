#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define y0 holdtheflower
#define y1 enjoythecolorandscent
#define yn walkthroughthesoulgarden
#define j1 feelthewarmbreathofkindnessandsalvation

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, m; vector<vector<int>> a;

void Input() {
	cin >> n >> m; a.resize(n, vector<int>(m));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}
}

void Solve() {
	vector<vector<int>> A0 = a, A1 = a;
	vector<int> R0(n, 0), C0(m, 0), R1(n, 0), C1(m, 0);
	bool valid0 = true, valid1 = true;
	for (int j=0; j<m; j++) {
		if (!A0[0][j]) continue; C0[j] = 1;
		for (int i=0; i<n; i++) A0[i][j] = 1 - A0[i][j];
	}
	for (int j=0; j<m; j++) {
		if (A1[n-1][j]) continue; C1[j] = 1;
		for (int i=0; i<n; i++) A1[i][j] = 1 - A1[i][j];
	}
	bool all1_0 = false;
	for (int i=1; i<n; i++) {
		vector<int> tmp = A0[i];
		sort(tmp.begin(), tmp.end());
		if (tmp == A0[i]) {
			if (tmp[0] == 0 && tmp.back() == 1) {
				if (!all1_0) all1_0 = true;
				else {valid0 = false; break;}
			}
			else if (tmp[0] == 0) {
				if (all1_0) R0[i] = 1;
			}
			else if (tmp[0] == 1) {
				if (!all1_0) R0[i] = 1;
			}
		}
		else {
			for (auto &z: A0[i]) z = 1 - z;
			R0[i] = 1; tmp = A0[i];
			sort(tmp.begin(), tmp.end());
			if (tmp == A0[i]) {
				if (tmp[0] == 0 && tmp.back() == 1) {
					if (!all1_0) all1_0 = true;
					else {valid0 = false; break;}
				}
			}
			else {valid0 = false; break;}
		}
	}
	bool all1_1 = false;
	for (int i=n-2; i>=0; i--) {
		vector<int> tmp = A1[i];
		sort(tmp.begin(), tmp.end());
		if (tmp == A1[i]) {
			if (tmp[0] == 0 && tmp.back() == 1) {
				if (!all1_1) all1_1 = true;
				else {valid1 = false; break;}
			}
			else if (tmp[0] == 1) {
				if (all1_1) R1[i] = 1;
			}
			else if (tmp[0] == 0) {
				if (!all1_1) R1[i] = 1;
			}
		}
		else {
			for (auto &z: A1[i]) z = 1 - z;
			R1[i] = 1; tmp = A1[i];
			sort(tmp.begin(), tmp.end());
			if (tmp == A1[i]) {
				if (tmp[0] == 0 && tmp.back() == 1) {
					if (!all1_1) all1_1 = true;
					else {valid1 = false; break;}
				}
			}
			else {valid1 = false; break;}
		}
	}
	if (valid0) {
		cout << "YES\n";
		for (auto z: R0) cout << z; cout << endl;
		for (auto z: C0) cout << z; cout << endl;
		return;
	}
	if (valid1) {
		cout << "YES\n";
		for (auto z: R1) cout << z; cout << endl;
		for (auto z: C1) cout << z; cout << endl;
		return;
	}
	cout << "NO\n";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/