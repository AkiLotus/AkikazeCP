#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

const int Mod = 8000101;

int n, m; vector<string> a;
vector<vector<vector<int>>> prefixSum;

int ManacherProcess(vector<int> &Hash, vector<bool> &possiblePalim) {
	int res = 0; vector<int> odd(n, 0), even(n, 0);
	// for odd-length palindromes
	for (int i=0, l=0, r=-1; i<n; i++) {
		if (!possiblePalim[i]) continue;
		int k = 0; if (i <= r) k = min(odd[l+r-i], r-i);
		while (0 <= i-k-1 && i+k+1 < n && possiblePalim[i-k-1] && possiblePalim[i+k+1] && Hash[i-k-1] == Hash[i+k+1]) k++;
		odd[i] = k; res += odd[i] + 1;
		if (i + k > r) {l = i - k; r = i + k;}
	}
	// for even-length palindromes
	for (int i=1, l=0, r=0; i<n; i++) {
		if (Hash[i-1] != Hash[i]) continue;
		if (!possiblePalim[i-1] || !possiblePalim[i]) continue;
		int k = 0; if (i <= r) k = min(even[l+r-i+1], r-i);
		while (0 <= (i-1)-k-1 && i+k+1 < n && possiblePalim[(i-1)-k-1] && possiblePalim[i+k+1] && Hash[(i-1)-k-1] == Hash[i+k+1]) k++;
		even[i] = k; res += even[i] + 1;
		if (i + k > r) {l = (i-1) - k; r = i + k;}
	}
	return res;
}

void Input() {
	cin >> n >> m; a.resize(n);
	prefixSum.resize(n, vector<vector<int>>(m, vector<int>(26, 0)));
	for (int i=0; i<n; i++) {
		cin >> a[i];
		for (int j=0; j<m; j++) {
			prefixSum[i][j][a[i][j]-'a']++;
		}
	}
}

void Solve() {
	int ans = 0;
	for (int i=0; i<n; i++) {
		for (int j=1; j<m; j++) {
			for (int k=0; k<26; k++) {
				prefixSum[i][j][k] += prefixSum[i][j-1][k];
			}
		}
	}
	for (int L=0; L<m; L++) {
		for (int R=L; R<m; R++) {
			vector<int> Hash(n, 0);
			vector<bool> possiblePalim(n, false);
			for (int i=0; i<n; i++) {
				int oddcount = 0;
				for (int x=0; x<26; x++) {
					int sum = prefixSum[i][R][x];
					if (L > 0) sum -= prefixSum[i][L-1][x];
					oddcount += sum % 2;
					Hash[i] *= 257;
					Hash[i] += sum; Hash[i] %= Mod;
				}
				possiblePalim[i] = (oddcount <= 1);
			}
			ans += ManacherProcess(Hash, possiblePalim);
		}
	}
	cout << ans;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/