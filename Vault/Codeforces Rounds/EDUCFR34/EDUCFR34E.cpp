/**
	Template by proptit_4t41
	Applied for C++11/C++14
	Add -std=c++14 to your IDE.
**/

/**
	// code written by a random fan of momocashew
	// world.execute(me);
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

string toStr(i64 z) {
	if (z == 0) return "0";
	bool negative = false;
	if (z < 0) negative = true;
	string res = "";
	while (z > 0) {
		i64 tmp = z % 10; z /= 10;
		res.insert(0, 1, char(48+tmp));
	}
	if (negative) res.insert(0, 1, '-');
	return res;
}

/** -----BIGINTS----- **/
struct bigint {
	string digit;
	bool negative = false;

	bigint() {}
	bigint(string vs, bool sign) {
		digit = vs; negative = sign;
	}
	bigint(i64 input) {
		digit = toStr(abs(input)); negative = (input < 0);
	}
	bigint(int input) {
		digit = toStr(abs(input)); negative = (input < 0);
	}

	bool operator<(bigint p2) {
		if (this->negative && !p2.negative) return true;
		if (this->negative && !p2.negative) return false;
		string s1 = this->digit, s2 = p2.digit;
		i64 len = max(s1.size(), s2.size());
		s1.insert(0, len-s1.size(), '0');
		s2.insert(0, len-s2.size(), '0');
		if (this->negative) return(s1 > s2);
		return (s1 < s2);
	}

	bool operator>(bigint p2) {
		if (this->negative && !p2.negative) return false;
		if (this->negative && !p2.negative) return true;
		string s1 = this->digit, s2 = p2.digit;
		i64 len = max(s1.size(), s2.size());
		s1.insert(0, len-s1.size(), '0');
		s2.insert(0, len-s2.size(), '0');
		if (this->negative) return(s1 < s2);
		return (s1 > s2);
	}

	bool operator==(bigint p2) {
		if (this->negative && !p2.negative) return false;
		if (this->negative && !p2.negative) return false;
		string s1 = this->digit, s2 = p2.digit;
		return (s1 == s2);
	}

	bool operator!=(bigint p2) {
		return (!(*this == p2));
	}

	bool operator<=(bigint p2) {
		return (*this < p2 || *this == p2);
	}

	bool operator>=(bigint p2) {
		return (*this > p2 || *this == p2);
	}

	bigint& operator=(bigint input) {
		this->digit = input.digit;
		this->negative = input.negative;
	}

	bigint operator+(bigint p2) {
		string s1 = this->digit, s2 = p2.digit;
		bool n1 = this->negative, n2 = p2.negative;
		i64 len = max(s1.size(), s2.size()) + 2;
		s1.insert(0, len-s1.size(), '0');
		s2.insert(0, len-s2.size(), '0');
		i64 carry = 0;
		string ans = ""; ans.insert(0, len, '0');
		if (n1 == n2) {
			for (i64 i=len-1; i>0; i--) {
				i64 tmp = (s1[i] - '0') + (s2[i] - '0') + carry;
				carry = tmp / 10; ans[i] = char(48+tmp%10);
			}
			while (ans.size() > 1 && ans[0] == '0') ans.erase(0, 1);
			return bigint(ans, n1);
		}
		bool anssign = false;
		if ((s2 > s1 && n2) || (s1 > s2 && n1)) anssign = true;
		if (s2 > s1) {
			string tmp = s1; s1 = s2; s2 = tmp;
		}
		for (i64 i=len-1; i>0; i--) {
			i64 tmp = (s1[i] - '0') - (s2[i] - '0') + carry;
			carry = 0;
			while (tmp < 0) {
				tmp += 10; carry--;
			}
			ans[i] = char(48+tmp);
		}
		while (ans.size() > 1 && ans[0] == '0') ans.erase(0, 1);
		return bigint(ans, anssign);
	}

	bigint& operator+=(bigint p2) {
		*this = *this + p2;
		return *this;
	}

	bigint operator-(bigint p2) {
		bigint tmp = bigint(p2.digit, !p2.negative);
		return (*this + tmp);
	}

	bigint& operator-=(bigint p2) {
		*this = *this - p2;
		return *this;
	}

