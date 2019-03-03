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

// global variables here


// custom typedef here


// functions here


int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	vector<i64> ftrl(21, 1);
	i64 prime[] = {2,3,5,7,11,13,17,19};
	for (i64 i=1; i<21; i++) ftrl[i] = ftrl[i-1] * i;
	int n; cin >> n;
	while (n--) {
		vector<i64> cc(8, 0);
		bool ok = true;
		i64 z; cin >> z;
		for (i64 i=0; i<8; i++) {
			while (z % prime[i] == 0) {
				z /= prime[i]; cc[i]++;
			}
		}
		for (i64 i=7; i>0; i--) {
			if (i == 7) {
				while (cc[7] > 0) {
					cc[0] -= 16; cc[1] -= 8; cc[2] -= 5; cc[3] -= 7; cc[4]--; cc[5]--; cc[6]--; cc[7]--;
				}
			}
			else if (i == 6) {
				while (cc[6] > 0) {
					cc[0] -= 15; cc[1] -= 6; cc[2] -= 3; cc[3] -= 2; cc[4]--; cc[5]--; cc[6]--;
				}

			}
			else if (i == 5) {
				while (cc[5] > 0) {
					cc[0] -= 10; cc[1] -= 5; cc[2] -= 2; cc[3]--; cc[4]--; cc[5]--;
				}

			}
			else if (i == 4) {
				while (cc[4] > 0) {
					cc[0] -= 8; cc[1] -= 4; cc[2] -= 2; cc[3]--; cc[4]--;
				}

			}
			else if (i == 3) {
				while (cc[3] > 0) {
					cc[0] -= 4; cc[1] -= 2; cc[2]--; cc[3]--;
				}

			}
			else if (i == 2) {
				while (cc[2] > 0) {
					cc[0] -= 3; cc[1]--; cc[2]--;
				}

			}
			else {
				while (cc[1] > 0) {
					cc[0]--; cc[1]--;
				}
			}
			for (i64 z=0; z<8; z++) {
				if (cc[z] < 0) {
					ok = false; break;
				}
			}
			if (!ok) break;
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
