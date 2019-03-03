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
i64 T; vector<vi> board(8, vi(8, 0));
map<i64, i64> Map1, Map2, Map3; i64 ans = -LINF;

/** -----EXTENSIVE FUNCTIONS----- **/
void Try_(i64 x, i64 y, i64 sum) {
	if (x == 7) {ans = max(ans, sum); return;}
	Map1[y]++; Map2[x+y]++; Map3[x-y]++;
	for (i64 i=0; i<8; i++) {
		if (Map1[i] == 0 && Map2[x+1+i] == 0 && Map3[x+1-i] == 0) Try_(x+1, i, sum+board[x+1][i]);
	}
	Map1[y]--; Map2[x+y]--; Map3[x-y]--;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> T;
}

void ProSolve() {
	while (T--) {
		while (!Map1.empty()) Map1.erase(Map1.begin());
		while (!Map2.empty()) Map2.erase(Map2.begin());
		while (!Map3.empty()) Map3.erase(Map3.begin());
		ans = -LINF;
		for (i64 i=0; i<8; i++) {
			for (i64 j=0; j<8; j++) {
				cin >> board[i][j];
			}
		}
		for (i64 i=0; i<8; i++) Try_(0, i, board[0][i]);
		cout << ans << endl;
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