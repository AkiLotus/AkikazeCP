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

int n, h; vector<int> a;

void Input() {
	cin >> n >> h; a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	int ans = 0;
	for (int cnt=1; cnt<=n; cnt++) {
		vector<int> Tmp(cnt);
		for (int i=0; i<cnt; i++) Tmp[i] = a[i];
		sort(Tmp.rbegin(), Tmp.rend());
		int RemHeight = h; bool valid = true;
		for (int i=0; i<cnt; i++) {
			if (RemHeight < Tmp[i]) {valid = false; break;}
			if (i == cnt-1) break;
			if (RemHeight < Tmp[i+1]) {valid = false; break;}
			RemHeight -= max(Tmp[i], Tmp[i+1]); i++;
		}
		if (valid) ans = cnt;
		else break;
	}
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/