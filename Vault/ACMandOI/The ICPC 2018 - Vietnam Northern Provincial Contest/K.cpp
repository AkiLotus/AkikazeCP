#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")
/*****************************************************/
 
/************** [LIBRARY PROTOCOL] **************/
#include <bits/stdc++.h>
using namespace std;
/************************************************/
 
/************** [LEGENDS/CONSTANTS] **************/
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
#define Interactive 227420978
 
#undef OImode // Switch this off if submitting OI problems.
#undef MultiTest // Switch this off if submitting multi-test problems.
#undef Interactive // Switch this off if submitting interactive problems. Also required when you need to debug step-by-step.
 
void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
/*********************************************************/
 
/************** [GLOBAL VARIABLES] **************/
 
/************************************************/
 
/************** [FUNCTIONS] **************/
 
i64 n,m,base,i,j;
i64 a[1005],b[1005];

i64 modMul(i64 a, i64 b) {
	if (b == 0) return 0;
	i64 tmp = modMul(a, b/2);
	if (b % 2 == 0) return ((tmp + tmp) % base);
	return ((((tmp + tmp) % base) + a) % base);
}
 
void Input() {
 	cin >> m >> n >> base;
 	for (i = 0; i < m; i++) cin >> a[i];
 	for (i = 0; i < n; i++) cin >> b[i];
 	for (i = 0; i < m; i++) 
 	for (j = 0; j < n; j++) {
 		i64 k = 0;
 		if ((k = __gcd(a[i],b[j])) > 1) {
 			a[i] /= k;
 			b[j] /= k;
 		}
 	}
 	//for (i = 0; i < n; i++) cout << b[i] <<' ';
 	i64 p = 1; 
 	i64 q = 1;
 	for (i = 0; i < m; i++) p = modMul(p,a[i]);
 	for (j = 0; j < n; j++) q = modMul(q,b[j]);
 	cout << p << endl << q << endl;
}
 
void Solve() {
 
}
/*****************************************/
 
/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	ControlIO(argc, argv);
 
	#ifndef Interactive
		ios_base::sync_with_stdio(0); cin.tie(NULL);
	#else
		ios_base::sync_with_stdio(0);
	#endif
 
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
	freopen("FILENAME.INP", "r", stdin);
	freopen("FILENAME.OUT", "w", stdout);
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
