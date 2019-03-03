#include <iostream>
#include <vector>
using namespace std;

long long strtoll(string z) {
	long long result = 0, sign = 1, i = 0;
	if (z[0] == '-') {
		i = 1; sign = -1;
	}
	for (; i<z.size(); i++) {
		result *= 10;
		result += (z[i] - '0');
	}
	return result * sign;
}

long long n;
vector<long long> adj[100001];
vector<long long> team(100001, -1);
long long team0 = 1, team1 = 0;

void DFS(long long z) {
    for (long long j=0; j<adj[z].size(); j++) {
        if (team[adj[z][j]] != -1) continue;
        team[adj[z][j]] = 1 - team[z];
        if (1 - team[z] == 0) team0++; else team1++;
        DFS(adj[z][j]);
    }
}

int main() {
    cin >> n;
    for (long long i=0; i<n-1; i++) {
        long long u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    team[1] = 0;
    DFS(1);
    long long ans = team0 * team1 - n + 1;
    cout << ans;
	return 0;
}
