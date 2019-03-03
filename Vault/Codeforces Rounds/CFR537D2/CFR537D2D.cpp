#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

const int Mod = 1000000007;
vector<int> cnt(52, 0), ftrl;

int modPow(int a, int b) {
	int res = 1;
	while (b > 0) {
		if (b % 2 != 0) {b--; res = (1LL * res * a) % Mod;}
		else {b /= 2; a = (1LL * a * a) % Mod;}
	}
	return res;
}

int nCr(int n, int r) {
	int numer = ftrl[n];
	int denom = (1LL * ftrl[n-r] * ftrl[r]) % Mod;
	return (1LL * numer * modPow(denom, Mod-2)) % Mod;
}

string s; int n, q;

void Input() {
	cin >> s; n = s.size(); ftrl.resize(n+1, 1);
	for (int i=2; i<=n; i++) ftrl[i] = (1LL * ftrl[i-1] * i) % Mod;
	for (auto c: s) {
		if (c >= 'A' && c <= 'Z') cnt[(c-'A')+0]++;
		if (c >= 'a' && c <= 'z') cnt[(c-'a')+26]++;
	}
}

void Solve() {
	cin >> q;
	while (q--) {
		int x, y; cin >> x >> y; x--; y--;
		int id1 = s[x] - 'A', id2 = s[y] - 'A';
		if (s[x] >= 'a') id1 = (s[x] - 'a') + 26;
		if (s[y] >= 'a') id2 = (s[y] - 'a') + 26;
		int count = cnt[id1]; if (id1 != id2) count += cnt[id2];
		//tracker5(x, y, id1, id2, count);
		if (count > n / 2) {cout << "0\n"; continue;}
		int arrangement = 1;
		int formation = (2LL * nCr(n/2, count)) % Mod;
		if (id1 != id2) arrangement = nCr(count, cnt[id1]);
		int InverseProduct = ftrl[n/2];
		for (int i=0; i<52; i++) {
			if (i == id1 || i == id2) continue;
			InverseProduct = (1LL * InverseProduct * modPow(ftrl[cnt[i]], Mod-2)) % Mod;
		}
		int supplement = InverseProduct;
		if (n/2 > count) supplement = 0;
		for (int i=0; i<52; i++) {
			if (i == id1 || i == id2) continue;
			if (cnt[i] == 0) continue;
			if (cnt[i] > n/2 - count) continue;
			for (int j=0; j<52; j++) {
				if (j == id1 || j == id2 || j == i) continue;
				if (cnt[i] + cnt[j] != n/2 - count) continue;
				int Tmp1 = ftrl[n/2 - count], Tmp2 = InverseProduct;
				Tmp1 = (1LL * Tmp1 * modPow(ftrl[cnt[i]], Mod-2)) % Mod;
				Tmp1 = (1LL * Tmp1 * modPow(ftrl[cnt[j]], Mod-2)) % Mod;
				Tmp2 = (1LL * Tmp2 * ftrl[cnt[i]]) % Mod;
				Tmp2 = (1LL * Tmp2 * ftrl[cnt[j]]) % Mod;
				//tracker4(i, j, Tmp1, Tmp2);
				supplement += (1LL * Tmp1 * Tmp2) % Mod;
				supplement %= Mod;
			}
		}
		for (int i=0; i<52; i++) {
			if (i == id1 || i == id2) continue;
			if (cnt[i] == 0) continue;
			if (cnt[i] != n/2 - count) continue;
			int Tmp1 = ftrl[n/2 - count], Tmp2 = InverseProduct;
			Tmp1 = (1LL * Tmp1 * modPow(ftrl[cnt[i]], Mod-2)) % Mod;
			Tmp2 = (1LL * Tmp2 * ftrl[cnt[i]]) % Mod;
			//tracker4(i, j, Tmp1, Tmp2);
			supplement += (1LL * Tmp1 * Tmp2) % Mod;
			supplement %= Mod;
		}
		//tracker3(arrangement, supplement, formation);
		int res = (((1LL * arrangement * supplement) % Mod) * formation) % Mod;
		cout << res << endl;
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
