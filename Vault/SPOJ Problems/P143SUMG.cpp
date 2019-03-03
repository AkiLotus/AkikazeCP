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
typedef pair<i64, string> pis;

/** -----GLOBAL VARIABLES----- **/
i64 T, cas = 0; // for multi-testcase problems
char topKey[] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
char basKey[] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '.'};
char botKey[] = {'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'};
vector<vector<char>> keyboard(3, vector<char>(0));
i64 N; map<char, pii> coor; string baseword;
vector<pis> words;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	keyboard[0] = vector<char> (topKey, topKey+10);
	keyboard[1] = vector<char> (basKey, basKey+10);
	keyboard[2] = vector<char> (botKey, botKey+10);
	for (i64 i=0; i<3; i++) {
		for (i64 j=0; j<10; j++) {
			coor[keyboard[i][j]] = mp(i, j);
		}
	}
	cin >> T; // for multi-testcase problems
}

void ProSolve() {
	cin >> baseword >> N;
	words.resize(N);
	for (i64 i=0; i<N; i++) {
		cin >> words[i].se; words[i].fi = 0;
		for (i64 j=0; j<words[i].se.size(); j++) {
			pii base = coor[baseword[j]];
			pii here = coor[words[i].se[j]];
			words[i].fi += abs(base.fi-here.fi) + abs(base.se-here.se);
		}
	}
	sort(words.begin(), words.end());
	for (i64 i=0; i<N; i++) cout << words[i].se << " " << words[i].fi << endl;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	while(T--) ProSolve(); // for multi-testcase problems
	//ProSolve(); // for regular problems
	return 0;
}
