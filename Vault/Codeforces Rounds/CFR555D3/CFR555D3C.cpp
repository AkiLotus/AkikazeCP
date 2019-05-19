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

int n; vector<int> a;

void Input() {
	cin >> n; a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	int L = 0, R = n - 1, Last = INT_MIN;
	bool unable = false;
	string s = "";
	while (L <= R) {
		if (a[L] == a[R]) {
			if (a[L] <= Last) unable = true;
			break;
		}
		if (a[L] < a[R] && Last < a[L]) {s += 'L'; Last = a[L]; L++;}
		else if (a[L] > a[R] && Last < a[R]) {s += 'R'; Last = a[R]; R--;}
		else if (a[L] < a[R] && Last < a[R]) {s += 'R'; Last = a[R]; R--;}
		else if (a[L] > a[R] && Last < a[L]) {s += 'L'; Last = a[L]; L++;}
		else {unable = true; break;}
	}
	if (L <= R && !unable) {
		int tmpL = 0, tmpR = 0, curLast = Last;
		for (int x=L; x<=R; x++) {
			if (curLast < a[x]) {tmpL++; curLast = a[x];}
			else break;
		}
		curLast = Last;
		for (int x=R; x>=L; x--) {
			if (curLast < a[x]) {tmpR++; curLast = a[x];}
			else break;
		}
		if (tmpL > tmpR) for (int x=0; x<tmpL; x++) s += 'L';
		else for (int x=0; x<tmpR; x++) s += 'R';
	}
	cout << s.size() << endl << s << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/