#include<bits/stdc++.h>
using namespace std;

bool visited[1000000];
int dp[1000000];
vector<int> adj[1000000];
int ini = 0, des = 0, answer;

void generate(int z) {
	int tmp1 = z, tmp2 = z;
	int dig1[6], dig2[6];
	int zz = 5;
	while (tmp1 > 0) {
		dig1[zz] = tmp1 % 10;
		tmp1 /= 10;
		zz--;
	}
	zz = 5;
	while (tmp2 > 0) {
		dig2[zz] = tmp2 % 10;
		tmp2 /= 10;
		zz--;
	}
	int swap1 = dig1[0], swap2 = dig1[1], swap3 = dig1[3], swap4 = dig1[4];
	dig1[0] = swap3; dig1[1] = swap1; dig1[3] = swap4; dig1[4] = swap2;
	swap1 = dig2[1]; swap2 = dig2[2]; swap3 = dig2[4]; swap4 = dig2[5];
	dig2[1] = swap3; dig2[2] = swap1; dig2[4] = swap4; dig2[5] = swap2;
	for (int i=0; i<6; i++) {
		tmp1 = tmp1 * 10 + dig1[i];
		tmp2 = tmp2 * 10 + dig2[i];
	}
	if (find(adj[z].begin(), adj[z].end(), tmp1) == adj[z].end()) {
		adj[z].push_back(tmp1);
		generate(tmp1);
	}
	if (find(adj[z].begin(), adj[z].end(), tmp2) == adj[z].end()) {
		adj[z].push_back(tmp2);
		generate(tmp2);
	}
}

int main()
{
	int init[6], dest[6];
	for (int i=0; i<6; i++) {
		cin >> init[i];
		ini = ini * 10 + init[i];
	}
	for (int i=0; i<6; i++) {
		cin >> dest[i];
		des = des * 10 + dest[i];
	}
	generate(ini);
	queue<int> Q;
	if (ini != des) Q.push(ini);
	while (!Q.empty()) {
		int z = Q.front();
		Q.pop();
		if (visited[z]) continue;
		if (z == des) break;
		for (int i=0; i<adj[z].size(); i++) {
			if (!visited[adj[z][i]]) {
				if (dp[adj[z][i]] == 0) dp[adj[z][i]] = dp[z] + 1;
				Q.push(adj[z][i]);
			}
		}
	}
	answer = dp[des];
	cout << answer;
	return 0;
}

