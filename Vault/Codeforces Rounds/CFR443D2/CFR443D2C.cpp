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

/** -----IDEAS/ALGORITHMS----- **/


/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
int n;
vector<int> state(10, 0);

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n;
	while (n--) {
		string bitwise; int val; cin >> bitwise >> val;
		if (bitwise == "|") {
			for (int i=0; i<10; i++) {
				if (val & (1 << i)) {
					state[i] = 1;
				}
			}
		}
		else if (bitwise == "&") {
			for (int i=0; i<10; i++) {
				if (!(val & (1 << i))) {
					state[i] = -1;
				}
			}
		}
		else if (bitwise == "^") {
			for (int i=0; i<10; i++) {
				if (val & (1 << i)) {
					if (state[i] != 0) state[i] = -state[i];
					else state[i] = 2;
				}
			}
		}
	}
}

void ProSolve() {
	int And = 1023, Or = 0, Xor = 0, ans = 0;
	for (int i=0; i<10; i++) {
		if (state[i] == -1) And -= (1 << i);
		else if (state[i] == 2) Xor += (1 << i);
		else if (state[i] == 1) Or += (1 << i);
	}
	if (And != 1023) ans++; if (Or != 0) ans++; if (Xor != 0) ans++;
	cout << ans << endl;
	if (And != 1023) cout << "& " << And << endl;
	if (Or != 0) cout << "| " << Or << endl;
	if (Xor != 0) cout << "^ " << Xor << endl;
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
