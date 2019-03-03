/**
	Template by proptit_4t41
	Applied for C++11/C++14
	Add -std=c++14 to your IDE.
**/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define i64 long long
#define u64 unsigned long long
#define ld long double
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define MOD 1000000007LL
#define INF 1e9
#define LINF 1e18
#define EPS 1e-9
#define GOLD ((1+sqrt(5))/2)
#define REcheck cout << "RE here?\n"
#define tracker1(i) cout << "working at " << i << endl;
#define tracker2(i,j) cout << "working at " << i << "-" << j << endl;
#define tracker3(i,j,k) cout << "working at " << i << "-" << j << "-" << k << endl;
const long double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
//int T, cas = 0; // for multi-testcase problems
i64 n, m; string s;
i64 seq = 0, dot = 0;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> n >> m >> s;
	for (i64 i=0; i<n; i++) {
		if (s[i] == '.') {
			seq++; i--;
			while (i<n && s[i+1] == '.') {
				dot++; i++;
			}
		}
	}
	while (m--) {
		i64 in; char c; cin >> in >> c;
		if (!((s[in-1] == '.' && c == '.') || (s[in-1] != '.' && c != '.'))) {
			if (s[in-1] == '.') {
				dot--; if (in-2 >= 0 && in < n && s[in-2] == s[in] && s[in] == '.') seq++;
				else if ((in-2 >= 0 || in == 1) && (in < n || in == n) && (in == 1 || s[in-2] != '.') && (s[in] != '.' || in == n)) seq--;
			}
			else {
				dot++; if (in-2 >= 0 && in < n && s[in-2] == s[in] && s[in] == '.') seq--;
				else if ((in-2 >= 0 || in == 1) && (in < n || in == n) && (in == 1 || s[in-2] != '.') && (s[in] != '.' || in == n)) seq++;
			}
		}
		s[in-1] = c;
		//cout << s << endl;
		//cout << dot << " " << seq << endl;
		cout << dot - seq << endl;
	}
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems

}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
