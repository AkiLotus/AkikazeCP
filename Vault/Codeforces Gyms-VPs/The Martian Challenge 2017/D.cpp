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
map<char, char> Map;
int n;
string line;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	Map[' '] = ' ';
	Map['A'] = 'n'; Map['B'] = 'y'; Map['C'] = 'U'; Map['D'] = 'K'; Map['E'] = 'Z'; Map['F'] = 'X'; Map['G'] = 'k'; Map['H'] = 'b';
	Map['I'] = 'v'; Map['J'] = 'z'; Map['K'] = 'I'; Map['L'] = 'd'; Map['M'] = 's'; Map['N'] = 'h'; Map['O'] = 'u'; Map['P'] = 'r';
	Map['Q'] = 'M'; Map['R'] = 'i'; Map['S'] = 'l'; Map['T'] = 'N'; Map['U'] = 'S'; Map['V'] = 'V'; Map['W'] = 'O'; Map['X'] = 't';
	Map['Y'] = 'e'; Map['Z'] = 'c';
	Map['a'] = 'P'; Map['b'] = 'g'; Map['c'] = 'E'; Map['d'] = 'f'; Map['e'] = 'T'; Map['f'] = 'Y'; Map['g'] = 'a'; Map['h'] = 'W';
	Map['i'] = 'G'; Map['j'] = 'H'; Map['k'] = 'j'; Map['l'] = 'D'; Map['m'] = 'A'; Map['n'] = 'm'; Map['o'] = 'x'; Map['p'] = 'Q';
	Map['q'] = 'q'; Map['r'] = 'F'; Map['s'] = 'L'; Map['t'] = 'R'; Map['u'] = 'p'; Map['v'] = 'C'; Map['w'] = 'J'; Map['x'] = 'B';
	Map['y'] = 'o'; Map['z'] = 'w';
	cin >> n; getline(cin, line);
	getline(cin, line);
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	for (int i=0; i<line.size(); i++) line[i] = Map[line[i]];
	cout << line << endl;
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
