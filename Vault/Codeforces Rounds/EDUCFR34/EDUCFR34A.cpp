/**
	Template by proptit_4t41
	Applied for C++11/C++14
	Add -std=c++14 to your IDE.
**/

/**
	To make it compatible to C++98,
	remove all tuple typedefs, unordered
	sets/maps/multisets/multimaps, and add
	a space between two '<'/'>'s when declaring
	multi-dimensional vectors (to avoid ambiguity).
**/

#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define endl '\n'
#define i64 long long
#define u64 unsigned long long
#define ld long double
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mmap multimap
#define mset multiset
#define umap unordered_map
#define uset unordered_set
#define ummap unordered_multimap
#define umset unordered_multiset
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define REcheck cout << "RE here?\n"
#define tracker1(i) cout << "working at " << i << endl;
#define tracker2(i,j) cout << "working at " << i << "-" << j << endl;
#define tracker3(i,j,k) cout << "working at " << i << "-" << j << "-" << k << endl;
const long double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
const long long MOD = 1000000007LL;
const long long INF = 1e9;
const long long LINF = 1e18;
const long double EPS = 1e-9;
const long double GOLD = ((1+sqrt(5))/2);
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----MATRICES----- **/
struct matrix {
	vector<vector<i64>> A;

	matrix() {}

	matrix(i64 n, i64 m) {
		A.resize(n, vector<i64>(m, 0));
	}

	matrix(i64 n, i64 m, vector<i64> input) {
		A.resize(n, vector<i64>(m, 0));
		for (i64 i=0; i<input.size(); i++) {
			A[i/m][i%m] = input[i];
		}
	}

	matrix(i64 n, i64 m, vector<vector<i64>> input) {
		A.resize(n, vector<i64>(m, 0));
		for (i64 i=0; i<input.size(); i++) {
			if (i >= n) break;
			for (i64 j=0; j<input[0].size(); j++) {
				if (j >= m) break;
				A[i][j] = input[i][j];
			}
		}
	}

	matrix(vector<vector<i64>> input) {
		for (i64 i=0; i<input.size(); i++) {
			vector<i64> tmp;
			for (i64 j=0; j<input[0].size(); j++) {
				tmp.pub(input[i][j]);
			}
			A.pub(tmp);
		}
	}

	matrix operator* (matrix b) {
		if (this->A[0].size() != b.A.size()) return matrix(0, 0);
		i64 n = this->A.size(), m = b.A[0].size();
		matrix result(n, m);
		for (i64 i=0; i<n; i++) {
			for (i64 j=0; j<m; j++) {
				result.A[i][j] = 0;
				for (i64 k=0; k<b.A.size(); k++) result.A[i][j] += this->A[i][k] * b.A[k][j];
			}
		}
		return result;
	}

	ostream& operator<< (ostream& os) {
		for (i64 i=0; i<this->A.size(); i++) {
			for (i64 j=0; j<this->A[0].size(); j++) {
				os << this->A[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}
};

matrix unitmat(matrix z) {
	matrix res = matrix(z.A.size(), z.A[0].size());
	for (i64 i=0; i<z.A.size(); i++) {
		res.A[i][i] = 1;
	}
	return res;
}

matrix modMul(matrix a, matrix b) {
	if (a.A[0].size() != b.A.size()) return matrix(0, 0);
	i64 n = a.A.size(), m = b.A[0].size();
	matrix result(n, m);
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			result.A[i][j] = 0;
			for (i64 k=0; k<b.A.size(); k++) {
				result.A[i][j] += (a.A[i][k] * b.A[k][j]) % MOD;
				result.A[i][j] %= MOD;
			}
		}
	}
	return result;
}

matrix matPow(matrix a, i64 b) {
	if (b == 0) return unitmat(a);
	if (b == 1) return a;
	matrix tmp = matPow(a, b/2);
	if (b % 2 == 0) return modMul(tmp, tmp);
	return modMul(modMul(tmp, tmp), a);
}

/** -----MATH/STRING FUNCTIONS----- **/
i64 modPow(i64 a, i64 b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	i64 tmp = modPow(a, b/2);
	if (b % 2 == 0) return ((tmp * tmp) % MOD);
	return ((((tmp * tmp) % MOD) * a) % MOD);
}

i64 divPow(i64 a, i64 b) {
	return ((a * modPow(b, MOD-2)) % MOD);
}

i64 Str2I64(string z) {
	bool negative = false;
	if (z[0] == '-') {
		negative = true; z.erase(0, 1);
	}
	i64 res = 0;
	for (i64 i=0; i<z.size(); i++) res = res * 10 + (z[i] - '0');
	if (negative) return -res;
	return res;
}

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/// MAIN SOLUTION STARTS HERE

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
int T, cas = 0; // for multi-testcase problems


/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> T; // for multi-testcase problems

}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	i64 N; cin >> N;
	for (i64 i=0; 7*i<=N; i++) {
		if ((N - 7*i) % 3 == 0) {
			cout << "YES\n"; return;
		}
	}
	cout << "NO\n";
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	while(T--) ProSolve(); // for multi-testcase problems
	//ProSolve(); // for regular problems
	return 0;
}
