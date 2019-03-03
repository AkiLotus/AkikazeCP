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
i64 limit, ans = 0, node = 1; string s;
vb badLetter(26, false);
vector<vi> mask(1, vi(26, -1));

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> s;
	for (i64 i=0; i<26; i++) {
		char c; cin >> c;
		badLetter[i] = (c == '0');
	}
	cin >> limit;
}

void ProSolve() {
	for (i64 i=0; i<s.size(); i++) {
		bool newRoad = false;
		i64 position = 0, bad = 0;
		for (i64 j=i; j<s.size(); j++) {
			if (badLetter[s[j]-'a']) bad++;
			if (mask[position][s[j]-'a'] != -1) {
				//cout << "following old trail to node " << mask[position][s[j]-'a'] << endl;
				position = mask[position][s[j]-'a'];
			}
			else {
				newRoad = true;
				mask.pub(vi(26, -1));
				mask[position][s[j]-'a'] = node++;
				position = node - 1;
				//cout << "new trail to node " << node-1 << endl;
			}
			if (bad > limit) break;
			if (newRoad) {
				//for (i64 x=i; x<=j; x++) cout << s[x]; cout << endl;
				ans++;
			}
		}
		//cout << "oldExtend = " << (oldExtend ? "true\n" : "false\n");
		//cout << "newRoad = " << (newRoad ? "true\n" : "false\n");
	}
	cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}