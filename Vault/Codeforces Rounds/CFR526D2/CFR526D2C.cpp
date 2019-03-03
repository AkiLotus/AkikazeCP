#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

const long long Mod = 1000000007LL;
string s; int n;

void Input() {
	cin >> s; n = s.size();
}

void Solve() {
	vector<long long> cnta;
	for (int i=0; i<n; i++) {
		if (s[i] == 'b') continue;
		int tmp = (s[i] == 'a'), j = i;
		while (j+1 < n && s[j+1] != 'b') {
			j++; tmp += (s[j] == 'a');
		}
		cnta.push_back(1LL * tmp); i = j;
	}
	int N = cnta.size();
	long long ans = 0;
	long long accumulated = 0;
	vector<long long> dp = cnta;
	for (int i=0; i<N; i++) {
		dp[i] += accumulated * cnta[i]; dp[i] %= Mod;
		accumulated += dp[i]; accumulated %= Mod;
	}
	for (auto x: dp) {ans += x; ans %= Mod;}
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
