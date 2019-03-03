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

bool visited[200001];
vector<int> adj[200001];

long long DFS(long long z, long long cc) {
    cc++; visited[z] = true;
    for (long long i=0; i<adj[z].size(); i++) {
        if (!visited[adj[z][i]]) {
            cc = DFS(adj[z][i], cc);
        }
    }
    return cc;
}

int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
	}
	long long ans = 1;
	for (long long i=1; i<=2*n; i++) {
        if (!visited[i]) {
            long long tmp = DFS(i, 0);
            ans = (ans * tmp) % 1000000007;
        }
	}
	cout << ans;
	return 0;
}
