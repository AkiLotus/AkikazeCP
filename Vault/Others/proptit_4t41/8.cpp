#include<bits/stdc++.h>
using namespace std;

bool visited[8000000];
int dp[8000000];
vector<int> adj[8000000];
int init, dest;
string inp = "";
string def = "1238004765";
map<string, int> M;

void generateCode() {
	string code = "0012345678";
	int permuNum = 0;
	M[code] = permuNum;
	while (next_permutation(code.begin(), code.end())) M[code] = ++permuNum;
}

void generateGraph(string z) {
	//cout << "bug spotting... - working at " << z << endl;
	int code = M[z];
	if (visited[code]) return;
	visited[code] = true;
	string tmp1 = z, tmp2 = z;
	//cout << "swap issues?\n";
	char swap1 = tmp1[0], swap2 = tmp1[1], swap3 = tmp1[3], swap4 = tmp1[5], swap5 = tmp1[7], swap6 = tmp1[8];
	tmp1[0] = swap3; tmp1[1] = swap1; tmp1[3] = swap5; tmp1[5] = swap2; tmp1[7] = swap6; tmp1[8] = swap4;
	swap1 = tmp2[1], swap2 = tmp2[2], swap3 = tmp2[4], swap4 = tmp2[6], swap5 = tmp2[8], swap6 = tmp2[9];
	tmp2[1] = swap3; tmp2[2] = swap1; tmp2[4] = swap5; tmp2[6] = swap2; tmp2[8] = swap6; tmp2[9] = swap4;
	//cout << "no swap issues -_-\n";
	int pos1 = M[tmp1], pos2 = M[tmp2];
	if (find(adj[code].begin(), adj[code].end(), pos1) == adj[code].end()) {
		adj[code].push_back(pos1);
		if (!visited[pos1]) generateGraph(tmp1);
	}
	if (find(adj[code].begin(), adj[code].end(), pos2) == adj[code].end()) {
		adj[code].push_back(pos2);
		if (!visited[pos2]) generateGraph(tmp2);
	}
}

int main()
{
    generateCode();
    cout << "generation completed\n";
    for (int i=0; i<8000000; i++) visited[i] = false;
	int hex[10];
	for (int i=0; i<10; i++) {
        cin >> hex[i];
        inp += ('0' + hex[i]);
	}
	cout << "RE check\n";
	init = M[inp];
	cout << "RE check\n";
	dest = M[def];
	cout << "RE check\n";
	generateGraph(inp);
	cout << "RE check\n";
	queue<int> Q;
	if (init != dest) Q.push(init);
	cout << "RE check\n";
	while (!Q.empty()) {
		int z = Q.front(); Q.pop();
		if (visited[z]) continue;
		visited[z] = true;
		for (int i=0; i<adj[z].size(); i++) {
			if (!visited[adj[z][i]]) {
				if (dp[adj[z][i]] == 0) dp[adj[z][i]] = dp[z] + 1;
				else dp[adj[z][i]] = min(dp[adj[z][i]], dp[z] + 1);
				Q.push(adj[z][i]);
			}
		}
	}
	cout << "RE check\n";
	cout << dp[dest];
	return 0;
}

