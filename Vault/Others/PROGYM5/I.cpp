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
	int t; cin >> t;
	while (t--) {
		int n, s, e; cin >> n >> s >> e;
		s--; e--;
		vector<vector<int>> cc;
		vector<int> level(n, 0);
		vector<bool> visited(n, false);
		vector<int> adj[n];
		for (int i=0; i<n; i++) {
			vector<int> tmp(10, 0);
			cc.pub(tmp);
			string z; cin >> z;
			for (int j=0; j<20; j++) cc[i][z[j]-'0']++;
		}
		for (int i=0; i<n-1; i++) {
			for (int j=i+1; j<n; j++) {
				if (min(cc[i][0], cc[j][0]) + min(cc[i][1], cc[j][1]) + min(cc[i][2], cc[j][2]) + min(cc[i][3], cc[j][3]) + min(cc[i][4], cc[j][4]) + min(cc[i][5], cc[j][5]) + min(cc[i][6], cc[j][6]) + min(cc[i][7], cc[j][7]) + min(cc[i][8], cc[j][8]) + min(cc[i][9], cc[j][9]) == 17) {
					//cout << "connecting " << i << " and " << j << endl;
					adj[i].pub(j); adj[j].pub(i);
				}
			}
		}
		bool ok = false;
		queue<int> Q; Q.push(s);
		while (!Q.empty()) {
			int z = Q.front(); Q.pop();
			if (visited[z]) continue;
			if (z == e) {
				ok = true; break;
			}
			visited[z] = true;
			for (int i=0; i<adj[z].size(); i++) {
				if (!visited[adj[z][i]]) {
					level[adj[z][i]] = level[z] + 1;
					Q.push(adj[z][i]);
				}
			}
		}
		if (ok) cout << level[e] << endl;
		else cout << "-1\n";
	}
	//fin.close(); fout.close();
	return 0;
}
