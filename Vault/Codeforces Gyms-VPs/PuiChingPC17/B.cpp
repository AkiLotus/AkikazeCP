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
	int N; cin >> N;
	vector<int> adj[N+1];
	vector<bool> visited(N+1, false);
	vector<int> level(N+1, -1);
	for (int i=1; i<N; i++) {
		int x, y; cin >> x >> y;
		adj[x].pub(y); adj[y].pub(x);
	}
	queue<int> pending;
	for (int i=1; i<=N; i++) {
		if (adj[i].size() == 1) {
			pending.push(i);
			level[i] = 0; break;
		}
	}
	if (N == 2) {
		cout << "0"; return 0;
	}
	while (!pending.empty()) {
		int z = pending.front(); pending.pop();
		if (visited[z]) continue;
		visited[z] = true;
		for (int i=0; i<adj[z].size(); i++) {
			if (!visited[adj[z][i]]) {
				pending.push(adj[z][i]);
				level[adj[z][i]] = level[z] + 1;
			}
		}
	}
	int tmp = *max_element(level.begin(), level.end());
	int ans = tmp % 2 + tmp / 2;
	cout << ans;
	//fin.close(); fout.close();
	return 0;
}
