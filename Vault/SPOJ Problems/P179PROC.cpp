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
i64 T, n, ans = 0, i = 0;
vi Oper(69, 0); vs input;

/** -----EXTENSIVE FUNCTIONS----- **/
bool valid(i64 z) {
	return (z % 2 == 0 || z % 3 == 0 || z % 5 == 0 || z % 7 == 0);
}

void Try_(i64 pos, i64 ope) {
	Oper[pos] = ope;
	if (pos >= n-1) {
		i64 sum = 0, tmp = 0, sign = 1;
		for (i64 j=0; j<=n; j++) {
			if (j == 0) tmp += (input[i][j] - '0');
			else {
				if (Oper[j-1] == 0) tmp = tmp * 10 + (input[i][j] - '0');
				else {
					sum += tmp * sign; if (Oper[j-1] == 2) sign = -1; else sign = 1;
					tmp = (input[i][j] - '0');
				}
			}
		}
		sum += tmp * sign;
		if (valid(sum)) ans++;
		return;
	}
	for (i64 x=0; x<3; x++) Try_(pos+1, x);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> T; input.resize(T);
	for (i64 i=0; i<T; i++) cin >> input[i];
}

void ProSolve() {
	for (i=0; i<T; i++) {
		ans = 0; n = input[i].size() - 1;
		if (n > 0) for (i64 x=0; x<3; x++) Try_(0, x);
		else Try_(0, 0);
		cout << "Case #" << (i+1) << ": " << ans << endl;
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