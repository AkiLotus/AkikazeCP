/**
	Template by Akikaze (秋風) - formerly proptit_4t41.
	Code written by a random fan of momocashew and Chiho.
	
	H△G x Mili - November 27th, 2013
	Mag Mell (Mili) - Sep 17th, 2014
	H△G x Mili Vol.2 - May 9th, 2015
	Miracle Milk (Mili) - Oct 12th, 2016
	青色フィルム (H△G) - February 14th, 2018
	Millennium Mother (Mili) - April 25th, 2018
**/

/** -----PRAGMA----- **/
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
i64 n; vector<vector<vector<char>>> pieces;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n; pieces.resize(4, vector<vector<char>>(n, vector<char>(n, '0')));
	for (i64 x=0; x<4; x++) {
		for (i64 i=0; i<n; i++) {
			for (i64 j=0; j<n; j++) {
				cin >> pieces[x][i][j];
			}
		}
	}
}

void ProSolve() {
	sort(pieces.begin(), pieces.end());
	i64 ans = LINF;
	do {
		i64 tmp1 = 0, tmp2 = 0;
		vector<vector<char>> board(2*n, vector<char>(2*n, '0'));
		for (i64 i=0; i<n; i++) {
			for (i64 j=0; j<n; j++) {
				board[i][j] = pieces[0][i][j];
				board[i+n][j] = pieces[1][i][j];
				board[i][j+n] = pieces[2][i][j];
				board[i+n][j+n] = pieces[3][i][j];
			}
		}
		for (i64 i=0; i<2*n; i++) {
			for (i64 j=0; j<2*n; j++) {
				if ((i64)(board[i][j] - '0') != (i + j) % 2) tmp1++;
				else tmp2++;
			}
		}
		ans = min(ans, min(tmp1, tmp2));
	} while (next_permutation(pieces.begin(), pieces.end()));
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