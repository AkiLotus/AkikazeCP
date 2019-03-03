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
int n, v;
vector<int> c;
vector<int> steps(128, -1);
queue<int> q;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n; c.resize(n);
	for (int i=0; i<n; i++) cin >> c[i];
	steps[c[0]] = 1; q.push(c[0]);
	cin >> v;
	cout << "v = " << v << endl;
}

void ProSolve() {
	while(!q.empty()) {
		int z = q.front(); q.pop();
		tracker1(z);
		for (int i=0; i<n; i++) {
			if (c[i] >= z) continue;
				cout << "steps[" << z-c[i] << "] = " << steps[z-c[i]] << endl;
				cout << "steps[" << c[i] << "] = " << steps[c[i]] << endl;
			if (steps[z - c[i]] == -1) {
				steps[z-c[i]] = steps[z] + 1;
				cout << "steps[" << z-c[i] << "] = " << steps[z-c[i]] << endl;
				q.push(z-c[i]);
			}
			if (steps[c[i]] == -1) {
				steps[c[i]] = steps[z] + 1;
				cout << "steps[" << c[i] << "] = " << steps[c[i]] << endl;
				q.push(c[i]);
			}
		}
	}
	if (steps[v] == -1) cout << "impossible";
	else cout << steps[v];
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
