#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define y0 takethescythe
#define y1 reapyourenemies
#define yn feedontheirflesh
#define j1 ascendthroughtheirblood

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

string s; int n;
int dist[10][10][10][10];
int ans[10][10];

void Input() {
	cin >> s; n = s.size();
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			for (int k=0; k<10; k++) {
				for (int l=0; l<10; l++) {
					dist[i][j][k][l] = -1;
				}
			}
		}
	}
}

void Solve() {
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			for (int k=0; k<10; k++) {
				queue<int> Q; Q.push(k); dist[i][j][k][k] = 0;
				while (!Q.empty()) {
					int z = Q.front(); Q.pop();
					if (dist[i][j][k][(z + max(i, j)) % 10] == -1 || ((z + max(i, j)) % 10 == k && dist[i][j][k][(z + max(i, j)) % 10] == 0)) {
						dist[i][j][k][(z + max(i, j)) % 10] = dist[i][j][k][z] + 1;
						Q.push((z + max(i, j)) % 10);
					}
					if (dist[i][j][k][(z + min(i, j)) % 10] == -1 || ((z + min(i, j)) % 10 == k && dist[i][j][k][(z + min(i, j)) % 10] == 0)) {
						dist[i][j][k][(z + min(i, j)) % 10] = dist[i][j][k][z] + 1;
						Q.push((z + min(i, j)) % 10);
					}
				}
				if (dist[i][j][k][k] == 0) dist[i][j][k][k] = -1;
			}
		}
	}

	for (int i=0; i<n-1; i++) {
		for (int x=0; x<10; x++) {
			for (int y=0; y<10; y++) {
				if (ans[x][y] == -1) continue;
				if (dist[x][y][s[i]-'0'][s[i+1]-'0'] == -1) {ans[x][y] = -1; continue;}
				ans[x][y] += dist[x][y][s[i]-'0'][s[i+1]-'0'] - 1;
			}
		}
	}
	
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			cout << ans[i][j] << " ";
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