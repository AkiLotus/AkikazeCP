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
	
}

void Solve() {
	
}