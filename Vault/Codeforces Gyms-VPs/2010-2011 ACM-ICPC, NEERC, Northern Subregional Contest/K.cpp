/**********************************************************
 *     Code written by Akikaze                            *
 *     Duy-Bach Le, #Team4T's Chief Executor              *
 *     #Team4T Tertiary Flagship - Oblivion               *
 *                                                        *
 *     Written by a random fan of momocashew and Chiho    *
 *                                                        *
 *     Arigatougozaimasu, imouto-chan.                    *
 **********************************************************/

/************** [OPTIMIZATION PROTOCOL] **************/
#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
/*****************************************************/

/************** [LIBRARY PROTOCOL] **************/
#include <bits/stdc++.h>
using namespace std;
/************************************************/

/************** [LEGENDS/CONSTANTS] **************/
#define endl '\n'
#define i64 long long
#define ld double
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
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
long long keyCount = sizeof(keymod) / sizeof(long long);
/*************************************************/

/************** [BITWISE FUNCTIONS] **************/
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcountll(s); }
/*************************************************/

/************** [MASTER CONTROLS - PHASE 1] **************/
auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();
#define OImode 227420978
#define MultiTest 227420978

//#undef OImode // Switch this off if submitting OI problems.
#undef MultiTest // Switch this off if submitting multi-test problems.

void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
i64 w, l, n, xr, yr; vector<pii> A;
ld dp[(1LL << 18)][18]; bool vis[(1LL << 18)][18];
/************************************************/

/************** [FUNCTIONS] **************/
ld sqr(ld x) {
	return (x * x);
}

ld Dist(pii a, pii b) {
	ld dx = (ld)a.fi - b.fi;
	ld dy = (ld)a.se - b.se;
	return sqrt(sqr(dx)+sqr(dy));
}

ld calc(int a, int b, int d){
    return (ld)a*d/(a+b);
}

ld optimalRoute(pii a, pii b, bool Left) {
    int a1,b1,d1;
    d1=abs(a.se-b.se);
	if(Left==true){
        a1=a.fi;
        b1=b.fi;
	}
	else{
        a1=w-a.fi;
        b1=w-b.fi;
	}
	ld x=calc(a1,b1,d1);
	return sqrt((ld)a1*a1+x*x)+sqrt((ld)b1*b1+sqr(d1-x));
}

ld optimalCeiling(pii a, pii b, bool Left) {
	int a1,b1,d1;
    d1=abs(a.fi-b.fi);
	if(Left==true){
        a1=a.se;
        b1=b.se;
	}
	else{
        a1=l-a.se;
        b1=l-b.se;
	}
	ld x=calc(a1,b1,d1);
	return sqrt((ld)a1*a1+x*x)+sqrt((ld)b1*b1+sqr(d1-x));
}
void Input() {
	cin >> w >> l >> n; A.rsz(n);
	for (i64 i=0; i<n; i++) cin >> A[i].fi >> A[i].se;
	cin >> xr >> yr;
}

void Solve() {
    //cout<<calc(1,3,1)<<endl;
    for (i64 i=0; i<(1LL << 18); i++) {
        for (i64 j=0; j<18; j++) {
            dp[i][j] = 1e9;
            vis[i][j] = false;
        }
    }
	queue<pii> Q;
	for (i64 i=0; i<n; i++) {dp[1LL << i][i] = Dist(mp(xr, yr), A[i]); Q.push(mp((1LL << i), i)); vis[1LL << i][i] = true;}
	while (!Q.empty()) {
		pii z = Q.front(); Q.pop();
		i64 mask = z.fi, x = z.se;
		//tracker3(mask, x, dp[mask][x]);
		for (i64 i=0; i<n; i++) {
			if ((mask & (1LL << i)) != 0) continue;
			if (!vis[mask | (1LL << i)][i]) {Q.push(mp(mask | (1LL << i), i)); vis[mask | (1LL << i)][i] = true;}
			//tracker3(i, optimalRoute(A[x], A[i], true), optimalRoute(A[x], A[i], false));
			dp[mask | (1LL << i)][i] = min(dp[mask | (1LL << i)][i], dp[mask][x] + min(min(optimalRoute(A[x], A[i], true), optimalRoute(A[x], A[i], false)), min(optimalCeiling(A[x], A[i], true), optimalCeiling(A[x], A[i], false))));
		}
	}
	ld Minimal = 1e18;
	for (i64 i=0; i<n; i++) Minimal = min(Minimal, dp[(1LL << n)-1][i] + min(min(A[i].fi, w-A[i].fi), min(A[i].se, l-A[i].se)));
	cout << fixed << setprecision(12) << Minimal;
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	ControlIO(argc, argv);
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	#ifndef MultiTest
		Input(); TimerStart();
		Solve(); TimerStop();
	#else
		int T; cin >> T; TimerStart();
		while(T--) {Input(); Solve();}
		TimerStop();
	#endif
	return 0;
}
/************************************/

/************** [MASTER CONTROLS - PHASE 2] **************/
void ControlIO(int argc, char* argv[]) {
	#ifdef Akikaze
	time_t t = time(0);
	tm* now = localtime(&t);
	cout << "Source code by #Team4T-Akikaze.\n";
	cout << "Current time: ";
	cout << (now->tm_year + 1900) << '-'
	     << (now->tm_mon + 1) << '-'
	     <<  now->tm_mday << " | "
	     <<  now->tm_hour << ":"
	     <<  now->tm_min << ":"
	     <<  now->tm_sec
	     << "\n\n";
	if (argc > 1) assert(freopen(argv[1], "r", stdin));
	if (argc > 2) assert(freopen(argv[2], "w", stdout));
	#elif OImode
	freopen("kitchen.in", "r", stdin);
	freopen("kitchen.out", "w", stdout);
	#endif
}

void TimerStart() {
	#ifdef Akikaze
	TimeStart = chrono::steady_clock::now();
	#endif
}

void TimerStop() {
	#ifdef Akikaze
	TimeEnd = chrono::steady_clock::now();
	auto ElapsedTime = TimeEnd - TimeStart;
	cout << "\n\nTime elapsed: " << chrono::duration<double>(ElapsedTime).count() << " seconds.\n";
	#endif
}

void Exit() {
	TimerStop(); exit(0);
}