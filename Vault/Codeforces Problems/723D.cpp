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
i64 n, m, k, lake = 0, ans = 0; vs board;
vector<vi> LKnum; vector<pii> LKcnt;
vi LKsize(2500, 0); vector<vb> vis;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m >> k; board.resize(n);
	for (i64 i=0; i<n; i++) cin >> board[i];
}

void ProSolve() {
	LKnum.resize(n, vi(m, -1));
	LKcnt.resize(2500); vis.resize(n, vb(m, false));
	for (i64 i=0; i<2500; i++) LKcnt[i].se = i;
	queue<pii> Q;
	for (i64 i=0; i<n; i++) {
		LKnum[i][0] = 0;
		if (board[i][0] == '.' && !vis[i][0]) {
			Q.push(mp(i, 0LL)); vis[i][0] = true;
		}
		LKnum[i][m-1] = 0;
		if (board[i][m-1] == '.' && !vis[i][m-1]) {
			Q.push(mp(i, m-1)); vis[i][m-1] = true;
		}
	}
	for (i64 j=0; j<m; j++) {
		LKnum[0][j] = 0;
		if (board[0][j] == '.' && !vis[0][j]) {
			Q.push(mp(0LL, j)); vis[0][j] = true;
		}
		LKnum[n-1][j] = 0;
		if (board[n-1][j] == '.' && !vis[n-1][j]) {
			Q.push(mp(n-1, j)); vis[n-1][j] = true;
		}
	}
	while (!Q.empty()) {
		LKcnt[lake].fi++; pii z = Q.front(); Q.pop();
		if (z.fi-1 >= 0 && board[z.fi-1][z.se] == '.' && !vis[z.fi-1][z.se]) {
			Q.push(mp(z.fi-1, z.se)); vis[z.fi-1][z.se] = true; LKnum[z.fi-1][z.se] = lake;	
		}
		if (z.fi+1 < n && board[z.fi+1][z.se] == '.' && !vis[z.fi+1][z.se]) {
			Q.push(mp(z.fi+1, z.se)); vis[z.fi+1][z.se] = true; LKnum[z.fi+1][z.se] = lake;	
		}
		if (z.se-1 >= 0 && board[z.fi][z.se-1] == '.' && !vis[z.fi][z.se-1]) {
			Q.push(mp(z.fi, z.se-1)); vis[z.fi][z.se-1] = true; LKnum[z.fi][z.se-1] = lake;	
		}
		if (z.se+1 < m && board[z.fi][z.se+1] == '.' && !vis[z.fi][z.se+1]) {
			Q.push(mp(z.fi, z.se+1)); vis[z.fi][z.se+1] = true; LKnum[z.fi][z.se+1] = lake;	
		}
	}
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			if (vis[i][j] || board[i][j] == '*') continue;
			lake++; Q.push(mp(i, j)); LKnum[i][j] = lake; vis[i][j] = true;
			while (!Q.empty()) {
				LKcnt[lake].fi++; pii z = Q.front(); Q.pop();
				if (z.fi-1 >= 0 && board[z.fi-1][z.se] == '.' && !vis[z.fi-1][z.se]) {
					Q.push(mp(z.fi-1, z.se)); vis[z.fi-1][z.se] = true; LKnum[z.fi-1][z.se] = lake;	
				}
				if (z.fi+1 < n && board[z.fi+1][z.se] == '.' && !vis[z.fi+1][z.se]) {
					Q.push(mp(z.fi+1, z.se)); vis[z.fi+1][z.se] = true; LKnum[z.fi+1][z.se] = lake;	
				}
				if (z.se-1 >= 0 && board[z.fi][z.se-1] == '.' && !vis[z.fi][z.se-1]) {
					Q.push(mp(z.fi, z.se-1)); vis[z.fi][z.se-1] = true; LKnum[z.fi][z.se-1] = lake;	
				}
				if (z.se+1 < m && board[z.fi][z.se+1] == '.' && !vis[z.fi][z.se+1]) {
					Q.push(mp(z.fi, z.se+1)); vis[z.fi][z.se+1] = true; LKnum[z.fi][z.se+1] = lake;	
				}
			}
		}
	}
//	cout << "lake = " << lake << endl;
//	for (i64 i=0; i<n; i++) {
//		for (i64 j=0; j<m; j++) {
//			cout << LKnum[i][j] << " ";
//		}
//		cout << endl;
//	}
	sort(LKcnt.begin()+1, LKcnt.begin()+lake+1);
	for (i64 x=1; x<=lake-k; x++) {
		i64 y = LKcnt[x].se;
		//cout << "codename = " << y << endl;
		for (i64 i=0; i<n; i++) {
			for (i64 j=0; j<m; j++) {
				//tracker2(i, j);
				//cout << "board[i][j] = " << board[i][j] << endl;
				//cout << "LKnum[i][j] = " << LKnum[i][j] << endl;
				if (board[i][j] == '.' && LKnum[i][j] == y) {
					board[i][j] = '*'; ans++;
				}
			}
		}
	}
	cout << ans << endl;
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			cout << board[i][j];
		}
		cout << endl;
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