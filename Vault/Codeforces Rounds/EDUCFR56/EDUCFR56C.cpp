#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int n; vector<long long> b, a;

void Input() {
	cin >> n; a.resize(n);
	b.resize(n/2);
	for (auto &x: b) cin >> x;
}

void Solve() {
	a[n/2-1] = b[n/2-1] / 2;
	a[n/2] = a[n/2-1] + (b[n/2-1] % 2);
	for (int i=n/2-2; i>=0; i--) {
		long long MaxLeft = a[i+1];
		long long MinRight = a[n-1-i-1];
		a[i] = min(b[i]/2, min(MaxLeft, b[i]-MinRight));
		a[n-1-i] = b[i] - a[i];
	}
	for (auto x: a) cout << x << " "; cout << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
