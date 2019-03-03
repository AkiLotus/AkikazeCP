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

/** -----IDEAS/ALGORITHMS-----
	Có 3 trường hợp thỏa mãn:
		M = N: Đồ thị gồm 1 vòng khép kín
		M = nCr(N, 2): Đồ thị đầy đủ
		M = N^2 / 4: Đồ thị 2 phía đầy đủ (Biclique / Complete Bipartite Graph) đối xứng
    -------------------------- **/

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
int N, M;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> N >> M;
}

void ProSolve() {
	if (M < N) {
		cout << "Impossible"; return;
	}
	if (M == N) {
		cout << "Possible\n";
		cout << "1 " << N;
		for (int i=1; i<N; i++) cout << endl << i << " " << i+1;
		return;
	}
	if (M == N*(N-1)/2) {
		cout << "Possible";
		for (int i=1; i<N; i++) {
			for (int j=i+1; j<=N; j++) cout << endl << i << " " << j;
		}
		return;
	}
	if (N % 2 == 0 && M == N * N / 4) {
		cout << "Possible";
		for (int i=1; i<=N/2; i++) {
			for (int j=N/2+1; j<=N; j++) {
				cout << endl << i << " " << j;
			}
		}
		return;
	}
	cout << "Impossible";
}

/** -----MAIN FUNCTION----- **/
int main() {
	freopen("TOURMAP.INP", "r", stdin);
	freopen("TOURMAP.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
