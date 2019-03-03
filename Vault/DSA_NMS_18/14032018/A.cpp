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
i64 T, N; vector<vi> baseMat(2, vi(2, 1));

/** -----EXTENSIVE FUNCTIONS----- **/
vector<vi> matMul(vector<vi> A, vector<vi> B) {
	vector<vi> C(A.size(), vi(B[0].size()));
	for (i64 i=0; i<A.size(); i++) {
		for (i64 j=0; j<B[0].size(); j++) {
			for (i64 k=0; k<A[i].size(); k++) {
				C[i][j] += A[i][k] * B[k][j];
				C[i][j] %= MOD;
			}
		}
	}
	return C;
}

vector<vi> matPow(vector<vi> mat, i64 N) {
	i64 len = mat.size();
	vector<vi> unit(len, vi(len, 0));
	for (i64 i=0; i<len; i++) unit[i][i] = 1;
	if (N == 0) return unit;
	if (N == 1) return mat;
	vector<vi> tmp = matPow(mat, N/2);
	if (N % 2 == 0) return matMul(tmp, tmp);
	return matMul(matMul(tmp, tmp), mat);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> T; baseMat[0][0] = 0;
}

void ProSolve() {
	while (T--) {
		cin >> N;
		cout << matPow(baseMat, N)[0][1] << endl;
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