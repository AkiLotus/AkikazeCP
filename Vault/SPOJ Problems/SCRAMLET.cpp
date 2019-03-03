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
i64 N; vs A, Mi, Mx;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> N; A.resize(N); Mi = A; Mx = A;
	for (i64 i=0; i<N; i++) {
		cin >> A[i]; Mi[i] = A[i]; Mx[i] = A[i];
		sort(Mi[i].begin(), Mi[i].end());
		sort(Mx[i].rbegin(), Mx[i].rend());
	}
	sort(Mi.begin(), Mi.end());
	sort(Mx.begin(), Mx.end());
	//for (i64 i=0; i<N; i++) cout << Mi[i] << " "; cout << endl;
	//for (i64 i=0; i<N; i++) cout << Mx[i] << " "; cout << endl;
}

void ProSolve() {
	for (i64 i=0; i<N; i++) {
		string tmp1 = A[i], tmp2 = A[i];
		sort(tmp1.begin(), tmp1.end()); sort(tmp2.rbegin(), tmp2.rend());
		//cout << tmp1 << " " << tmp2 << endl;
		i64 x1 = lower_bound(Mx.begin(), Mx.end(), tmp1) - Mx.begin();
		i64 x2 = lower_bound(Mi.begin(), Mi.end(), tmp2) - Mi.begin();
		x1++; if (x2 < Mi.size() && Mi[x2] == tmp2) x2++;
		cout << x1 << " " << x2 << endl;
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}