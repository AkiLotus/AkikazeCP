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
i64 N, K;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> N >> K;
}

void ProSolve() {
	i64 minimum = 0;
	if (K % 2 == 0) minimum = K / 2 * 3;
	else minimum = (K-1) / 2 * 3 + 1;
	if (N < minimum) {cout << "-1"; return;}
	i64 tmpN = N;
	vi ans(K, 0); i64 tmp = N / K;
	for (i64 i=0; i<K; i++) {
		if (i % 2 == 0) ans[i] = tmp - 1;
		else ans[i] = tmp + 1;
		N -= ans[i];
	}
	for (i64 i=0; i<K; i+=2) {
		if (N == 0) break;
		ans[i]++; N--;
	}
	for (i64 i=1; i<K; i+=2) {
		if (N == 0) break;
		ans[i]++; N--;
	}
	if (K % 2 == 0) {for (i64 i=0; i<K; i++) cout << ans[i] << " "; return;}
	vi ans2(K, 0); N = tmpN;
	for (i64 i=0; i<K; i++) {
		if (i % 2 == 0) ans2[i] = tmp + 1;
		else ans2[i] = tmp - 1;
		N -= ans2[i];
	}
	if (N < 0) {for (i64 i=0; i<K; i++) cout << ans[i] << " "; return;}
	for (i64 i=1; i<K; i+=2) {
		if (N == 0) break;
		ans2[i]++; N--;
	}
	for (i64 i=0; i<K; i+=2) {
		if (N == 0) break;
		ans2[i]++; N--;
	}
	if (*max_element(ans.begin(), ans.end()) - *min_element(ans.begin(), ans.end()) < *max_element(ans2.begin(), ans2.end()) - *min_element(ans2.begin(), ans2.end())) {
		for (i64 i=0; i<K; i++) cout << ans[i] << " "; return;
	}
	for (i64 i=0; i<K; i++) cout << ans2[i] << " ";
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