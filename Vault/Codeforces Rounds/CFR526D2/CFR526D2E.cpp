#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

long long n, k; string s, t;

void Input() {
	cin >> n >> k >> s >> t;
}

void Solve() {
	if (k == 1 || s == t) {cout << n << endl; return;}
	k = k - 2; long long ans = 2;
	long long lefttree = 1, righttree = 1;
	long long petr = 0;
	while (petr < n && s[petr] == t[petr]) {petr++; ans++;}
	for (; petr < n-1; petr++) {
		long long left_supply = min(lefttree - (s[petr+1] == 'b'), k);
		lefttree += left_supply; k -= left_supply;
		long long right_supply = min(righttree - (t[petr+1] == 'a'), k);
		righttree += right_supply; k -= right_supply;
		ans += lefttree; ans += righttree;
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
