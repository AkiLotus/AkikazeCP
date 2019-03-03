#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, k; vector<int> a; string s;

void Input() {
	cin >> n >> k; a.resize(n);
	for (auto &z: a) cin >> z;
	cin >> s;
}

void Solve() {
	long long ans = 0;
	for (int i=0; i<n; i++) {
		int cnt = 0, j = i;
		priority_queue<int> Heap;
		Heap.push(a[i]);
		while (j+1 < n && s[j+1] == s[i]) {
			j++; Heap.push(a[j]);
		}
		while (cnt < k && !Heap.empty()) {
			ans += Heap.top();
			Heap.pop(); cnt++;
		}
		i = j;
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
