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
bool valid(vector<string> z) {
	int n = z.size();
	bool upper = true;
	for (int i=1; i<n; i++) {
		for (int j=i-1; j>=0; j--) {
			if (z[i][j] == '1') {
				upper = false; break;
			}
		}
		if (!upper) break;
	}
	if (upper) return true;
	for (int i=0; i<n-1; i++) {
		for (int j=i+1; j<n; j++) {
			if (z[i][j] == '1') return false;
		}
	}
	return true;
}

int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	int T, cas = 0; cin >> T;
	while (T--) {
		map<vector<string>, int> M;
		queue<vector<string>> Q;
		int N; cin >> N; vector<string> a(N);
		for (int i=0; i<N; i++) cin >> a[i];
		if (valid(a)) {
			cout << "Case #" << ++cas << ": 0\n";
			continue;
		}
		int ans = 0;
		Q.push(a);
		M[a] = 666666;
		while (!Q.empty()) {
			vector<string> z = Q.front(); Q.pop();
			if (valid(z)) {
				ans = M[z]; break;
			}
			for (int i=0; i<N-1; i++) {
				vector<string> tmp = z;
				string qq = tmp[i]; tmp[i] = tmp[i+1]; tmp[i+1] = qq;
				if (M[tmp] == 0) {
					Q.push(tmp);
					if (M[z] == 666666) M[tmp] = 1;
					else M[tmp] = M[z] + 1;
				}
			}
		}
		cout << "Case #" << ++cas << ": " << ans << endl;
	}
	return 0;
}
