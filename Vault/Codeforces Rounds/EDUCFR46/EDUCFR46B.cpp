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
i64 n, M; vector<i64> a;
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
	cin >> n >> M; a.resize(n);
	for (i64 i=0; i<n; i++) cin >> a[i];
}

void Solve() {
	vector<i64> sOn(n+2, 0), sOff(n+2, 0);
	for (i64 i=1; i<=n; i++) {
		if (i % 2 == 1) sOn[i] = sOn[i-1] + a[i-1] - ((i < 2) ? 0 : a[i-2]);
		else sOn[i] = sOn[i-1];
		if (i % 2 == 0) sOff[i] = sOff[i-1] + a[i-1] - ((i < 2) ? 0 : a[i-2]);
		else sOff[i] = sOff[i-1];
	}
	if ((n + 1) % 2 == 1) {
		sOn[n+1] = sOn[n] + (M - a[n-1]);
		sOff[n+1] = sOff[n];
	}
	else {
		sOff[n+1] = sOff[n] + (M - a[n-1]);
		sOn[n+1] = sOn[n];
	}
	//cout << sOn << endl << sOff << endl;
	i64 ans = sOn[n+1];
	for (i64 i=1; i<=n; i++) {
		if (i % 2 == 1) ans = max(ans, sOn[i] + sOff[n+1] - sOff[i] - 1);
		else ans = max(ans, sOn[i-1] + (a[i-1] - ((i < 2) ? 0 : a[i-2])) + sOff[n+1] - sOff[i] - 1);
		//tracker2(i, ans);
	}
	cout << ans;
}