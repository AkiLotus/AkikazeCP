#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

string s; int n, q, a, b, c, d;
vector<vector<int>> cnt;

void Input() {
	cin >> s >> q; n = s.size();
	cnt.resize(n, vector<int>(26, 0));
	for (int i=0; i<n; i++) {
		cnt[i][s[i]-'a']++;
	}
}

void Solve() {
	for (int i=1; i<n; i++) {
		for (int j=0; j<26; j++) {
			cnt[i][j] += cnt[i-1][j];
		}
	}
	while (q--) {
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		bool flag = true;
		for (int j=0; j<26; j++) {
			int sum1 = cnt[b][j]; if (a > 0) sum1 -= cnt[a-1][j];
			int sum2 = cnt[d][j]; if (c > 0) sum2 -= cnt[c-1][j];
			if (sum1 != sum2) {flag = false; break;}
		}
		if (!flag) cout << "NO\n";
		else cout << "YES\n";
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/