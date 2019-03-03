#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n; string s; vector<int> a;

void Input() {
	cin >> n >> s; a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	vector<long long> dp_monochromic(n, 0);
	vector<vector<long long> > dp(n, vector<long long>(n, 0));
	for (int i=0; i<n; i++) {
		for (int z=0; z<i; z++) dp_monochromic[i] = max(dp_monochromic[i], dp_monochromic[z] + dp_monochromic[i-z-1]);
		dp_monochromic[i] = max(dp_monochromic[i], (long long)a[i]);
	}
	for (int x=0; x<n; x++) {
		for (int i=0; i<n-x; i++) {
			int j = i + x;
			if (*min_element(s.begin()+i, s.begin()+j+1) == *max_element(s.begin()+i, s.begin()+j+1)) {
				dp[i][j] = dp_monochromic[x]; continue;
			}
			long long ans0 = 0, ans1 = 0, cnt0 = 0, cnt1 = 0;
			for (int z=i; z<=j; z++) {cnt0 += (s[z] == '0'); cnt1 += (s[z] == '1');}
			ans0 = dp_monochromic[cnt0-1]; ans1 = dp_monochromic[cnt1-1];
			for (int z1=i; z1<=j; z1++) {
				int z2 = z1;
				while (z2+1 <= j && s[z2+1] == s[z1]) z2++;
				if (s[z1] == '1') ans0 += dp_monochromic[z2-z1];
				else ans1 += dp_monochromic[z2-z1];
				z1 = z2;
			}
			dp[i][j] = max(ans0, ans1);
		}
	}
	
	cout << dp_monochromic << endl;
	
	cout << dp[0][n-1] << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
