#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, m, s, f, c, r; vector<int> a;
long long Max = 0;

void Input() {
	cin >> n >> m; a.resize(n);
	for (auto &x: a) cin >> x;
}

void Solve() {
	while (m--) {
		cin >> s >> f >> c >> r; s--; f--;
		int MaximumRefuel = min(f-s-1, r);
		priority_queue<long long> Heap;
		for (int i=s; i<f-1; i++) Heap.push_
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
