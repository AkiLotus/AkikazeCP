/**
	Template by Akikaze (秋風) - formerly proptit_4t41.
	Code written by a random fan of momocashew and Chiho.
**/

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
i64 n, ans = -LINF; set<i64> destroyed; multiset<i64> segments;
priority_queue<pii, vector<pii>, greater<pii>> minHeap;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	for (i64 i=0; i<n; i++) {
		i64 x; cin >> x;
		minHeap.push(mp(x, i));
	}
}

void ProSolve() {
	destroyed.insert(-1); destroyed.insert(n); segments.insert(n);
	queue<pii> tmp;
	while (!minHeap.empty()) {
		pii z = minHeap.top(); minHeap.pop(); tmp.push(z);
		while (!tmp.empty() && tmp.front().fi != z.fi) {
			i64 qq = tmp.front().se; tmp.pop();
			auto lwrit = destroyed.lower_bound(qq); lwrit--;
			auto uprit = destroyed.upper_bound(qq);
			i64 L = *lwrit, R = *uprit;
			segments.erase(segments.find(R-L-1)); destroyed.insert(qq);
			if (qq-1 - (L+1) + 1 > 0) segments.insert(qq-1 - (L+1) + 1);
			if (R-1 - (qq+1) + 1 > 0) segments.insert(R-1 - (qq+1) + 1);
		}
		auto lwrit = destroyed.lower_bound(z.se); lwrit--;
		auto uprit = destroyed.upper_bound(z.se);
		i64 L = *lwrit, R = *uprit;
		ans = max(ans, (R-L-1)*z.fi);
	}
	cout << ans;

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