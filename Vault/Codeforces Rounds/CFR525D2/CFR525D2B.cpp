#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int n, k; vector<int> a;

void Input() {
	cin >> n >> k; a.resize(n);
	for (auto &x: a) cin >> x;
}

void Solve() {
	int ptr = 0;
	sort(a.begin(), a.end());
	while (k--) {
		while (ptr < n && ((ptr == 0 && a[ptr] == 0) || a[ptr] == a[ptr-1])) ptr++;
		if (ptr == n) cout << "0\n";
		else {
			if (ptr == 0) cout << a[0] << endl;
			else cout << a[ptr] - a[ptr-1] << endl;
			ptr = ptr + 1;
		}
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
