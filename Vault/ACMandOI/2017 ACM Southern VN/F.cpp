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

/** -----IDEAS/ALGORITHMS----- **/


/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
int T, N, ans = 0; // for multi-testcase problems


/** -----EXTENSIVE FUNCTIONS----- **/
string To_string(int q) {
	string res = "";
	while (q > 0) {
		int tmp = q % 10;
		char c = char(48+tmp);
		res.insert(0, 1, c);
		q /= 10;
	}
	return res;
}

int Stoi(string q) {
	int res = 0;
	for (int i=0; i<q.size(); i++) {
		int tmp = q[i] - '0';
		res = res * 10 + tmp;
	}
	return res;
}

void reduce(string z) {
	if (z.size() == 1) {
		ans += (z[0] - '1'); return;
	}
	int tmp = 0;
	string ts = z; sort(ts.begin(), ts.end());
	if (z != ts) ans++;
	string recursive = "";
	for (int i=1; i<z.size(); i++) recursive += "9";
	ans += tmp; reduce(recursive);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> T;
}

void ProSolve() {
	ans = 0; cin >> N;
	string sN = To_string(N);
	reduce(sN);
	cout << ans << endl;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("F.INP", "r", stdin);
	//freopen("F.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	while(T--) ProSolve(); // for multi-testcase problems
	//ProSolve(); // for regular problems
	return 0;
}
