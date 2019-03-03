// Code written by JadeMasochist

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define MOD 1000000007
using namespace std;

string toStr(ll z) {
	if (z == 0) return "0";
	bool negative = false;
	if (z < 0) negative = true;
	string res = "";
	while (z > 0) {
		ll tmp = z % 10; z /= 10;
		res.insert(0, 1, char(48+tmp));
	}
	if (negative) res.insert(0, 1, '-');
	while (res.size() > 1 && res[0] == '0') res.erase(0, 1);
	return res;
}

struct bigint {
	string digit = "";
	bool negative = false;

	bigint() {}
	bigint(string vs, bool sign) {
		digit = vs; negative = sign;
	}
	bigint(ll inputs) {
		digit = toStr(abs(inputs)); negative = (inputs < 0);
	}
	bigint(int inputs) {
		digit = toStr(abs(inputs)); negative = (inputs < 0);
	}

	bool operator<(bigint p2) {
		if (this->negative && !p2.negative) return true;
		if (this->negative && !p2.negative) return false;
		string s1 = this->digit, s2 = p2.digit;
		ll len = max(s1.size(), s2.size());
		s1.insert(0, len-s1.size(), '0');
		s2.insert(0, len-s2.size(), '0');
		if (this->negative) return(s1 > s2);
		return (s1 < s2);
	}

	bool operator>(bigint p2) {
		if (this->negative && !p2.negative) return false;
		if (this->negative && !p2.negative) return true;
		string s1 = this->digit, s2 = p2.digit;
		ll len = max(s1.size(), s2.size());
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

	bigint biabs(bigint z) {
		z.negative = false;
		return z;
	}

	bigint& operator=(bigint input) {
		this->digit = input.digit;
		this->negative = input.negative;
	}

	bigint operator+(bigint p2) {
		string s1 = this->digit, s2 = p2.digit;
		bool n1 = this->negative, n2 = p2.negative;
		ll len = max(s1.size(), s2.size()) + 2;
		s1.insert(0, len-s1.size(), '0');
		s2.insert(0, len-s2.size(), '0');
		ll carry = 0;
		string ans = ""; ans.insert(0, len, '0');
		if (n1 == n2) {
			for (ll i=len-1; i>0; i--) {
				ll tmp = (s1[i] - '0') + (s2[i] - '0') + carry;
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
		for (ll i=len-1; i>0; i--) {
			ll tmp = (s1[i] - '0') - (s2[i] - '0') + carry;
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
		for (ll i=p2.digit.size()-1; i>=0; i--) {
			if (i != p2.digit.size()-1) working.insert(working.size(), 1, '0');
			string tmp = working; tmp.insert(0, 2, '0');
			ll mul = p2.digit[i] - '0', carry = 0;
			for (ll j=tmp.size()-1; j>0; j--) {
				ll tmptmp = (tmp[j] - '0') * mul + carry;
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

	bigint pow(bigint z, ll p2) {
		if (p2 == 0) return bigint(0);
		if (p2 == 1) return z;
		bigint tmp = pow(z, p2/2);
		if (p2 % 2 == 0) return (tmp * tmp);
		return (tmp * tmp * z);
	}

	bigint operator/(bigint p2) {
		if (biabs(*this) < biabs(p2)) return bigint(0);
		if (biabs(*this) == biabs(p2)) {
			if (*this == p2) return bigint(1);
			else return bigint(-1);
		}
		bool negative = false;
		if ((this->negative && !p2.negative) || (!this->negative && p2.negative)) negative = true;
		if (this->negative) cout << "Negative1!\n";
		if (p2.negative) cout << "Negative2!\n";
		string working = this->digit;
		string divisor = p2.digit;
		string vs = "";
		string strtmp = working.substr(0, divisor.size());
		ll pointer = divisor.size() - 1;
		if (strtmp < divisor) {
			pointer++; strtmp += working[pointer];
		}
		bigint tmp1 = bigint(strtmp, false);
		bigint tmp2 = biabs(p2);
		while (pointer < working.size()) {
			for (ll i=9; i>=0; i--) {
				if (tmp2 * bigint(i) <= tmp1) {
					vs += char(48+i);
					tmp1 -= tmp2 * bigint(i);
					break;
				}
			}
			pointer++;
			if (pointer < working.size()) {
				tmp1 *= bigint(10);
				tmp1 += bigint(working[pointer]-'0');
			}
		}
		return bigint(vs, negative);
	}

	bigint& operator/=(bigint p2) {
		*this = *this / p2;
		return *this;
	}

	bigint operator%(bigint p2) {
		if (biabs(*this) < biabs(p2)) return bigint(0);
		if (biabs(*this) == biabs(p2)) {
			if (*this == p2) return bigint(1);
			else return bigint(-1);
		}
		bool negative = false;
		if ((this->negative && !p2.negative) || (!this->negative && p2.negative)) negative = true;
		if (this->negative) cout << "Negative1!\n";
		if (p2.negative) cout << "Negative2!\n";
		string working = this->digit;
		string divisor = p2.digit;
		string strtmp = working.substr(0, divisor.size());
		ll pointer = divisor.size() - 1;
		if (strtmp < divisor) {
			pointer++; strtmp += working[pointer];
		}
		bigint tmp1 = bigint(strtmp, false);
		bigint tmp2 = biabs(p2);
		while (pointer < working.size()) {
			for (ll i=9; i>=0; i--) {
				if (tmp2 * bigint(i) <= tmp1) {
					tmp1 -= tmp2 * bigint(i);
					break;
				}
			}
			pointer++;
			if (pointer < working.size()) {
				tmp1 *= bigint(10);
				tmp1 += bigint(working[pointer]-'0');
			}
		}
		tmp1.negative = negative; return tmp1;
	}

	bigint& operator%=(bigint p2) {
		*this = *this % p2;
		return *this;
	}


	bigint operator++() {
		*this += bigint(1);
		return *this;
	}

	bigint operator--() {
		*this -= bigint(1);
		return *this;
	}

	const bigint operator++(int) {
		bigint temp = *this;
		++(*this);
		return bigint(temp);
	}

	const bigint operator--(int) {
		bigint temp = *this;
		--(*this);
		return bigint(temp);
	}

	bigint operator+() {
		return *this;
	}

	bigint operator-() {
		bigint tmp = *this;
		tmp.negative = !(tmp.negative);
		return tmp;
	}
};

ostream& operator<< (ostream& oss, bigint z) {
	if (z.digit == "0") z.negative = false;
	if (z.negative) oss << "-";
	for (ll i=0; i<z.digit.size(); i++) oss << z.digit[i];
	return oss;
}

bigint biParse(ll input) {
	string vs = ""; bool sign = false;
	if (input < 0) {
		sign = true; input = -input;
	}
	if (input == 0) vs = "0";
	while (input > 0) {
		ll tmp = input % 10; input /= 10;
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

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
//	ios_base::sync_with_stdio(0); cin.tie(NULL);
	ll t1, t2, t3, t4; cin >> t1 >> t2 >> t3 >> t4;
	bigint n = biParse(t1), k = biParse(t2), M = biParse(t3), D = biParse(t4);
	bigint ans = 0;
	for (bigint i=1LL; i<=D; i++) {
		bigint x = M;
		bigint z = n / ((i - 1) * k + 1);
		bigint Diff = z - x;
		if (Diff.negative) x = z;
		if (x == 0) continue;
		if ((n / x + k - 1) / k != i) continue;
		bigint tmp = i * x, diff = ans - tmp;
		if (diff.negative) ans = tmp;
	}
	cout << ans;
	return 0;
}