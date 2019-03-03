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
i64 n, q, c;
vi starX, starY, starS;
vector<vector<vi>> prefixSum(128, vector<vi>(128, vi(16, 0)));
vi qT, qX1, qY1, qX2, qY2;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> q >> c; starX.resize(n); starY = starX; starS = starX;
	for (i64 i=0; i<n; i++) cin >> starX[i] >> starY[i] >> starS[i];
	qT.resize(q); qX1 = qT; qY1 = qT; qX2 = qT; qY2 = qT;
	for (i64 i=0; i<q; i++) cin >> qT[i] >> qX1[i] >> qY1[i] >> qX2[i] >> qY2[i];
}

void ProSolve() {
	for (i64 i=0; i<16; i++) {
		for (i64 j=0; j<n; j++) {
			prefixSum[starX[j]][starY[j]][i] += ((starS[j] + i) % (c + 1));
		}
		for (i64 x=1; x<128; x++) {
			for (i64 y=1; y<128; y++) {
				prefixSum[x][y][i] += prefixSum[x][y-1][i];
				prefixSum[x][y][i] += prefixSum[x-1][y][i];
				prefixSum[x][y][i] -= prefixSum[x-1][y-1][i];
			}
		}
	}
	for (i64 i=0; i<q; i++) {
		i64 ans = prefixSum[qX2[i]][qY2[i]][qT[i] % (c + 1)];
		ans -= prefixSum[qX2[i]][qY1[i]-1][qT[i] % (c + 1)];
		ans -= prefixSum[qX1[i]-1][qY2[i]][qT[i] % (c + 1)];
		ans += prefixSum[qX1[i]-1][qY1[i]-1][qT[i] % (c + 1)];
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