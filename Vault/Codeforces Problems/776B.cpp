#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int n; vector<int> primediv;

void Input() {
	cin >> n;
	primediv.resize(n+2, 1);
}

void Solve() {
	for (int i=2; i<=n+1; i++) {
		if (primediv[i] > 1) continue;
		for (int j=2; i*j<=n+1; j++) {
			primediv[i*j] = 2;
		}
	}
	cout << *max_element(primediv.begin(), primediv.end()) << endl;
	for (int i=2; i<=n+1; i++) cout << primediv[i] << " "; cout << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
