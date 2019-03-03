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
string problemName = "";
string in = ".INP";
string out = ".OUT";

int main() {
	//ifstream fin; ofstream fout;
	//fin.open(problemName+in); fout.open(problemName+out);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	int x, y; cin >> x >> y;
	string cmd; cin >> cmd;
	int n; cin >> n;
	vector<string> name(n);
	vector<pii> a(n);
	vector<int> res(n);
	for (int i=0; i<n; i++) cin >> name[i] >> a[i].fi >> a[i].se;
	for (int i=0; i<n; i++) {
		if (cmd == "LEFT") {
			int tmpX = x - abs(a[i].se - y) / 2 - abs(a[i].se - y) % 2, tmpY = y;
			int zx = a[i].fi, zy = y; res[i] = abs(a[i].se - y) / 2 + abs(a[i].se - y) % 2;
			if (zx < tmpX) {
				res[i] += (tmpX - zx) / 3;
				if ((tmpX - zx) % 3 != 0) res[i]++;
			}
			else res[i] += (zx - tmpX);
		}
		else if (cmd == "RIGHT") {
			int tmpX = x + abs(a[i].se - y) / 2 + abs(a[i].se - y) % 2, tmpY = y;
			int zx = a[i].fi, zy = y; res[i] = abs(a[i].se - y) / 2 + abs(a[i].se - y) % 2;
			if (zx > tmpX) {
				res[i] += (zx - tmpX) / 3;
				if ((zx - tmpX) % 3 != 0) res[i]++;
			}
			else res[i] += (tmpX - zx);
		}
		else if (cmd == "DOWN") {
			int tmpX = x, tmpY = y - abs(a[i].fi - x) / 2 - abs(a[i].fi - x) % 2;
			int zx = x, zy = a[i].se; res[i] = abs(a[i].fi - x) / 2 + abs(a[i].fi - x) % 2;
			if (zy < tmpY) {
				res[i] += (tmpY - zy) / 3;
				if ((tmpY - zy) % 3 != 0) res[i]++;
			}
			else res[i] += (zy - tmpY);
		}
		else if (cmd == "UP") {
			int tmpX = x, tmpY = y + abs(a[i].fi - x) / 2 + abs(a[i].fi - x) % 2;
			int zx = x, zy = a[i].se; res[i] = abs(a[i].fi - x) / 2 + abs(a[i].fi - x) % 2;
			if (zy > tmpY) {
				res[i] += (zy - tmpY) / 3;
				if ((zy - tmpY) % 3 != 0) res[i]++;
			}
			else res[i] += (tmpY - zy);
		}
	}
	int ans = min_element(res.begin(), res.end()) - res.begin();
	cout << name[ans];
	//fin.close(); fout.close();
	return 0;
}
