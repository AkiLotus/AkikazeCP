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

i64 n, l, r, k;

i64 binary_search(i64 top, i64 bot) {
	if (bot > top) return -1;
	i64 mid = (top + bot) / 2;
	i64 cycleConsumption = n + mid;
}

void Input() {
	cin >> n >> l >> r >> k;
}

void Solve() {
	cout << binary_search(0LL, n);
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	
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