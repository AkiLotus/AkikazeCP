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
int N, M; // for multi-testcase problems


/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> N >> M; // for multi-testcase problems
}

void ProSolve() {
	int tmp1 = N, tmp2 = M;
	string s1 = "", s2 = "";
	for (int i=0; i<N+M; i++) {
		if (i == 0) {
			s1 += "0"; tmp1--;
		}
		else {
			if (tmp1 == 0) {
				s1 += "1"; tmp2--;
			}
			else if (tmp2 == 0) {
				s1 += "0"; tmp1--;
			}
			else if (i % 2 != 0) {
				if (s1[i-1] == '0') {
					s1 += "1"; tmp2--;
				}
				else {
					s1 += "0"; tmp1--;
				}
			}
			else {
				if (s1[i-1] == '0') {
					s1 += "0"; tmp1--;
				}
				else {
					s1 += "1"; tmp2--;
				}
			}
		}
	}
	tmp1 = N; tmp2 = M;
	for (int i=0; i<N+M; i++) {
		if (i == 0) {
			s2 += "1"; tmp2--;
		}
		else {
			if (tmp1 == 0) {
				s2 += "1"; tmp2--;
			}
			else if (tmp2 == 0) {
				s2 += "0"; tmp1--;
			}
			else if (i % 2 != 0) {
				if (s2[i-1] == '0') {
					s2 += "1"; tmp2--;
				}
				else {
					s2 += "0"; tmp1--;
				}
			}
			else {
				if (s2[i-1] == '0') {
					s2 += "0"; tmp1--;
				}
				else {
					s2 += "1"; tmp2--;
				}
			}
		}
	}
	int ans1 = 0, ans2 = 0;
	for (int i=1; i<N+M; i++) {
		if (s1[i] == s1[i-1]) ans1++;
		if (s2[i] == s2[i-1]) ans2++;
	}
	cout << max(ans1, ans2) << " " << N+M-1-max(ans1,ans2);
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
