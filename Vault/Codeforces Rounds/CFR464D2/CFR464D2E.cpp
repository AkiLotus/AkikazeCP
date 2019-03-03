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
i64 Q, ptr = -1; vd a, s;
ld sum = 0, avg = 0, last = 0; i64 cnt = 0;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> Q;
}

void ProSolve() {
	i64 ptr = -1, sumset = 0, cntset = 0;
	while (Q--) {
		i64 cmd; cin >> cmd;
		if (cmd == 1) {
			cin >> last;
			a.pub(last); sum += last;
			s.pub(sum); cnt++;
			//for (i64 i=0; i<cnt; i++) cout << a[i] << " "; cout << endl;
			//for (i64 i=0; i<cnt; i++) cout << s[i] << " "; cout << endl;
		}
		else {
			while (ptr + 1 < cnt-1 && a[ptr+1] < (sumset + last) / (cntset + 1)) {
				ptr++; cntset++; sumset += a[ptr];
			}
			i64 sumset = 0; if (ptr >= 0) sumset = s[ptr];
			//cout << "ptr = " << ptr << endl;
			//cout << "max = " << last << endl;
			//cout << "sumset = " << last + sumset << endl;
			//cout << "cntset = " << cntset << endl;
			cout << fixed << setprecision(9) << (last - ((last + sumset) / (ptr + 2))) << endl;
		}
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}