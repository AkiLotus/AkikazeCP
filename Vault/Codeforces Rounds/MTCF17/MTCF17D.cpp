#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int n;
map<pii, int> type;
vector<int> adj[100007];

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
        int par, typ;
        cin >> par >> typ;
        pii z; z.first = par; z.second = i;
        if (typ != -1) {
            type[z] = typ+1;
            adj[par].push_back(i);
        }
	}
	for (int i=1; i<=n; i++) {
        queue<int> Q;
        Q.push(i);
        while (!Q.empty()) {
            int z = Q.front(); Q.pop();
            pii mm; mm.first = i; mm.second = z;
            if (i != z && type[mm] == 0) continue;
            for (int j=0; j<adj[z].size(); j++) {
                Q.push(adj[z][j]);
                pii mn; mn.first = z; mn.second = adj[z][i];
                if (type[mm] == type[mn]) {
                    pii nn; nn.first = i; nn.second = adj[z][i];
                    type[nn] = type[mm];
                }
            }
        }
	}
	int q;
	cin >> q;

	return 0;
}
