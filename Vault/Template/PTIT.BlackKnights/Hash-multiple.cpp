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
	Hashing Algorithm (Multiple modules)
    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/


/** -----GLOBAL VARIABLES----- **/
i64 modArr[] = {(i64)1e9+3, (i64)1e9+7, (i64)1e8+3, (i64)1e8+7, (i64)1e7+7, (i64)1e7+3, (i64)1e6+3, (i64)1e6+7};
string A, B;
vector<vi> hashA;
i64 lenA, lenB;
vi hashKey(8, 0), hashMul(8, 1);
vi workingKey(8, 0);

/** -----EXTENSIVE FUNCTIONS----- **/
bool keyMatch() {
	for (i64 i=0; i<8; i++) {
		if (hashKey[i] != workingKey[i]) return false;
	}
	return true;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	getline(cin, A); getline(cin, B);
	lenA = A.size(); lenB = B.size();
	hashA.resize(8, vi(lenA, 0));
	
	// Initialize hashMul
	for (i64 x=0; x<8; x++) {
		for (i64 i=1; i<lenB; i++) hashMul[x] = (hashMul[x] * 257) % modArr[x];
	}
	
	// Calculate hashKey
	for (i64 x=0; x<8; x++) {
		for (i64 i=0; i<lenB; i++) hashKey[x] = (hashKey[x] * 257 + int(B[i])) % modArr[x];
	}
	
	// Pre-processing hashA array and workingKey
	for (i64 x=0; x<8; x++) {
		for (i64 i=0; i<lenA; i++) {
			hashA[x][i] = int(A[i]);
			if (i < lenB) workingKey[x] = (workingKey[x] * 257 + hashA[x][i]) % modArr[x];
		}
	}
}

void ProSolve() {
	if (lenA < lenB) {
		cout << ""; return;
	}
	
	// Prefix match
	if (keyMatch()) cout << "1 ";
	
	// Other subsequences
	for (i64 i=1; i<=lenA-lenB; i++) {
		for (i64 x=0; x<8; x++) {
			workingKey[x] = (workingKey[x] - hashA[x][i-1] * hashMul[x]) % modArr[x];
			while (workingKey[x] < 0) workingKey[x] += modArr[x];
			workingKey[x] = (workingKey[x] * 257 + hashA[x][i+lenB-1]) % modArr[x];
		}
		if (keyMatch()) cout << (i+1) << " ";
	}
	cout << "";
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}