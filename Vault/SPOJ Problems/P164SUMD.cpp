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
	map<string, int> M;
	int k; string z; cin >> k >> z;
	string tmp = ""; int tmpcc = 0;
	int breakingPos = -1;
	for (int i=0; i<z.size(); i++) {
		tmp += z[i];
		if (z[i] == '1') tmpcc++;
		if (tmpcc == k) {
			breakingPos = i; break;
		}
	}
	if (tmpcc < k) {
		cout << 0; return 0;
	}
	M[tmp]++;
	for (int i=breakingPos; i<z.size(); i++) {
		tmp += z[i];
		if (z[i] != '1') {
			if (!M[tmp]) ans++;
			M[tmp]++;
		}
		else {
			tmp.erase(0,1);
			int one = tmp.find()
		}
	}
	return 0;
}
