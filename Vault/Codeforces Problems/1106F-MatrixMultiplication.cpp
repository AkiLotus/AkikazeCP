#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int linearRec(vector<int> S, vector<int> tr, int k, int Mod) {
	#define Matrix vector<vector<int>>
	function<Matrix(Matrix, Matrix)> MatMul = [&](Matrix a, Matrix b) -> Matrix {
		int n = a.size(), k = a[0].size(), m = b[0].size();
		Matrix res(n, vector<int>(m, 0));
		for (int z=0; z<k; z++) {
			for (int i=0; i<n; i++) {
				for (int j=0; j<m; j++) {
					res[i][j] += (1LL * a[i][z] * b[z][j]) % Mod;
					res[i][j] %= Mod;
				}
			}
		}
		return res;
	};
	
	function<Matrix(int)> UnitMatrix = [&](int n) -> Matrix {
		Matrix res(n, vector<int>(n, 0));
		for (int i=0; i<n; i++) res[i][i] = 1;
		return res;
	};
	
	function<Matrix(Matrix, int)> MatPow = [&](Matrix a, int b) -> Matrix {
		// a is guaranteed to be a square matrix
		Matrix res = UnitMatrix(a.size());
		while (b > 0) {
			if (b % 2 == 1) {res = MatMul(res, a); b--;}
			else {a = MatMul(a, a); b /= 2;}
		}
		return res;
	};
	
	int n = S.size();

	Matrix TransformationMatrix(n, vector<int>(n, 0));
	for (int i=1; i<n; i++) TransformationMatrix[i-1][i] = 1;
	for (int i=0; i<n; i++) TransformationMatrix[n-1][i] = tr[n-1-i];

	Matrix BaseMatrix(n, vector<int>(1, 0));
	for (int i=0; i<n; i++) BaseMatrix[i][0] = S[i];
	
	Matrix PostTransform = MatMul(MatPow(TransformationMatrix, k), BaseMatrix);
	#undef Matrix
	return PostTransform[0][0];
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