	bigint operator*(bigint p2) {
		bigint ans = bigint(0);
		if ((this->negative && !p2.negative) || (!this->negative && p2.negative)) ans.negative = true;
		string working = this->digit;
		for (i64 i=p2.digit.size()-1; i>=0; i--) {
			if (i != p2.digit.size()-1) working.insert(working.size(), 1, '0');
			string tmp = working; tmp.insert(0, 2, '0');
			i64 mul = p2.digit[i] - '0', carry = 0;
			for (i64 j=tmp.size()-1; j>0; j--) {
				i64 tmptmp = (tmp[j] - '0') * mul + carry;
				tmp[j] = ('0' + tmptmp % 10); carry = tmptmp / 10;
			}
			while (tmp.size() > 1 && tmp[0] == '0') tmp.erase(0, 1);
			ans += bigint(tmp, ans.negative);
		}
		return ans;
	}

	bigint& operator*=(bigint p2) {
		*this = *this * p2;
		return *this;
	}

	bigint pow(bigint z, i64 p2) {
		if (p2 == 0) return bigint(0);
		if (p2 == 1) return z;
		bigint tmp = pow(z, p2/2);
		if (p2 % 2 == 0) return (tmp * tmp);
		return (tmp * tmp * z);
	}
};

ostream& operator<< (ostream& oss, bigint z) {
	if (z.digit == "0") z.negative = false;
	if (z.negative) oss << "-";
	for (i64 i=0; i<z.digit.size(); i++) oss << z.digit[i];
	return oss;
}

bigint biParse(i64 input) {
	string vs = ""; bool sign = false;
	if (input < 0) {
		sign = true; input = -input;
	}
	if (input == 0) vs = "0";
	while (input > 0) {
		i64 tmp = input % 10; input /= 10;
		vs.insert(0, 1, char(48+tmp));
	}
	return bigint(vs, sign);
}

bigint biParse(string input) {
	string vs = input; bool sign = false;
	if (vs[0] == '-') {
		sign = true; vs.erase(0, 1);
	}
	return bigint(vs, sign);
}

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/// MAIN SOLUTION STARTS HERE

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
//int T, cas = 0; // for multi-testcase problems
i64 k, n; vector<string> str;
map<string, i64> M;
vector<string> possible;
vector<i64> HammingDistance;
vector<i64> cc(26, 0);
bool invalid = false;
bool replicated = false;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> k >> n; str.resize(k);
	HammingDistance.resize(k, 0);
	for (i64 i=0; i<k; i++) {
		cin >> str[i];
		if (invalid) continue;
		if (i == 0) {
			for (i64 j=0; j<n; j++) {
				cc[str[i][j]-'a']++;
				if (cc[str[i][j]-'a'] > 1) replicated = true;
			}
		}
		else {
			vector<i64> tmpCC(26, 0);
			for (i64 j=0; j<n; j++) tmpCC[str[i][j]-'a']++;
			if (tmpCC != cc) invalid = true;
		}
	}
	for (i64 i=1; i<k; i++) {
		for (i64 j=0; j<n; j++) {
			if (str[0][j] != str[i][j]) HammingDistance[i]++;
		}
	}
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	if (k == 1) {
		char tmp = str[0][0]; str[0][0] = str[0][1]; str[0][1] = tmp;
		cout << str[0]; return;
	}
	if (invalid) {
		cout << "-1"; return;
	}
	for (i64 i=0; i<n; i++) {
		for (i64 j=i+1; j<n; j++) {
			bool allValid = true;
			for (i64 x=1; x<k; x++) {
				i64 testing = HammingDistance[x];
				//cout << "Initial HD = " << testing << endl;
				if (str[0][i] != str[x][i] && str[0][j] == str[x][i]) testing--;
				else if (str[0][i] == str[x][i] && str[0][j] != str[x][i]) testing++;
				if (str[0][j] != str[x][j] && str[0][i] == str[x][j]) testing--;
				else if (str[0][j] == str[x][j] && str[0][i] != str[x][j]) testing++;
				//cout << "Testing = " << testing << endl;
				if (testing == 2 || (testing == 0 && replicated)) continue;
				else {allValid = false; break;}
			}
			if (allValid) {
				string tmp = str[0]; char tmptmp = tmp[i];
				tmp[i] = tmp[j]; tmp[j] = tmptmp;
				cout << tmp; return;
			}
		}
	}
	cout << "-1";
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
