#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int l, r, d;

void Input() {
	cin >> l >> r >> d;
}

void Solve() {
	if (d < l) {cout << d << endl; return;}
	int z = r / d + 1;
	cout << z * d << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int q; cin >> q; while (q--) {Input(); Solve();} return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
