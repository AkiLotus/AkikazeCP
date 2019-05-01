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
	Hashing Algorithm
    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/


/** -----GLOBAL VARIABLES----- **/
string A, B;
vi hashA;
i64 lenA, lenB;
i64 hashKey = 0, hashMul = 1;
i64 workingKey = 0;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	getline(cin, A); getline(cin, B);
	lenA = A.size(); lenB = B.size();
	hashA.resize(lenA, 0);
	
	// Initialize hashMul
	for (i64 i=1; i<lenB; i++) hashMul = (hashMul * 257) % MOD;
	
	// Calculate hashKey
	for (i64 i=0; i<lenB; i++) hashKey = (hashKey * 257 + int(B[i])) % MOD;
	
	// Pre-processing hashA array and workingKey
	for (i64 i=0; i<lenA; i++) {
		hashA[i] = int(A[i]);
		if (i < lenB) workingKey = (workingKey * 257 + hashA[i]) % MOD;
	}
}

void ProSolve() {
	// Prefix match
	if (workingKey == hashKey) cout << "1 ";
	
	// Other subsequences
	for (i64 i=1; i<=lenA-lenB; i++) {
		workingKey = (workingKey - hashA[i-1] * hashMul) % MOD;
		while (workingKey < 0) workingKey += MOD;
		workingKey = (workingKey * 257 + hashA[i+lenB-1]) % MOD;
		if (workingKey == hashKey) cout << (i+1) << " ";
	}
	cout << "";
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}