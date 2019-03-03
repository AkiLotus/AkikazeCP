/******************************************************
 *     Code written by JadeMasochist                  *
 *     Ngoc-Mai Ngo, #Team4T's Deputy Leader          *
 *     #Team4T Secondary Flagship - Destruction       *
 ******************************************************/

/************** [OPTIMIZATION PROTOCOL] **************/
/**/ #pragma comment(linker, "/stack:252457298")
/**/ #pragma GCC optimize("Ofast")
/**/ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
/*****************************************************/

/************** [LIBRARY PROTOCOL] **************/
/**/ #include <bits/stdc++.h>
/**/ using namespace std;
/************************************************/

/************** [LEGENDS/CONSTANTS] **************/
/**/ #define endl '\n'
/**/ #define i64 long long
/**/ #define pb push_back
/**/ #define mp make_pair
/**/ #define fi first
/**/ #define se second
/**/ const long long Mod = 998244353LL, Inf = 1e18;
/**/ const long double Pi = 3.141592653589793116, Eps = 1e-9, Gold = ((1+sqrt(5))/2);
/*************************************************/

/************** [BITWISE FUNCTIONS] **************/
/**/ template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
/**/ template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
/**/ template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
/**/ template<class T> int cntbit(T s) { return __builtin_popcount(s); }
/*************************************************/

/************** [GLOBAL VARIABLES] **************/
/**/ auto TimeStart = chrono::steady_clock::now();
/**/ auto TimeEnd = chrono::steady_clock::now();
i64 n; vector<i64> a, ftrl(1007, 1);
/************************************************/

/************** [FUNCTIONS] **************/
/**/ void ChangeIO();
/**/ void TimerStart();
/**/ void TimerStop();
/**/ void Exit();
i64 modPow(i64 a, i64 b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	i64 tmp = modPow(a, b/2);
	if (b % 2 == 0) return ((tmp * tmp) % Mod);
	return ((((tmp * tmp) % Mod) * a) % Mod);
}

i64 nCr(i64 n, i64 r) {
	i64 numer = ftrl[n];
	i64 denom = (ftrl[n-r] * ftrl[r]) % Mod;
	return ((numer * modPow(denom, Mod-2)) % Mod);
}

i64 calc(i64 siz, i64 rem) {
	if (siz <= 0 || rem < siz) return 0;
	return nCr(rem, siz);
}
/**/ void Input();
/**/ void Solve();
/*****************************************/

/************** [MAIN] **************/
/**/ int main() {
/**/ 	ChangeIO();
/**/ 	ios_base::sync_with_stdio(0);
/**/ 	cin.tie(NULL); cout.tie(NULL);
/**/ 	Input(); TimerStart();
/**/ 	Solve(); TimerStop();
/**/ 	return 0;
/**/ }
/************************************/

void ChangeIO() {
	#ifdef Jade
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	#endif
}

void TimerStart() {
	#ifdef Jade
	TimeStart = chrono::steady_clock::now();
	#endif
}

void TimerStop() {
	#ifdef Jade
	TimeEnd = chrono::steady_clock::now();
	auto ElapsedTime = TimeEnd - TimeStart;
	cout << "\n\nTime elapsed: " << chrono::duration<double>(ElapsedTime).count() << " seconds.\n";
	#endif
}

void Exit() {
	TimerStop(); exit(0);
}

void Input() {
	cin >> n; a.resize(n);
	for (i64 i=1; i<1007; i++) ftrl[i] = (ftrl[i-1] * i) % Mod;
	for (i64 i=0; i<n; i++) cin >> a[i];
}

void Solve() {
	i64 ans = 0; vector<i64> dp(n);
	for (i64 i=n-1; i>=0; i--) {
		dp[i] += calc(a[i], n-1-i);
		if (a[i] > 0) {for (i64 j=i+a[i]+1; j<n; j++) {dp[i] += (nCr(j-i-1, a[i]) * dp[j]) % Mod;; dp[i] %= Mod;}}
		ans += dp[i]; ans %= Mod;
		//cout << "ans = " << ans << endl;
	}
	cout << ans;
}