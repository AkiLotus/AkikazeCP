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
i64 n, m, ans = 0;
i64 digit[4100][2050];

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n >> m;
	for (i64 i=0; i<n; i++) {
		string z; cin >> z;
		for (i64 j=0; j<m/8; j++) {
			if (z[2*j] >= '0' && z[2*j] <= '9') digit[i][j] += int(z[2*j]) - 48;
			else digit[i][j] += int(z[2*j]) - 55;
			digit[i][j] *= 16;
			if (z[2*j+1] >= '0' && z[2*j+1] <= '9') digit[i][j] += int(z[2*j+1]) - 48;
			else digit[i][j] += int(z[2*j+1]) - 55;
			//cout << digit[i][j] << " ";
		}
		//cout << endl;
	}
}

void ProSolve() {
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m/8; j++) {
			for (i64 x=3; x>=0; x--) {
				if (!(digit[i][j] & (1 << x))) continue;
				//tracker3(i,j,x); cout << "Start here\n";
				ans++;
				digit[i][j] &= (15 - (1 << x));
				queue<pii> Q; Q.push(mp(i, 4*j+x));
				while (!Q.empty()) {
					i64 z = Q.front().se;
					i64 a = Q.front().fi, b = z / 4, c = z % 4; Q.pop();
					//tracker3(a,b,c);
					if (a-1 >= 0 && ((digit[a-1][b]) & (1 << c))) {
						digit[a-1][b] = digit[a-1][b] & (15 - (1 << c));
						Q.push(mp(a-1, z));
					}
					if (a+1 < n && ((digit[a+1][b]) & (1 << c))) {
						digit[a+1][b] = digit[a+1][b] & (15 - (1 << c));
						Q.push(mp(a+1, z));
					}
					if (z-1 >= 0 && ((digit[a][(z-1)/4]) & (1 << ((z-1)%4)))) {
						digit[a][(z-1)/4] = digit[a][(z-1)/4] & (15 - (1 << ((z-1)%4)));
						Q.push(mp(a, z-1));
					}
					if (z+1 < m && ((digit[a][(z+1)/4]) & (1 << ((z+1)%4)))) {
						digit[a][(z+1)/4] = digit[a][(z+1)/4] & (15 - (1 << ((z+1)%4)));
						Q.push(mp(a, z+1));
					}
				}
			}
		}
	}
	cout << ans;
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
