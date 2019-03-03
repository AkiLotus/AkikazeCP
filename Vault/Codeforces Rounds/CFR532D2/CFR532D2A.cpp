#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, k; vector<int> a;

void Input() {
	cin >> n >> k; a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	int ans = 0;
	for (int x=0; x<k; x++) {
		int e = 0, s = 0;
		for (int i=0; i<n; i++) {
			if (i % k == x) continue;
			e += (a[i] == 1); s += (a[i] == -1);
		}
		ans = max(ans, abs(s - e));
	}
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
