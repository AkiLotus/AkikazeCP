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
i64 n, m; vector<vector<char>> apa;
vector<vb> visited;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n >> m; visited.resize(n, vb(m, false));
	apa.resize(n, vector<char>(m, '.'));
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) cin >> apa[i][j];
	}
}

void ProSolve() {
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			if (visited[i][j]) continue;
			if (apa[i][j] != '.') continue;
			visited[i][j] = true;
			queue<pii> Q; Q.push(mp(i, j));
			i64 mnX = i, mnY = j, mxX = i, mxY = j;
			while (!Q.empty()) {
				pii z = Q.front(); Q.pop();
				mnX = min(mnX, z.fi); mxX = max(mxX, z.fi);
				mnY = min(mnY, z.se); mxY = max(mxY, z.se);
				if (z.fi - 1 >= 0 && !visited[z.fi-1][z.se] && apa[z.fi-1][z.se] == '.') {
					visited[z.fi-1][z.se] = true; Q.push(mp(z.fi-1, z.se));
				}
				if (z.se - 1 >= 0 && !visited[z.fi][z.se-1] && apa[z.fi][z.se-1] == '.') {
					visited[z.fi][z.se-1] = true; Q.push(mp(z.fi, z.se-1));
				}
				if (z.fi + 1 < n && !visited[z.fi+1][z.se] && apa[z.fi+1][z.se] == '.') {
					visited[z.fi+1][z.se] = true; Q.push(mp(z.fi+1, z.se));
				}
				if (z.se + 1 < m && !visited[z.fi][z.se+1] && apa[z.fi][z.se+1] == '.') {
					visited[z.fi][z.se+1] = true; Q.push(mp(z.fi, z.se+1));
				}
			}
			for (i64 x=mnX; x<=mxX; x++) {
				for (i64 y=mnY; y<=mxY; y++) {
					visited[x][y] = true;
					apa[x][y] = '.';
				}
			}
		}
	}
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			cout << apa[i][j];
		}
		cout << endl;
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}