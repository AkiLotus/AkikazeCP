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
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	i64 cas = 0, n, r, k; cin >> n >> r >> k;
	while (n != 0 && r != 0 && k != 0) {
		i64 a[3][n+1], tmp = 0;
		for (i64 i=1; i<3; i++) {
			for (i64 j=1; j<=n; j++) cin >> a[i][j];
		}
		i64 sub = min(*min_element(a[1]+1, a[1]+n+1), *min_element(a[2]+1, a[2]+n+1));
		tmp += sub * (2 * n);
		for (i64 i=1; i<3; i++) {
			for (i64 j=1; j<=n; j++) a[i][j] -= sub;
		}
		while (a[r][k] != 0) {
			a[r][k]--; tmp++;
			if (r == 2 && k == 1) {
				r = 1; k = 1;
			}
			else if (r == 1 && k == n) {
				r = 2; k = n;
			}
			else if (r == 1) k++;
			else if (r == 2) k--;
		}
		cout << "Case " << ++cas << ":\n";
		if (r == 1) cout << "INVALID\n";
		else {
			a[r][k] = tmp;
			for (i64 i=1; i<3; i++) {
				for (i64 j=1; j<=n; j++) cout << a[i][j] << " ";
				cout << endl;
			}
		}
		cin >> n >> r >> k;
	}
	return 0;
}
