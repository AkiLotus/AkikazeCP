#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

const long long Mod = 998244353LL;

int n; string s;

void Input() {
	cin >> n >> s;
}

void Solve() {
	long long ans = 1;
	if (s[0] == s[n-1]) {
		string Z = s;
		sort(Z.begin(), Z.end());
		if (Z[0] == Z[n-1]) ans = 1LL * n * n;
		else {
			int prefix = 1, suffix = 1;
			for (int i=0; i<n; i++) {
				if (s[i] != s[0]) break;
				else prefix++;
			}
			for (int i=n-1; i>=0; i--) {
				if (s[i] != s[0]) break;
				else suffix++;
			}
			ans = 1LL * prefix * suffix;
		}
	}
	else {
		ans += 2;
		for (int i=1; i<n; i++) {
			if (s[i] != s[0]) break;
			else ans++;
		}
		for (int i=n-2; i>=0; i--) {
			if (s[i] != s[n-1]) break;
			else ans++;
		}
	}
	cout << ans % Mod << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
