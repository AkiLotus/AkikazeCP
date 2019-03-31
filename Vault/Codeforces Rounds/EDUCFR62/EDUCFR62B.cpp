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

int n; string s;

void Input() {
	cin >> n >> s;
}

void Solve() {
	int firstRt = -1, lastRt = -1;
	int firstLt = -1, lastLt = -1;
	for (int i=0; i<n; i++) {
		if (s[i] == '<') {lastLt = i; if (firstLt == -1) firstLt = i;}
		if (s[i] == '>') {lastRt = i; if (firstRt == -1) firstRt = i;}
	}
	int clearRight = 0, clearLeft = 0;
	for (int i=lastLt+1; i<n; i++) clearRight += (s[i] == '>');
	for (int i=firstRt-1; i>=0; i--) clearLeft += (s[i] == '<');
	cout << min(clearRight, clearLeft) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/