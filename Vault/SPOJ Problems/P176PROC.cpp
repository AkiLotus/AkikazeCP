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
i64 N, node = 1; 
vector<vi> mask(1, vi(26, -1));
vi outDeg(1, 0); vb End(1, false);

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> N;
}

void ProSolve() {
	while (N--) {
		string s; cin >> s;
		bool newRoad = false, oldExtend = false;
		i64 position = 0;
		for (i64 i=0; i<s.size(); i++) {
			if (mask[position][s[i]-'a'] != -1) {
				//cout << "following old trail to node " << mask[position][s[i]-'a'] << endl;
				position = mask[position][s[i]-'a'];
			}
			else {
				if (End[position]) oldExtend = true;
				outDeg[position]++; newRoad = true;
				mask.pub(vi(26, -1)); outDeg.pub(0); End.pub(false);
				mask[position][s[i]-'a'] = node++;
				position = node - 1;
				//cout << "new trail to node " << node-1 << endl;
			}
		}
		//cout << "oldExtend = " << (oldExtend ? "true\n" : "false\n");
		//cout << "newRoad = " << (newRoad ? "true\n" : "false\n");
		if (oldExtend || !newRoad) {
			cout << "BAD SET\n" << s << endl; return;
		}
		End[position] = true;
	}
	cout << "GOOD SET";
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}