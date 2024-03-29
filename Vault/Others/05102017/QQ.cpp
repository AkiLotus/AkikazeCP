// Template by proptit_4t41
// Applied for C++11/C++14
// Add -std=c++14 to your IDE.

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define i64 long long
#define u64 unsigned long long
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


// File I/O here
string problemName = "QQ";
string in = ".INP";
string out = ".OUT";

int main() {
	//ifstream fin; ofstream fout;
	//fin.open(problemName+in); fout.open(problemName+out);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	freopen("QQ.INP", "r", stdin);
	freopen("QQ.OUT", "w", stdout);
	i64 n; cin >> n;
	vector<pii> case1(n), case2(n);
	for (i64 i=0; i<n; i++) {
		i64 x, y; cin >> x >> y;
		case1[i] = mp(x,y);
		case2[i] = mp(y,x);
	}
	sort(case1.begin(), case1.end());
	sort(case2.begin(), case2.end());
	vector<i64> sum1(n), sum2(n);
	for (i64 i=0; i<n; i++) {
		if (i == 0) {
			sum1[i] = case1[i].fi; sum2[i] = case2[i].fi;
		}
		else {
			sum1[i] = sum1[i-1] + case1[i].fi;
			sum2[i] = sum2[i-1] + case2[i].fi;
		}
	}
	i64 ans = LINF;
	for (i64 i=0; i<n; i++) {
		i64 tmp1 = 0, tmp2 = 0;
		if (i == 0) {
			tmp1 = sum1[n-1] - case1[i].fi * n;
			tmp2 = sum2[n-1] - case2[i].fi * n;
		}
		else {
			tmp1 = (sum1[n-1] - case1[i].fi * (n-i)) + (case1[i].fi * i - sum1[i-1]);
			tmp2 = (sum2[n-1] - case2[i].fi * (n-i)) + (case2[i].fi * i - sum2[i-1]);
		}
		ans = min(ans, min(tmp1, tmp2));
	}
	cout << ans;
	//fin.close(); fout.close();
	return 0;
}
