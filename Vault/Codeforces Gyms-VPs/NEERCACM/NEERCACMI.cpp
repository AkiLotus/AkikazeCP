#include <iostream>
#include <queue>
#include <cmath>
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

long long n, m, q, p;
char board[256][256];
long long noise[26][65536];
long long noises[256][256];

int main() {
	cin >> n >> m >> q >> p;
	for (int i=0; i<26; i++) {
        noise[i][0] = (i+1)*q;
        //cout << noise[i][0];
        for (int j=1; j<n*m; j++) {
            noise[i][j] = noise[i][j-1] / 2;
            //cout << " " << noise[i][j];
        }
        //cout << endl;
	}
	for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cin >> board[i][j];
	}
	for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (board[i][j] >= 'A' && board[i][j] <= 'Z') {
                int id = board[i][j] - 'A';
                bool visited[n][m];
                for (int x=0; x<n; x++) {
                    for (int y=0; y<m; y++) visited[x][y] = false;
                }
                queue<pair<pair<int,int>, int>> Q;
                pair<pair<int,int>, int> tmp; tmp.first.first = i; tmp.first.second = j; tmp.second = 0;
                Q.push(tmp); visited[i][j] = true;
                while (!Q.empty()) {
                    pair<pair<int,int>, int> zzz = Q.front(); Q.pop();
                    pair<int,int> z = zzz.first;
                    //cout << "working at " << z.first << "-" << z.second << endl;
                    int dist = zzz.second;
                    noises[z.first][z.second] += noise[id][dist];
                    if (z.first-1 >= 0 && !visited[z.first-1][z.second] && board[z.first-1][z.second] != '*') {
                        pair<int,int> zz; zz.first = z.first-1; zz.second = z.second;
                        pair<pair<int,int>, int> zzzz; zzzz.first = zz; zzzz.second = dist+1;
                        Q.push(zzzz);
                        visited[z.first-1][z.second] = true;
                    }
                    if (z.second-1 >= 0 && !visited[z.first][z.second-1] && board[z.first][z.second-1] != '*') {
                        pair<int,int> zz; zz.first = z.first; zz.second = z.second-1;
                        pair<pair<int,int>, int> zzzz; zzzz.first = zz; zzzz.second = dist+1;
                        Q.push(zzzz);
                        visited[z.first][z.second-1] = true;
                    }
                    if (z.first+1 < n && !visited[z.first+1][z.second] && board[z.first+1][z.second] != '*') {
                        pair<int,int> zz; zz.first = z.first+1; zz.second = z.second;
                        pair<pair<int,int>, int> zzzz; zzzz.first = zz; zzzz.second = dist+1;
                        Q.push(zzzz);
                        visited[z.first+1][z.second] = true;
                    }
                    if (z.second+1 < m && !visited[z.first][z.second+1] && board[z.first][z.second+1] != '*') {
                        pair<int,int> zz; zz.first = z.first; zz.second = z.second+1;
                        pair<pair<int,int>, int> zzzz; zzzz.first = zz; zzzz.second = dist+1;
                        Q.push(zzzz);
                        visited[z.first][z.second+1] = true;
                    }
                }
            }
        }
	}
	int ans = 0;
	for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            //cout << noises[i][j] << " ";
            if (noises[i][j] > p) ans++;
        }
        //cout << endl;
	}
	cout << ans;
	return 0;
}
