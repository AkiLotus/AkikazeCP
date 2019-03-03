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
	map<tiii, int> Map;
	int ans = 0;
	int N; cin >> N;
	int a, b, c; cin >> a >> b >> c;
	for (int i=-2; i<=2; i++) {
		for (int j=-2; j<=2; j++) {
			for (int k=-2; k<=2; k++) {
				int x = a+i, y = b+j, z = c+k;
				while (x <= 0) x += N; while (y <= 0) y += N; while (z <= 0) z += N;
				while (x > N) x -= N; while (y > N) y -= N; while (z > 0) z -= N;
				tiii tmp = mt(x,y,z);
				if (Map[tmp] == 0) ans++; Map[tmp]++;
			}
		}
	}
	int d, e, f; cin >> d >> e >> f;
	for (int i=-2; i<=2; i++) {
		for (int j=-2; j<=2; j++) {
			for (int k=-2; k<=2; k++) {
				int x = d+i, y = e+j, z = f+k;
				while (x <= 0) x += N; while (y <= 0) y += N; while (z <= 0) z += N;
				while (x > N) x -= N; while (y > N) y -= N; while (z > 0) z -= N;
				tiii tmp = mt(x,y,z);
				if (Map[tmp] == 0) ans++; Map[tmp]++;
			}
		}
	}
	cout << ans;
	return 0;
}
