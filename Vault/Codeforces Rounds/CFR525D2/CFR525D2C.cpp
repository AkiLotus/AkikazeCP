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
	cout << n+1 << endl;
	for (int i=n-1; i>=0; i--) {
		int Rem = (i - a[i] + n * 1000000) % n;
		cout << "1 " << i+1 << " " << Rem << endl;
		for (int x=0; x<=i; x++) a[x] += Rem;
	}
	cout << "2 " << n << " " << n << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
