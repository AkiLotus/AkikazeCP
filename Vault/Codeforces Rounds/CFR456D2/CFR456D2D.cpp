/**
	Template by Akikaze
	Applied for C++11/C++14 (Add -std=c++14 to your IDE.)
	To make it compatible to C++98, remove all tuple typedefs,
	unordered sets/maps/multisets/multimaps, and add a space
	between two '<'/'>'s when declaring multi-dimensional vectors.
**/

/**
	Code written by a random fan of momocashew and Chiho
	Akikaze (あきかぜ - 秋風) - formerly proptit_4t41
**/

#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define endl '\n'
#define i64 long long
#define u64 unsigned long long
#define ld long double
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mmap multimap
#define mset multiset
#define umap unordered_map
#define uset unordered_set
#define ummap unordered_multimap
#define umset unordered_multiset
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define REcheck cout << "RE here?\n"
#define tracker1(i) cout << "working at " << i << endl;
#define tracker2(i,j) cout << "working at " << i << "-" << j << endl;
#define tracker3(i,j,k) cout << "working at " << i << "-" << j << "-" << k << endl;
const long double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
const long long MOD = 1000000007LL;
const long long INF = 1e9;
const long long LINF = 1e18;
const long double EPS = 1e-9;
const long double GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<vector<i64>> vvi;
typedef vector<ld> vd;
typedef vector<vector<ld>> vvd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;
typedef vector<pii> vp;

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/// MAIN SOLUTION STARTS HERE

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
//int T, cas = 0; // for multi-testcase problems
i64 n, m, r, k, cc, fish = 0, net = 0;
priority_queue<pip> heap; map<pii, i64> Map;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> n >> m >> r >> k;
	net = (n - r + 1) * (m - r + 1);
	//cout << "net = " << net << endl;
	i64 xMid = n/2, yMid = m/2;
	i64 xMin, xMax, yMin, yMax;
	if (n % 2 == 0) {
		xMin = max(0LL, xMid-r+1), xMax = min(n-1, xMid+r-1);
		yMin = max(0LL, yMid-r+1), yMax = min(m-1, yMid+r-1);
		heap.push(mp((xMax - xMin - r + 2) * (yMax - yMin - r + 2), mp(xMid, yMid))); Map[mp(xMid,yMid)]++;
		xMin = max(0LL, xMid-1-r+1), xMax = min(n-1, xMid-1+r-1);
		yMin = max(0LL, yMid-r+1), yMax = min(m-1, yMid+r-1);
		heap.push(mp((xMax - xMin - r + 2) * (yMax - yMin - r + 2), mp(xMid-1, yMid))); Map[mp(xMid-1,yMid)]++;
		if (m % 2 == 0) {
			xMin = max(0LL, xMid-r+1), xMax = min(n-1, xMid+r-1);
			yMin = max(0LL, yMid-1-r+1), yMax = min(m-1, yMid-1+r-1);
			heap.push(mp((xMax - xMin - r + 2) * (yMax - yMin - r + 2), mp(xMid, yMid-1))); Map[mp(xMid,yMid-1)]++;
			xMin = max(0LL, xMid-1-r+1), xMax = min(n-1, xMid-1+r-1);
			yMin = max(0LL, yMid-1-r+1), yMax = min(m-1, yMid-1+r-1);
			heap.push(mp((xMax - xMin - r + 2) * (yMax - yMin - r + 2), mp(xMid-1, yMid-1))); Map[mp(xMid-1,yMid-1)]++;
		}
	}
	else {
		xMin = max(0LL, xMid-r+1), xMax = min(n-1, xMid+r-1);
		yMin = max(0LL, yMid-r+1), yMax = min(m-1, yMid+r-1);
		heap.push(mp((xMax - xMin - r + 2) * (yMax - yMin - r + 2), mp(xMid, yMid))); Map[mp(xMid,yMid)]++;
		if (m % 2 == 0) {
			xMin = max(0LL, xMid-r+1), xMax = min(n-1, xMid+r-1);
			yMin = max(0LL, yMid-1-r+1), yMax = min(m-1, yMid-1+r-1);
			heap.push(mp((xMax - xMin - r + 2) * (yMax - yMin - r + 2), mp(xMid, yMid-1))); Map[mp(xMid,yMid-1)]++;
		}
	}
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	i64 cnt = 0;
	while (++cnt <= k) {
		pip data = heap.top(); heap.pop(); fish += data.fi;
		i64 x = data.se.fi, y = data.se.se;
		if (x > 0 && !Map[mp(x-1,y)]) {
			i64 xMin = max(0LL, x-1-r+1), xMax = min(n-1, x-1+r-1);
			i64 yMin = max(0LL, y-r+1), yMax = min(m-1, y+r-1);
			heap.push(mp((xMax - xMin - r + 2) * (yMax - yMin - r + 2), mp(x-1, y))); Map[mp(x-1,y)]++;
		}
		if (x < n-1 && !Map[mp(x+1,y)]) {
			i64 xMin = max(0LL, x+1-r+1), xMax = min(n-1, x+1+r-1);
			i64 yMin = max(0LL, y-r+1), yMax = min(m-1, y+r-1);
			heap.push(mp((xMax - xMin - r + 2) * (yMax - yMin - r + 2), mp(x+1, y))); Map[mp(x+1,y)]++;
			
		}
		if (y > 0 && !Map[mp(x,y-1)]) {
			i64 xMin = max(0LL, x-r+1), xMax = min(n-1, x+r-1);
			i64 yMin = max(0LL, y-1-r+1), yMax = min(m-1, y-1+r-1);
			heap.push(mp((xMax - xMin - r + 2) * (yMax - yMin - r + 2), mp(x, y-1))); Map[mp(x,y-1)]++;
		}
		if (y < m-1 && !Map[mp(x,y+1)]) {
			i64 xMin = max(0LL, x-r+1), xMax = min(n-1, x+r-1);
			i64 yMin = max(0LL, y+1-r+1), yMax = min(m-1, y+1+r-1);
			heap.push(mp((xMax - xMin - r + 2) * (yMax - yMin - r + 2), mp(x, y+1))); Map[mp(x,y+1)]++;
		}
	}
	cout << fixed << setprecision(12) << (ld)fish / net;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
