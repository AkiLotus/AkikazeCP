#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FO(i,a,b) for(int i=(a);i<(b);i++)
#define FOD(i,a,b) for(int i=(a);i>(b);i--)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORV(i,a) for(typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

typedef pair<int,int>ii;
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}

typedef pair<ll,ll> pll;

string s;

int cal1() {
	vector <int> d(s.length(), 0);
	int l = 0, r = -1;
	int res = 0;
	FOR(i, 0, s.length() - 1) {
		int k = 0;
		if (i <= r) k = min(r - i, d[r - i + l]);
		while (i + k + 1 < s.length() && i - k - 1 >= 0 && s[i + k + 1] == s[i - k - 1]) k++;
		d[i] = k;
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
		res += d[i];
	}
	return res;
}


int cal2() {
	vector <int> d(s.length(), 0);
	int l = 0, r = -1;
	int res = 0;
	FOR(i, 0, s.length() - 1) {
		int k = 0;
		if (i <= r) k = min(r - i + 1, d[r - i + l + 1]);
		while (i + k + 1 < s.length() && i - k - 1 >= 0 && s[i + k] == s[i - k - 1]) k++;
		d[i] = k;
		if (i + k - 1 > r) {
			l = i - k;
			r = i + k - 1;
		}
		res += d[i];
	}
	return res;
}

int main() {
	cin >> s;
	int res = cal1() + cal2() + s.length();
	cout << res << endl;
}
