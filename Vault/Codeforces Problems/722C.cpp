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
i64 n; vi a, s, p;
set<i64> destroyed;
multiset<i64> heap;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n; a.resize(n, 0); s = a; p = a;
	for (i64 i=0; i<n; i++) cin >> a[i];
	for (i64 i=0; i<n; i++) {cin >> p[i]; p[i]--;}
}

void ProSolve() {
	s[0] = a[0]; destroyed.insert(-1); destroyed.insert(n);
	for (i64 i=1; i<n; i++) s[i] = s[i-1] + a[i];
	heap.insert(s[n-1]);
	for (i64 i=0; i<n; i++) {
		auto it2 = destroyed.lower_bound(p[i]);
		auto it1 = it2; it1--;
		i64 l = (*it1) + 1, r = (*it2) - 1;
		i64 curr = s[r]; if (l > 0) curr -= s[l-1];
		heap.erase(heap.find(curr)); destroyed.insert(p[i]);
		//cout << "destroyed " << curr << endl;
		if (p[i] > l) {
			i64 tmp = s[p[i]-1]; if (l > 0) tmp -= s[l-1];
			heap.insert(tmp); //cout << "inserted " << tmp << endl;
		}
		if (p[i] < r) {
			i64 tmp = s[r] - s[p[i]];
			heap.insert(tmp); //cout << "inserted " << tmp << endl;
		}
		if (!heap.empty()) {
			auto itmax = heap.end(); itmax--;
			cout << (*itmax) << endl;
		}
		else cout << "0\n";
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