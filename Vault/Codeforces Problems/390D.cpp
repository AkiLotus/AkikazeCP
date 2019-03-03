#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, m, k;

int dx[] = {-1, +0, +0, +1};
int dy[] = {+0, -1, +1, +0};
pair<int, int> Default = {-1, -1};

vector<vector<int>> Dist;
vector<vector<pair<int, int>>> Last;

stack<pair<int, int>> Cells;

void Input() {
	cin >> n >> m >> k;
	Dist.resize(n+2, vector<int>(m+2, 4444));
	Last.resize(n+2, vector<pair<int, int>>(m+2, Default));
}

void Solve() {
	int cost = 0;
	
	queue<pair<int, int>> Q;
	Q.push({1, 1}); Dist[1][1] = 1;
	while (!Q.empty() && Cells.size() < k) {
		pair<int, int> C = Q.front(); Q.pop();
		Cells.push(C); int x = C.first, y = C.second;
		cost += Dist[x][y];
		for (int dir=0; dir<4; dir++) {
			if (x + dx[dir] < 1 || x + dx[dir] > n) continue;
			if (y + dy[dir] < 1 || y + dy[dir] > m) continue;
			if (Dist[x+dx[dir]][y+dy[dir]] != 4444) continue;
			Dist[x+dx[dir]][y+dy[dir]] = Dist[x][y] + 1;
			Q.push({x + dx[dir], y + dy[dir]});
			Last[x+dx[dir]][y+dy[dir]] = C;
		}
	}
	
	cout << cost << endl;
	
	while (!Cells.empty()) {
		stack<pair<int, int>> Traceback;
		int x = Cells.top().first, y = Cells.top().second; Cells.pop();
		while (x != -1 && y != -1) {
			Traceback.push({x, y});
			pair<int, int> NextCell = Last[x][y];
			x = NextCell.first; y = NextCell.second;
		}
		while (!Traceback.empty()) {
			pair<int, int> CurCell = Traceback.top();
			Traceback.pop();
			cout << "(" << CurCell.first << ", " << CurCell.second << ") ";
		}
		cout << endl;
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
