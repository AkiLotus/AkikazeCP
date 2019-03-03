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
i64 M, N, Q; vs board;
vi powerOfTwo; vector<vi> hashVal;
vi X1, Y1, X2, Y2;

/** -----EXTENSIVE FUNCTIONS----- **/
i64 modPow(i64 a, i64 b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	i64 tmp = modPow(a, b/2);
	if (b % 2 == 0) return ((tmp * tmp) % MOD);
	return ((((tmp * tmp) % MOD) * a) % MOD);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> M >> N >> Q; board.resize(M);
	for (i64 i=0; i<M; i++) cin >> board[i];
	X1.resize(Q); X2 = X1; Y1 = X1; Y2 = X1;
	for (i64 i=0; i<Q; i++) {
		cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
		X1[i]--; Y1[i]--; X2[i]--; Y2[i]--;
	}
}

void ProSolve() {
	powerOfTwo.resize(N, 1); hashVal.resize(M, vi(N, 0));
	for (i64 i=1; i<N; i++) powerOfTwo[i] = (powerOfTwo[i-1] * 2) % MOD;
	for (i64 i=0; i<M; i++) {
		for (i64 j=0; j<N; j++) {
			if (j == 0) hashVal[i][j] = (board[i][j] == '*');
			else hashVal[i][j] = (hashVal[i][j-1] + ((board[i][j] == '*') * powerOfTwo[j]) % MOD) % MOD;
		}
	}
	for (i64 q=0; q<Q; q++) {
		i64 main = 0, inverse = 0; bool flag = true;
		for (i64 j=Y1[q]; j<=Y2[q]; j++) {
			main = (main + ((board[X1[q]][j] == '*') * powerOfTwo[j-Y1[q]]) % MOD) % MOD;
			inverse = (inverse + ((board[X1[q]][j] != '*') * powerOfTwo[j-Y1[q]]) % MOD) % MOD;
		}
		//cout << "main = " << main << endl;
		//cout << "inverse = " << inverse << endl;
		for (i64 i=X1[q]+1; i<=X2[q]; i++) {
			i64 tmp = hashVal[i][Y2[q]];
			if (Y1[q] > 0) {
				tmp = (tmp - hashVal[i][Y1[q]-1]) % MOD;
				while (tmp < MOD) tmp += MOD;
				tmp = (tmp * modPow(powerOfTwo[Y1[q]], MOD-2)) % MOD;
			}
			//cout << "tmp = " << tmp << endl;
			if (tmp != main && tmp != inverse) {
				flag = false; break;
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
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