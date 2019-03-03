#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int n; vector<int> a;

void Input() {
	cin >> n; a.resize(n);
	for (auto &x: a) cin >> x;
}

void Solve() {
	int ans = 1000000000;
	for (int x=0; x<n; x++) {
		int tmp = 0;
		for (int i=0; i<n; i++) {
			tmp += abs(x - i) * 2 * a[i] + x * 2 * a[i] + 2 * i * a[i];
		}
		ans = min(ans, tmp);
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
