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
	vector<bool> visited(11111, false);
	vector<int> state(11111, 0);
	vector<int> dp(11111, -1);
	dp[0] = 0;
	visited[0] = true; state[0] = 1;
	queue<int> Q; Q.push(0);
	while (!Q.empty()) {
		int z = Q.front(); Q.pop();
		for (int i=1; i<=6; i++) {
			if (i == state[z]) continue;
			if (i + state[z] == 7) continue;
			if (i + z > 10000) continue;
			if (!visited[z+i]) {
				visited[z+i] = true;
				dp[z+i] = dp[z] + 1;
				Q.push(z+i); state[z+i] = i;
			}
		}
	}
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << dp[n] << endl;
	}
	//fin.close(); fout.close();
	return 0;
}
