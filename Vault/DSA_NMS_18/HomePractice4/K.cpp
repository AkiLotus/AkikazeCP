/**
	Template by Akikaze (秋風) - formerly proptit_4t41.
	Code written by a random fan of momocashew and Chiho.
	
	H△G x Mili - November 27th, 2013
	Mag Mell (Mili) - Sep 17th, 2014
	H△G x Mili Vol.2 - May 9th, 2015
	Miracle Milk (Mili) - Oct 12th, 2016
	青色フィルム (H△G) - February 14th, 2018
	Millennium Mother (Mili) - April 25th, 2018
**/

/** -----PRAGMA----- **/
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define endl '\n'
#define i64 long long
#define ld long double
#define pub push_back
#define mp make_pair
#define fi first
#define se second
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/


/** -----GLOBAL VARIABLES----- **/
i64 T, N; vi a;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> T;
}

void ProSolve() {
	while (T--) {
		cin >> N; vi a(N); for (i64 i=0; i<N; i++) cin >> a[i];
		vi ans, ans2, ans3, mod1, mod2;
		for (i64 i=0; i<N; i++) {
			if (a[i] % 3 == 0) {ans.pub(a[i]); ans2.pub(a[i]); ans3.pub(a[i]);}
			else if (a[i] % 3 == 2) mod2.pub(a[i]);
			else mod1.pub(a[i]);
		}
		sort(mod1.begin(), mod1.end(), greater<i64>());
		sort(mod2.begin(), mod2.end(), greater<i64>());
		i64 ptr1 = 0, ptr2 = 0;
		while (ptr1 < mod1.size() && ptr2 < mod2.size() && ptr1 < 1 && ptr2 < 1) {
			ans.pub(mod1[ptr1]); ans.pub(mod2[ptr2]);
			ptr1++; ptr2++;
		}
		for (i64 i=ptr1+2; i<mod1.size(); i+=3) {
			ans.pub(mod1[i-2]); ans.pub(mod1[i-1]); ans.pub(mod1[i]);
		}
		for (i64 i=ptr2+2; i<mod2.size(); i+=3) {
			ans.pub(mod2[i-2]); ans.pub(mod2[i-1]); ans.pub(mod2[i]);
		}
		ptr1 = 0; ptr2 = 0;
		while (ptr1 < mod1.size() && ptr2 < mod2.size() && ptr1 < 2 && ptr2 < 2) {
			ans2.pub(mod1[ptr1]); ans2.pub(mod2[ptr2]);
			ptr1++; ptr2++;
		}
		for (i64 i=ptr1+2; i<mod1.size(); i+=3) {
			ans2.pub(mod1[i-2]); ans2.pub(mod1[i-1]); ans2.pub(mod1[i]);
		}
		for (i64 i=ptr2+2; i<mod2.size(); i+=3) {
			ans2.pub(mod2[i-2]); ans2.pub(mod2[i-1]); ans2.pub(mod2[i]);
		}
		ptr1 = 0; ptr2 = 0;
		while (ptr1 < mod1.size() && ptr2 < mod2.size() && ptr1 < 0 && ptr2 < 0) {
			ans3.pub(mod1[ptr1]); ans3.pub(mod2[ptr2]);
			ptr1++; ptr2++;
		}
		for (i64 i=ptr1+2; i<mod1.size(); i+=3) {
			ans3.pub(mod1[i-2]); ans3.pub(mod1[i-1]); ans3.pub(mod1[i]);
		}
		for (i64 i=ptr2+2; i<mod2.size(); i+=3) {
			ans3.pub(mod2[i-2]); ans3.pub(mod2[i-1]); ans3.pub(mod2[i]);
		}
		//cout << ans << ans2 << ans3 << endl;
		sort(ans.begin(), ans.end(), greater<i64>());
		sort(ans2.begin(), ans2.end(), greater<i64>());
		sort(ans3.begin(), ans3.end(), greater<i64>());
		if (ans.empty() && ans2.empty() && ans3.empty()) {cout << "-1\n"; continue;}
		vi max = ans;
		if (ans2.size() > max.size() || (ans2.size() == max.size() && ans2 > max)) max = ans2;
		if (ans3.size() > max.size() || (ans3.size() == max.size() && ans3 > max)) max = ans3;
		for (i64 i=0; i<max.size(); i++) cout << max[i]; cout << endl;
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
			#ifdef Akikaze
			//freopen("FILE.INP", "r", stdin);
			//freopen("FILE.OUT", "w", stdout);
			#endif
	VarInput();
			#ifdef Akikaze
			auto TIME1 = chrono::steady_clock::now();
			#endif
	ProSolve();
			#ifdef Akikaze
			auto TIME2 = chrono::steady_clock::now();
			auto DIFF = TIME2 - TIME1;
			cout << "\n\nTime elapsed: " << fixed << setprecision(18) << chrono::duration<double>(DIFF).count() << " seconds.";
			#endif
	return 0;
}