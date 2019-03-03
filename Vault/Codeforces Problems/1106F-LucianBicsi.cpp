#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int linearRec(vector<int> S, vector<int> tr, int k, int Mod) {
	int n = S.size();

	auto combine = [&](vector<int> a, vector<int> b) {
		vector<int> res(n * 2 + 1);
		for (int i=0; i<n+1; i++) for (int j=0; j<n+1; j++)
			res[i + j] = (res[i + j] + (1LL * a[i] * b[j]) % Mod) % Mod;
		for (int i = 2 * n; i > n; --i) for (int j=0; j<n; j++)
			res[i - 1 - j] = (res[i - 1 - j] + (1LL * res[i] * tr[j]) % Mod) % Mod;
		res.resize(n + 1);
		return res;
	};

	vector<int> pol(n + 1), e(pol);
	pol[0] = e[1] = 1;

	for (++k; k; k /= 2) {
		if (k % 2) pol = combine(pol, e);
		e = combine(e, e);
	}

	int res = 0;
	for (int i=0; i<n; i++) res = (res + (1LL * pol[i + 1] * S[i]) % Mod) % Mod;
	return res;
}

int discrete_root(int n, int k, int a) {
	function<int(int, int, int)> powmod = [&](int a, int b, int p) -> int {
		int res = 1;
		while (b)
			if (b & 1) res = int (res * 1LL * a % p), --b;
			else a = int (a * 1LL * a % p),  b >>= 1;
		return res;
	};
	
	function<int(int)> generator = [&](int p) -> int {
		vector<int> fact;
		int phi = p-1, n = phi;
		for (int i=2; i<=sqrt(n); i++) {
			if (n % i == 0) {
				fact.push_back(i);
				while (n % i == 0) n /= i;
			}
		}
		if (n > 1) fact.push_back (n);
		
		for (int res=2; res<=p; ++res) {
			bool ok = true;
			for (size_t i=0; i<fact.size() && ok; ++i)
				ok &= powmod (res, phi / fact[i], p) != 1;
			if (ok) return res;
		}
		return -1;
	};
	
	if (a == 0) return 0;
	int g = generator(n), sq = sqrt(n) + 1;
	vector < pair<int, int> > dec(sq);
	for (int i=1; i<=sq; ++i) dec[i-1] = {powmod (g, int (i * sq * 1ll * k % (n - 1)), n), i};
	sort(dec.begin(), dec.end()); int any_ans = -1;
	for (int i=0; i<sq; ++i) {
		int my = powmod(g, int (i * 1ll * k % (n - 1)), n) * 1ll * a % n;
		auto it = lower_bound(dec.begin(), dec.end(), make_pair(my, 0));
		if (it != dec.end() && it->first == my) {any_ans = it->second * sq - i; break;}
	}
	if (any_ans == -1) return -1;
	int delta = (n-1) / __gcd(k, n-1);
	return powmod(g, any_ans % delta, n);
}

int k, n, m; vector<int> b;
const int mod = 998244353;

void Input() {
	cin >> k; b.resize(k);
	for (auto &z: b) cin >> z;
	cin >> n >> m;
}

void Solve() {
	vector<int> series(k, 0); series[k-1] = 1;
	int expo = linearRec(series, b, n-1, mod-1);
	cout << discrete_root(mod, expo, m) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/
