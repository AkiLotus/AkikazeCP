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
i64 T, m; vs dna(19, "");

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> T;
}

void ProSolve() {
	while (T--) {
		cin >> m; bool flag = false;
		for (i64 i=0; i<m; i++) cin >> dna[i];
		for (i64 i=60; i>2; i--) {
			vs ans(0);
			for (i64 j=0; j<m; j++) {
				for (i64 k=0; k<=60-i; k++) {
					string tmp = dna[j].substr(k, i);
					bool flag2 = true;
					for (i64 x=0; x<m; x++) {
						if (dna[x].find(tmp) >= dna[x].size()) {
							flag2 = false; break;
						}
					}
					if (flag2) {
						flag = true; ans.pub(tmp);
					}
				}
			}
			if (!ans.empty()) cout << *min_element(ans.begin(), ans.end()) << endl;
			if (flag) break;
		}
		if (!flag) cout << "no significant commonalities\n";
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}