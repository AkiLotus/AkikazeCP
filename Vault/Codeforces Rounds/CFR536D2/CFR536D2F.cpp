#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;

long long linearRec(vector<long long> S, vector<long long> tr, long long k) {
	long long n = S.size();

	auto combine = [&](vector<long long> a, vector<long long> b) {
		vector<long long> res(n * 2 + 1);
		for (long long i=0; i<n+1; i++) for (long long j=0; j<n+1; j++)
			res[i + j] = (res[i + j] + a[i] * b[j]) % (mod-1);
		for (long long i = 2 * n; i > n; --i) for (long long j=0; j<n; j++)
			res[i - 1 - j] = (res[i - 1 - j] + res[i] * tr[j]) % (mod-1);
		res.resize(n + 1);
		return res;
	};

	vector<long long> pol(n + 1), e(pol);
	pol[0] = e[1] = 1;

	for (++k; k; k /= 2) {
		if (k % 2) pol = combine(pol, e);
		e = combine(e, e);
	}

	long long res = 0;
	for (long long i=0; i<n; i++) res = (res + pol[i + 1] * S[i]) % mod;
	return res;
}

long long k, n, m; vector<long long> b;

int gcd (int a, int b) {
    return a ? gcd (b%a, a) : b;
}

int powmod (int a, int b, int p) {
    int res = 1;
    while (b)
        if (b & 1)
            res = int (res * 1ll * a % p),  --b;
        else
            a = int (a * 1ll * a % p),  b >>= 1;
    return res;
}

int generator (int p) {
    vector<int> fact;
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}

int discrete_root(int n, int k, int a) {
	if (a == 0) return 0;
	int g = generator (n);
    int sq = (int) sqrt (n + .0) + 1;
    vector < pair<int,int> > dec (sq);
    for (int i=1; i<=sq; ++i)
		dec[i-1] = make_pair (powmod (g, int (i * sq * 1ll * k % (n - 1)), n), i);
    sort (dec.begin(), dec.end());
    int any_ans = -1;
    for (int i=0; i<sq; ++i) {
        int my = int (powmod (g, int (i * 1ll * k % (n - 1)), n) * 1ll * a % n);
        vector < pair<int,int> >::iterator it =
            lower_bound (dec.begin(), dec.end(), make_pair (my, 0));
        if (it != dec.end() && it->first == my) {
            any_ans = it->second * sq - i;
            break;
        }
    }
    if (any_ans == -1) return -1;
    int delta = (n-1) / gcd (k, n-1);
    vector<int> ans;
    for (int cur=any_ans%delta; cur<n-1; cur+=delta)
        return powmod (g, cur, n);
}

void Input() {
	cin >> k; b.resize(k);
	for (auto &z: b) cin >> z;
	cin >> n >> m;
}

void Solve() {
	vector<long long> series(k, 0); series[k-1] = 1;
	long long expo = linearRec(series, b, n-1) % (mod - 1);
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
