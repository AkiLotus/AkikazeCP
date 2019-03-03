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
/**/ const long long Mod = 1000000007LL, Inf = 1e18;
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
i64 n; vector<string> a, b; map<string, i64> Map1, Map2;
/************************************************/

/************** [FUNCTIONS] **************/
/**/ void ChangeIO();
/**/ void TimerStart();
/**/ void TimerStop();
/**/ void Exit();

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
	cin >> n; a.resize(n); b = a;
	for (i64 i=0; i<n; i++) {cin >> a[i]; Map1[a[i]]++;}
	for (i64 i=0; i<n; i++) {cin >> b[i]; Map2[b[i]]++;}
}

void Solve() {
	i64 ans = (abs(Map2["M"]-Map1["M"]) + abs(Map2["S"]-Map1["S"]) + abs(Map2["L"] - Map1["L"])) / 2;
	for (i64 i=1; i<4; i++) {
		string sl = "L", ss = "S";
		for (i64 j=0; j<i; j++) {sl.insert(0, 1, 'X'); ss.insert(0, 1, 'X');}
		i64 cnt1l = Map1[sl], cnt1s = Map1[ss];
		i64 cnt2l = Map2[sl], cnt2s = Map2[ss];
		ans += (min(abs(cnt1l-cnt2l), abs(cnt1s-cnt2s)));
	}
	cout << ans;
}