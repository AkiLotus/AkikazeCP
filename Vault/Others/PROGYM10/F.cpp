// Template by proptit_4t41
// Applied for C++11/C++14
// Add -std=c++14 to your IDE.

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
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

// custom typedef here


// global variables here


// functions here


int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	// code here
	int n; cin >> n;
	if (n == 1) {
		cout << "! 1 1\n";
		return 0;
	}
	if (n == 2) {
		cout << "? 1 2\n";
		char a, b; cin >> a >> b;
		if (a == '?' || b == '-')
		cout << "! 1 1\n";
		return 0;
	}
	vector<int> defected(n+1, -1);
	vector<string> testWithOne(n+1);
	int nonDetermined = n;
	bool bothOperational = false, bothDefective = false;
	for (int i=2; i<=n; i++) {
		cout << "? 1 " << i << endl; cout.flush();
		char a, b; cin >> a >> b;
		string tmp = " "; tmp.insert(0, 1, a); tmp += b;
		if (a == '+' && b == '+') bothOperational = true;
		if (a == '-' && b == '-') bothDefective = true;
		testWithOne[i] = tmp;
	}
	if (bothOperational) {
		defected[1] = 0; int cc = 1;
		for (int i=2; i<=n; i++) {
			if(testWithOne[i].find("-") == -1) {
				defected[i] = 0; cc++;
			}
			else defected[i] = 1;
		}
		cout << "! " << cc;
		for (int i=1; i<=n; i++) if (!defected[i]) cout << " " << i; cout << endl;
	}
	else if (bothDefective) {
		defected[1] = 0; int cc = 1;
		for (int i=2; i<=n; i++) {
			if(testWithOne[i].find("-") == -1) {
				defected[i] = 0; cc++;
			}
			else defected[i] = 1;
		}
		cout << "! " << cc;
		for (int i=1; i<=n; i++) if (!defected[i]) cout << " " << i; cout << endl;
	}
	else {
		cout << "? " << n-1
	}
	return 0;
}
