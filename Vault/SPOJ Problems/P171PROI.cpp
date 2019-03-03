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
vector<i64> Fib(89, 1);
vector<bool> mask(89, false);
i64 T, N, ans = 0, msb = -1;
map<vector<bool>, bool> Map;

/** -----EXTENSIVE FUNCTIONS----- **/
void generateBitMask(i64 z) {
	while (z > 0) {
		i64 tmp = upper_bound(Fib.begin(), Fib.end(), z) - Fib.begin();
		if (msb == -1) msb = tmp-1; mask[tmp-1] = true;
		z -= Fib[tmp-1];
	}
}

void track(vector<bool> Mask, i64 MSB) {
	ans++; Map[Mask] = true;
	for (i64 i=MSB; i>2; i--) {
		if (!Mask[i]) continue;
		if (!Mask[i-1] && !Mask[i-2]) {
			vector<bool> Masks(Mask.begin(), Mask.end());
			Masks[i] = false; Masks[i-1] = true; Masks[i-2] = true;
			if (Map[Masks]) continue;
			if (i == MSB) track(Masks, MSB-1);
			else track(Masks, MSB);
		}
	}
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> T;
	for (i64 i=2; i<89; i++) Fib[i] = Fib[i-1] + Fib[i-2];
}

void ProSolve() {
	Map.clear(); mask.clear();
	cin >> N; ans = 0; msb = -1;
	mask.resize(89, false);
	generateBitMask(N);
	for (i64 i=1; i<=msb; i++) cout << mask[i]; cout << endl;
	track(mask, msb);
	cout << ans << endl;
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
