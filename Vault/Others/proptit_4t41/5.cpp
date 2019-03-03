#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int a[k];
	bool visited[2048];
	int dp[2048];
	vector<int> V;
	for (int i=0; i<2048; i++) {
		visited[i] = false;
		dp[i] = -1;
	}
	queue<int> Q;
	for (int i=0; i<k; i++) {
		cin >> a[i];
		a[i] -= n;
		if (!visited[a[i]+1000]) {
			V.push_back(a[i]);
			Q.push(a[i]);
			dp[a[i]+1000] = 1;
		}
		visited[a[i]+1000] = true;
	}
	while (!Q.empty()) {
		int z = Q.front(); Q.pop();
		for (int i=0; i<V.size(); i++) {
			int tmp = z + V[i];
			if (tmp < -1000 || tmp > 1000) continue;
			if (!visited[tmp+1000]) {
				visited[tmp+1000] = true;
				Q.push(tmp);
				if (dp[tmp+1000] == -1) dp[tmp+1000] = dp[z+1000] + 1;
				else dp[tmp+1000] = min(dp[tmp+1000], dp[z+1000]+1);
			}
		}
	}
	cout << dp[1000];
	return 0;
}

