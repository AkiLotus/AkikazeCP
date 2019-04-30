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

int k; string s, t;

void Input() {
	cin >> k >> s >> t;
}

void Solve() {
	vector<int> r(k);
	for (int i=0; i<k; i++) r[i] = (s[i] - 'a');
	for (int i=k-1; i>=0; i--) {
		int diff = (t[i] - s[i]);
		int q = diff / 2, rem = diff - q * 2;
		if (rem != 0) r[i+1] += rem * 13;
		r[i] += q;
	}
	for (int i=k-1; i>0; i--) {
		if (r[i] < 0) {
			int carry = -r[i] / 26 + (r[i] % 26 != 0);
			r[i] += carry * 26; r[i-1] -= carry;
		}
		if (r[i] > 25) {
			int carry = +r[i] / 26;
			r[i] -= carry * 26; r[i-1] += carry;
		}
	}
	for (int i=0; i<k; i++) {
		cout << char(97+ r[i]);
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/