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

string s; int n;

void Input() {
	cin >> s; n = s.size();
}

void Solve() {
	vector<int> Minx(n), Maxx(n), Miny(n), Maxy(n);
	vector<int> x(n), y(n);
	int zx = 0, zy = 0;
	for (int i=0; i<n; i++) {
		char c = s[i];
		if (c == 'W') {zx--;}
		if (c == 'S') {zx++;}
		if (c == 'A') {zy--;}
		if (c == 'D') {zy++;}
		x[i] = zx; y[i] = zy;
	}
	Minx[n-1] = Maxx[n-1] = x[n-1]; Miny[n-1] = Maxy[n-1] = y[n-1];
	for (int i=n-2; i>=0; i--) {
		Minx[i] = min(Minx[i+1], x[i]);
		Maxx[i] = max(Maxx[i+1], x[i]);
		Miny[i] = min(Miny[i+1], y[i]);
		Maxy[i] = max(Maxy[i+1], y[i]);
	}
	int ans = INT_MAX;
	for (int i=n-1; i>=0; i--) {
		zx = x[i]; zy = y[i];
		char c = s[i];
		if (c == 'W') zx++;
		if (c == 'S') zx--;
		if (c == 'A') zy++;
		if (c == 'D') zy--;
		int newMinx = zx - (x[i] - Minx[n-1]);
		int newMaxx = zx + (Maxx[n-1] - x[i]);
		int newMiny = zy - (y[i] - Miny[n-1]);
		int newMaxy = zy + (Maxy[n-1] - y[i]);
		tracker7(i, zx, zy, newMinx, newMaxx, newMiny, newMaxy);
		ans = min(ans, (newMaxx - newMinx + 1) * (newMaxy - newMiny + 1));
	}
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/