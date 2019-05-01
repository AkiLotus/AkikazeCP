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
	Knuth-Morris-Pratt Algorithm
    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/


/** -----GLOBAL VARIABLES----- **/
string A, B; i64 lenA, lenB;
vi LPS; bool containAnswer = false;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	getline(cin, A); getline(cin, B);
	lenA = A.size(); lenB = B.size();
	
	// Processing lookup table
	LPS.resize(lenB, 0); i64 length = 0;
	for (i64 i=1; i<lenB; i++) {
		while (length > 0 && B[length] != B[i]) length = LPS[length-1];
		if (B[length] == B[i]) LPS[i] = ++length;
		else LPS[i] = 0;
	}
}

void ProSolve() {
	i64 pointer = 0;
	for (i64 i=0; i<lenA; i++) {
		while (pointer > 0 && B[pointer] != A[i]) pointer = LPS[pointer-1];
		if (A[i] == B[pointer]) {
			pointer++;
			if (pointer == lenB) {
				if (containAnswer) cout << " ";
				cout << (i - lenB + 2);
				pointer = LPS[pointer-1];
				containAnswer = true;
			}
		}
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