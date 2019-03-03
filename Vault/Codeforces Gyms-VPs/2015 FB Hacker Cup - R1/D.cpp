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


int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
    int T, cas = 0; cin >> T;
    while (T--) {
        cout << "Case #" << ++cas << ": ";
        int N; cin >> N;
        vector<int> adj[N+1];
        vector<int> level(N+1, 0);
        vector<int> cc(N+1, 0);
        int maxLevel = 0;
        for (int i=1; i<=N; i++) {
            int z; cin >> z;
            adj[z].pub(i);
        }
        queue<int> Q; Q.push(0);
        while (!Q.empty()) {
            int z = Q.front(); Q.pop();
            for (int i=0; i<adj[z].size(); i++) {
                level[adj[z][i]] = level[z] + 1;
                maxLevel = max(maxLevel, level[z]+1);
                cc[level[z]+1]++;
                Q.push(adj[z][i]);
            }
        }
        for (int i=1; i<=N; i++) cout << level[i] << " "; cout << endl;
        for (int i=1; i<=maxLevel; i++) cout << cc[i] << " "; cout << endl;
        int ans1 = 0, ans2 = 0;
        for (int i=1; i<=maxLevel; i++) {
            if (i % 2 == 1) ans1 += cc[i];
            else ans1 += cc[i] * 2;
            if (i % 2 == 1) ans2 += cc[i] * 2;
            else ans2 += cc[i];
        }
        cout << min(ans1, ans2) << endl;
    }
	return 0;
}
