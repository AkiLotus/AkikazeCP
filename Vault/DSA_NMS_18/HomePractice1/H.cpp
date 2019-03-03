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
 
// custom typedef here
 
 
// global variables here
vector<bool> visited;
int n, k, s, ans = 0;
 
// functions here
void Try_(int cc, int sum, int last) {
	if (cc == k) {
		if (sum == s) ans++;
		return;
	}
	for (int i=last+1; i<=n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			Try_(cc+1, sum+i, i);
			visited[i] = false;
		}
	}
}
 
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	cin >> n >> k >> s;
	while (n != 0 && k != 0 && s != 0) {
		visited.resize(n+1, false); ans = 0;
		for (int i=1; i<=n; i++) {
			visited[i] = true;
			Try_(1, i, i);
			visited[i] = false;
		}
		cout << ans << endl;
		cin >> n >> k >> s;
	}
	return 0;
} 