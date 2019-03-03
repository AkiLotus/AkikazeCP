/**
	Template by proptit_4t41
	Applied for C++11/C++14
	Add -std=c++14 to your IDE.
**/

/**
	// code written by a random fan of momocashew
	// world.execute(me);
**/

/**
	To make it compatible to C++98,
	remove all tuple typedefs, unordered
	sets/maps/multisets/multimaps, and add
	a space between two '<'/'>'s when declaring
	multi-dimensional vectors (to avoid ambiguity).
**/

#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define endl '\n'
#define i64 long long
#define u64 unsigned long long
#define ld long double
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mmap multimap
#define mset multiset
#define umap unordered_map
#define uset unordered_set
#define ummap unordered_multimap
#define umset unordered_multiset
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define REcheck cout << "RE here?\n"
#define tracker1(i) cout << "working at " << i << endl;
#define tracker2(i,j) cout << "working at " << i << "-" << j << endl;
#define tracker3(i,j,k) cout << "working at " << i << "-" << j << "-" << k << endl;
const long double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
const long long MOD = 1000000007LL;
const long long INF = 1e9;
const long long LINF = 1e18;
const long double EPS = 1e-9;
const long double GOLD = ((1+sqrt(5))/2);
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/// MAIN SOLUTION STARTS HERE

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
//int T, cas = 0; // for multi-testcase problems
i64 n, personCount = 0;
vector<string> friends;
vector<vector<string>> numbers;

/** -----EXTENSIVE FUNCTIONS----- **/

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> n;
	while (n--) {
		string name; cin >> name;
		i64 pos = find(friends.begin(), friends.end(), name) - friends.begin();
		if (pos == personCount) {friends.pub(name); numbers.pub(vector<string>(0)); personCount++;}
		i64 t; cin >> t;
		while (t--) {
			string num; cin >> num; numbers[pos].pub(num);
		}
	}
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	cout << personCount << endl;
	for (i64 i=0; i<personCount; i++) {
		for (i64 j=numbers[i].size()-1; j>=0; j--) {
			for (i64 k=0; k<j; k++) {
				if (numbers[i][k].size() < numbers[i][k+1].size()) {
					string tmp = numbers[i][k];
					numbers[i][k] = numbers[i][k+1];
					numbers[i][k+1] = tmp;
				}
			}
		}
		for (i64 j=0; j<numbers[i].size(); j++) {
			string suffix = "";
			for (i64 k=numbers[i][j].size()-1; k>=0; k--) {
				suffix.insert(0, 1, numbers[i][j][k]);
				for (i64 l=j+1; l<numbers[i].size(); l++) {
					if (numbers[i][l] == suffix) {
						numbers[i].erase(numbers[i].begin()+l); l--;
					}
				}
			}
		}
		cout << friends[i] << " " << numbers[i].size();
		for (i64 j=0; j<numbers[i].size(); j++) cout << " " << numbers[i][j]; cout << endl;
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
