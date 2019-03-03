#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n; vector<int> c;
int dp[5000][5000][2];
// Third dimension: 0 for left col, 1 for right col
int Inf = 1000000000;

void Input() {
	cin >> n; c.resize(n);
    for (int i=0; i<n; i++) cin >> c[i];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int dir=0; dir<2; dir++) {
                dp[i][j][dir] = Inf;
            }
        }
    }
}

void Solve() {
    for (int i=0; i<n; i++) {
        dp[i][i][0] = dp[i][i][1] = 0;
    }
    for (int Len=1; Len<n; Len++) {
        for (int i=0; i<=n-Len; i++) {
            int j = i + Len - 1;
            for (int dir=0; dir<2; dir++) {
                int col = (dir == 0) ? c[i] : c[j];
                if (i > 0) {
                    dp[i-1][j][0] = min(dp[i-1][j][0], dp[i][j][dir] + (col != c[i-1]));
                }
                if (j+1 < n) {
                    dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][dir] + (col != c[j+1]));
                }
            }
        }
    }
    cout << min(dp[0][n-1][0], dp[0][n-1][1]) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}
