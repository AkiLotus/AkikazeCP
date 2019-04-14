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

int n;

vector<int> split() {
	vector<int> List(8, -1);
	for (int x=1; x<n; x++) {
		cout << "? 1 1 " << x << " " << n << endl; fflush(stdout);
		int cnt; cin >> cnt; if (cnt == -1) exit(11112000);
		if (cnt % 2 == 1) {
			if (List[0] == -1) {List[0] = x; List[1] = 1; List[2] = x; List[3] = n;}
		}
		else if (List[0] != -1 && List[4] == -1) {List[4] = x; List[5] = 1; List[6] = x; List[7] = n;}
	}
	if (List[0] != -1 && List[4] == -1) {List[4] = n; List[5] = 1; List[6] = n; List[7] = n;}
	if (List[0] != -1) return List;
	for (int y=1; y<n; y++) {
		cout << "? 1 1 " << n << " " << y << endl; fflush(stdout);
		int cnt; cin >> cnt; if (cnt == -1) exit(11112000);
		if (cnt % 2 == 1) {
			if (List[0] == -1) {List[0] = 1; List[1] = y; List[2] = n; List[3] = y;}
		}
		else if (List[0] != -1 && List[4] == -1) {List[4] = 1; List[5] = y; List[6] = n; List[7] = y;}
	}
	if (List[0] != -1 && List[4] == -1) {List[4] = 1; List[5] = n; List[6] = n; List[7] = n;}
	return List;
}

pair<int, int> extract (int xa, int ya, int xb, int yb) {
	int dim = 1, L = 1, R = n;
	if (xa == xb) dim = 2; else dim = 1;
	while (L < R) {
		int M = (L + R) / 2;
		if (dim == 1) cout << "? " << xa << " " << ya << " " << M << " " << yb << endl;
		else cout << "? " << xa << " " << ya << " " << xb << " " << M << endl;
		fflush(stdout); int cnt; cin >> cnt; if (cnt == -1) exit(11112000);
		if (cnt % 2 == 1) {
			R = M;
			if (dim == 1) xb = R;
			else yb = R;
		}
		else {
			L = M + 1;
			if (dim == 1) xa = L;
			else ya = L;
		}
	}
	return make_pair(xa, ya);
}

void Input() {
	cin >> n;
}

void Solve() {
	vector<int> coorList = split();
	pair<int, int> res1 = extract(coorList[0], coorList[1], coorList[2], coorList[3]);
	pair<int, int> res2 = extract(coorList[4], coorList[5], coorList[6], coorList[7]);
	cout << "! " << res1.first << " " << res1.second << " " << res2.first << " " << res2.second << endl; fflush(stdout);
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/