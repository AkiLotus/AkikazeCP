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
i64 N, A, B;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> N >> A >> B;
}

void ProSolve() {
	if (A == 1 || B == 1) {
		for (i64 i=1; i<=N; i++) cout << i << " ";
		return;
	}
	if (N % A == 0) {
		for (i64 i=0; i<N/A; i++) {
			i64 st = i * A;
			for (i64 j=1; j<A; j++) cout << st+j+1 << " ";
			cout << st+1 << " ";
		}
		return;
	}
	if (N % B == 0) {
		for (i64 i=0; i<N/B; i++) {
			i64 st = i * B;
			for (i64 j=1; j<B; j++) cout << st+j+1 << " ";
			cout << st+1 << " ";
		}
		return;
	}
	i64 x = -2, y = -2;
	for (i64 i=1; i<=N/A; i++) {
		if ((N-i*A) % B == 0) {
			x = i; y = (N - i*A) / B; break;
		}
	}
	if (x == -2 && y == -2) {
		cout << "-1"; return;
	}
	i64 start = 0;
	for (i64 i=0; i<x; i++) {
		for (i64 j=1; j<A; j++) cout << start+j+1 << " ";
		cout << start+1 << " ";
		start += A;
	}
	for (i64 i=0; i<y; i++) {
		for (i64 j=1; j<B; j++) cout << start+j+1 << " ";
		cout << start+1 << " ";
		start += B;
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}