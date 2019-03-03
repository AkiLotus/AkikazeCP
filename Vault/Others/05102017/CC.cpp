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
i64 n, k;
vector<i64> d(128);

// custom typedef here


// functions here
void solve1() {
	i64 ans = LINF;
	for (i64 i=0; i<n; i++) {
		i64 tmp = 0;
		for (i64 j=0; j<n; j++) tmp += abs(d[i]-d[j]);
		ans = min(ans, tmp);
	}
	cout << ans << ".00";
}

void solve2() {
	i64 sumsqr = 0, sum = 0;
	for (i64 i=0; i<n; i++) {
		sumsqr += d[i] * d[i];
		sum += d[i];
	}
	ld ans = sumsqr - ((ld)sum / n) * sum;
	cout << fixed << setprecision(2) << ans;
}

// File I/O here
string problemName = "CC";
string in = ".INP";
string out = ".OUT";

int main() {
	//ifstream fin; ofstream fout;
	//fin.open(problemName+in); fout.open(problemName+out);
	freopen("CC.INP", "r", stdin);
	freopen("CC.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	cin >> n >> k;
	for (i64 i=0; i<n; i++) cin >> d[i];
	if (n == 0) cout << "0.00";
	else if (k == 1) solve1();
	else solve2();
	//fin.close(); fout.close();
	return 0;
}
