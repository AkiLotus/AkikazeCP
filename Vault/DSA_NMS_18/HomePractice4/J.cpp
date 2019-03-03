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
#define fi first.first
#define se first.second
#define th second
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
i64 T, A, B, C;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> T;
}

void ProSolve() {
	while (T--) {
		cin >> A >> B >> C; i64 x = -1, y = -1, z = -1, X = -1, Y = -1, Z = -1;
		vector<vector<vector<char> > > board(A, vector<vector<char> >(B, vector<char>(C, '.')));
		for (i64 i=0; i<A; i++) {
			for (i64 j=0; j<B; j++) {
				for (i64 k=0; k<C; k++) {
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S') {x = i; y = j; z = k;}
					else if (board[i][j][k] == 'E') {X = i; Y = j; Z = k;}
				}
			}
		}
		vector<vector<vi> > dp(A, vector<vi>(B, vi(C, LINF))); dp[x][y][z] = 0;
		vector<vector<vb> > vis(A, vector<vb>(B, vb(C, false))); vis[x][y][z] = true;
		queue<ppi> Q; Q.push(mp(mp(x, y), z));
		while (!Q.empty()) {
			ppi zazz = Q.front(); Q.pop();
			if (zazz.fi == X && zazz.se == Y && zazz.th == Z) break;
			if (zazz.fi - 1 >= 0 && board[zazz.fi-1][zazz.se][zazz.th] != '#' && !vis[zazz.fi-1][zazz.se][zazz.th]) {
				dp[zazz.fi-1][zazz.se][zazz.th] = dp[zazz.fi][zazz.se][zazz.th] + 1;
				Q.push(mp(mp(zazz.fi-1, zazz.se), zazz.th)); vis[zazz.fi-1][zazz.se][zazz.th] = true;
			}
			if (zazz.se - 1 >= 0 && board[zazz.fi][zazz.se-1][zazz.th] != '#' && !vis[zazz.fi][zazz.se-1][zazz.th]) {
				dp[zazz.fi][zazz.se-1][zazz.th] = dp[zazz.fi][zazz.se][zazz.th] + 1;
				Q.push(mp(mp(zazz.fi, zazz.se-1), zazz.th)); vis[zazz.fi][zazz.se-1][zazz.th] = true;
			}
			if (zazz.th - 1 >= 0 && board[zazz.fi][zazz.se][zazz.th-1] != '#' && !vis[zazz.fi][zazz.se][zazz.th-1]) {
				dp[zazz.fi][zazz.se][zazz.th-1] = dp[zazz.fi][zazz.se][zazz.th] + 1;
				Q.push(mp(mp(zazz.fi, zazz.se), zazz.th-1)); vis[zazz.fi][zazz.se][zazz.th-1] = true;
			}
			if (zazz.fi + 1 < A && board[zazz.fi+1][zazz.se][zazz.th] != '#' && !vis[zazz.fi+1][zazz.se][zazz.th]) {
				dp[zazz.fi+1][zazz.se][zazz.th] = dp[zazz.fi][zazz.se][zazz.th] + 1;
				Q.push(mp(mp(zazz.fi+1, zazz.se), zazz.th)); vis[zazz.fi+1][zazz.se][zazz.th] = true;
			}
			if (zazz.se + 1 < B && board[zazz.fi][zazz.se+1][zazz.th] != '#' && !vis[zazz.fi][zazz.se+1][zazz.th]) {
				dp[zazz.fi][zazz.se+1][zazz.th] = dp[zazz.fi][zazz.se][zazz.th] + 1;
				Q.push(mp(mp(zazz.fi, zazz.se+1), zazz.th)); vis[zazz.fi][zazz.se+1][zazz.th] = true;
			}
			if (zazz.th + 1 < C && board[zazz.fi][zazz.se][zazz.th+1] != '#' && !vis[zazz.fi][zazz.se][zazz.th+1]) {
				dp[zazz.fi][zazz.se][zazz.th+1] = dp[zazz.fi][zazz.se][zazz.th] + 1;
				Q.push(mp(mp(zazz.fi, zazz.se), zazz.th+1)); vis[zazz.fi][zazz.se][zazz.th+1] = true;
			}
		}
		if (dp[X][Y][Z] != LINF) cout << dp[X][Y][Z] << endl;
		else cout << "-1\n";
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