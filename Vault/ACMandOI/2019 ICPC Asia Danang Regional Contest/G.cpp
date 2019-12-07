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

int x;

void Input() {
	cin >> x;
}

void Solve() {
	int ans = 0;
	while (x > 1) {
		string s = to_string(x); int n = s.size();
		vector<int> cnt(10, 0);
		for (auto c: s) cnt[c-'0']++;
		if (n == 1) {ans += (x - 1); x = 1; continue;}

		if (cnt[0] == n-1) {ans++; x--; continue;}
		if (s[n-1] == '0') {
			string new_s = "";
			for (int i=1; i<10; i++) {
				if (cnt[i]) {cnt[i]--; new_s += char(48+i); break;}
			}
			for (int i=0; i<10; i++) {
				while (cnt[i]) {cnt[i]--; new_s += char(48+i);}
			}
			x = atoi(new_s.c_str());
			ans += 1; continue;
		}

		if (cnt[1] > 0) {
			if (cnt[1] == 1 && s[n-1] == '1') {
				string new_s = "";
				for (int i=1; i<10; i++) {
					if (cnt[i]) {cnt[i]--; new_s += char(48+i); break;}
				}
				for (int i=0; i<10; i++) {
					while (cnt[i]) {cnt[i]--; new_s += char(48+i);}
				}
				x = atoi(new_s.c_str());
				ans += 1; continue;
			}
			else {
				ans += x % 10; x -= x % 10;
				continue;
			}
		}
		else {
			ans += (x % 10 - 1); x -= (x % 10 - 1);
		}
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