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
i64 a, x, b, y, c, z;

/** -----EXTENSIVE FUNCTIONS----- **/
bool valid() {
    return ((x == y && y == z && a + b + c == x) || (a == b && b == c && x + y + z == a)
	|| (x == y && a + b == c && y + z == c) || (y == z && b + c == a && z + x == a) || (z == x && c + a == b && x + y == b)
	|| (a == b && x + y == z && b + c == z) || (b == c && y + z == x && c + a == x) || (c == a && z + x == y && a + b == y));
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> a >> x >> b >> y >> c >> z;
	if (valid()) cout << "YES";
	else {
	    i64 sw1 = a; a = x; x = sw1;
	    if (valid()) cout << "YES";
    	else {
    	    i64 sw2 = a; a = x; x = sw2; sw2 = b; b = y; y = sw2;
    	    if (valid()) cout << "YES";
        	else {
        	    i64 sw3 = b; b = y; y = sw3; sw3 = c; c = z; z = sw3;
        	    if (valid()) cout << "YES";
        	    else {
                    cout << "NO";
        	    }
        	}
    	}
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
