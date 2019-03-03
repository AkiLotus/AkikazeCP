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
const long double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

// custom typedef here


// global variables here
int T, cas = 0;

// functions here


/* -----COMPULSORY FUNCTIONS----- */
void VarInput() {
	cin >> T;

}

void ProSolve() {
	cout << "Case " << ++cas << ":\n";
	int N; cin >> N; int F = -1, B = -1;
	vector<int> deck(555555, 0);
	map<int, int> M;
	while (N--) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			char x; int y; cin >> x >> y;
			if (F == -1 && B == -1) {
				F = 300000; B = 300000;
			}
			else {
				if (x == 'B') B--;
				else F++;
			}
			if (x == 'B') {
				deck[B] = y;
				M[y] = B;
			}
			else {
				deck[F] = y;
				M[y] = F;
			}
		}
		else if (cmd == 2) {
			char x; cin >> x;
			if (x == 'B') deck[B++] = 0;
			else deck[F--] = 0;
			if (B > F) {
				B = -1; F = -1;
			}
		}
		else if (cmd == 3) {
			char x; int y; cin >> x >> y;
			if (x == 'D') cout << deck[F-(y-1)] << endl;
			else cout << F-M[y]+1 << endl;
		}
	}
}

/* -----MAIN FUNCTION----- */
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	while (T--) ProSolve();
	return 0;
}
