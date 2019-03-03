#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define i64 long long
#define ld long double
#define rsz resize
#define pub push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);

template<class T> int cntbit(T s) { return __builtin_popcountll(s); }

void Exit();

#define MultiTest 227420978
#undef MultiTest // Switch this off if submitting multi-test problems.

i64 n; vb Shiro; vector<pii> a;

bool monochromic() {
	for (i64 i=1; i<n; i++) {
		if (Shiro[i] != Shiro[0]) return false;
	}
	return true;
}

void Input() {
	cin >> n;
	Shiro.rsz(n, false); a.rsz(n);
	a[0] = mp(1LL, 0LL);
}

void Solve() {
	if (n == 1) {
		cout << "0 0\n"; fflush(stdout);
		string s; cin >> s;
		cout << "1 0 0 1\n"; fflush(stdout); return;
	}
	if (n == 2) {
		cout << "0 0\n"; fflush(stdout);
		string s1; cin >> s1;
		cout << "0 2\n"; fflush(stdout);
		string s2; cin >> s2;
		if (s1 == s2) cout << "4 0 0 4\n"; else cout << "0 1 4 1\n";
		fflush(stdout); return;
	}
	cout << "1 0\n"; fflush(stdout);
	string s; cin >> s; Shiro[0] = (s == "white");
	i64 Rightest = 0, Leftest = INF;
	i64 L = 0, R = 536870912LL;
	for (i64 i=1; i<n; i++) {
		cout << "1 " << (L + R) / 2 << endl;
		fflush(stdout); a[i] = mp(1LL, (L+R)/2);
		cin >> s; Shiro[i] = (s == "white");
		if (Shiro[i] == Shiro[0]) {L = a[i].se;}
		else {R = a[i].se;}
	}
	if (monochromic()) {cout << "4 0 4 4\n"; fflush(stdout); return;}
	cout << "2 " << L << " 0 " << R << endl; fflush(stdout);
}

int main(int argc, char* argv[]) {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	
	#ifndef MultiTest
		Input();
		Solve();
	#else
		int T; cin >> T;
		while(T--) {Input(); Solve();}
	#endif

	return 0;
}

void Exit() {
	exit(0);
}