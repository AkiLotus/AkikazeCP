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
i64 n; vi a;
vi cnt1, cnt2;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n; a.resize(n, 0);
	cnt1 = a; cnt2 = a;
	for (i64 i=0; i<n; i++) {
		cin >> a[i];
		if (i == 0) cnt1[i] = (a[i] == 1);
		else cnt1[i] = cnt1[i-1] + (a[i] == 1);
	}
	for (i64 i=n-1; i>=0; i--) {
		if (i == n-1) cnt2[i] = (a[i] == 2);
		else cnt2[i] = cnt2[i+1] + (a[i] == 2);
	}
	//for (i64 i=0; i<n; i++) cout << cnt1[i] << " "; cout << endl;
	//for (i64 i=0; i<n; i++) cout << cnt2[i] << " "; cout << endl;
}

void ProSolve() {
	i64 ans = 0;
	for (i64 pivot=0; pivot<=n; pivot++) {
		i64 sumL = 0, sumR = 0;
		//cout << "pivot = " << pivot << endl;
		for (i64 i=0; i<=pivot; i++) {
			i64 tmp = 0;
			if (i - 1 >= 0) tmp += cnt1[i-1];
			if (i < n) tmp += cnt2[i];
			if (pivot + 1 < n) tmp -= cnt2[pivot+1];
			sumL = max(sumL, tmp);
			//cout << "sumL = " << sumL << endl;
		}
		for (i64 j=pivot; j<=n; j++) {
			i64 tmp = 0;
			if (j + 1 < n) tmp += cnt2[j+1];
			tmp += cnt1[min(j, n-1)];
			if (pivot - 1 >= 0) tmp -= cnt1[pivot-1];
			sumR = max(sumR, tmp);
			//cout << "sumR = " << sumR << endl;
		}
		ans = max(ans, sumL+sumR);
	}
	cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}