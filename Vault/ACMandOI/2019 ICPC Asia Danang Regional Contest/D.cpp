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

string st, en;
int alpha;

void Input() {
	cin >> st >> en >> alpha;
	alpha = alpha * 2;
}

void Solve() {
	int h1 = atoi(st.substr(0, 2).c_str());
	int h2 = atoi(en.substr(0, 2).c_str());
	int m1 = atoi(st.substr(3, 2).c_str()) * 11;
	int m2 = atoi(en.substr(3, 2).c_str()) * 11;
	int a1 = h1 * 60 * 11 + m1, a2 = h2 * 60 * 11 + m2;
	int ans = 0;
	for (int a=a1; a<=a2; a++) {
		int reformed = a % 720;
		if (reformed > 360) reformed = 720 - reformed;
		ans += (reformed == alpha);
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