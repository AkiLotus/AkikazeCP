#include <iostream>
#include <vector>
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
	cin >> n >> m;
	while (m-- > 0) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
	}
	for (int i=1; i<=n; i++) {
        for (int j=0; j<24; j++) {
            for (int k=0; k<24; k++) visited[j][k] = false;
        }
        DFS(i, 0);
	}
	cout << ans;
	return 0;
}
