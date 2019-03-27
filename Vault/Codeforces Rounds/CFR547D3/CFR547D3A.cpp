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

int n, m;

void Input() {
	cin >> n >> m;
}

void Solve() {
	int n2 = 0, n3 = 0, m2 = 0, m3 = 0;
	while (m % 2 == 0) {m2++; m /= 2;}
	while (m % 3 == 0) {m3++; m /= 3;}
	while (n % 2 == 0) {n2++; n /= 2;}
	while (n % 3 == 0) {n3++; n /= 3;}
	if (n != m) {cout << "-1\n"; return;}
	if (n2 > m2 || n3 > m3) {cout << "-1\n"; return;}
	cout << (m2 - n2 + m3 - n3) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/