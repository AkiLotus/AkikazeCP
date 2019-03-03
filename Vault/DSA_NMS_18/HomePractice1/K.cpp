#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[24];
int n, m;
int ans = 0;
bool visited[24][24];

void DFS(int z, int len) {
    //cout << "working at " << z << " - len = " << len << endl;
    for (int i=0; i<adj[z].size(); i++) {
        int counts = 0;
        int zz = adj[z][i];
        if (!visited[z][zz]) {
            counts++;
            visited[z][zz] = true; visited[zz][z] = true;
            DFS(zz, len+1);
            visited[z][zz] = false; visited[zz][z] = false;
        }
        if (counts == 0) ans = max(ans, len);
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int t; cin >> t;
	while (t--) {
		for (int i=0; i<24; i++) {
			adj[i].clear();
			for (int j=0; j<24; j++) visited[i][j] = false;
		}
		ans = 0;
		cin >> n >> m;
		while (m-- > 0) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		#ifdef Akikaze
		auto TIME1 = chrono::steady_clock::now();
		#endif
		for (int i=1; i<=n; i++) {
			for (int j=0; j<24; j++) {
				for (int k=0; k<24; k++) visited[j][k] = false;
			}
			DFS(i, 0);
		}
		cout << ans << endl;
		#ifdef Akikaze
		auto TIME2 = chrono::steady_clock::now();
		auto DIFF = TIME2 - TIME1;
		cout << "\n\nTime elapsed: " << fixed << setprecision(18) << chrono::duration<double>(DIFF).count() << " seconds.";
		#endif
	}
	return 0;
}