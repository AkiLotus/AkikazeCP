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
i64 n, ans = 0, hCount = 0; vs t;

/** -----EXTENSIVE FUNCTIONS----- **/
bool cmp1 (string a, string b) {
	string p1 = a, p2 = b;
	p1 += b; p2 += a;
	if (p1 > p2) return true;
	return false;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n; t.resize(n);
	for (i64 i=0; i<n; i++) cin >> t[i];
	sort(t.begin(), t.end(), cmp1);
}

void ProSolve() {
	//for (i64 i=0; i<n; i++) cout << t[i];
	for (i64 i=n-1; i>=0; i--) {
		i64 len = t[i].size();
		for (i64 j=len-1; j>=0; j--) {
			if (t[i][j] == 'h') hCount++;
			else ans += hCount;
		}
	}
	//cout << "  <<<<===  " << ans << endl;
	cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}