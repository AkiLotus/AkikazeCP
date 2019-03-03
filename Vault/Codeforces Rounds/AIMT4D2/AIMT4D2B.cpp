#include <iostream>
using namespace std;

long long pow2 (long long z) {
    if (z == 0) return 1;
    return pow2(z-1) * 2;
}

int main() {
    long long n, m;
    cin >> n >> m;
    long long mat[n][m];
    long long col1[m], col0[m];
    long long row1[n], row0[n];
    for (long long i=0; i<m; i++) {
        col1[i] = 0; col0[i] = 0;
    }
    for (long long i=0; i<n; i++) {
        row1[i] = 0; row0[i] = 0;
    }
    long long ans = 0;
    for (long long i=0; i<n; i++) {
        for (long long j=0; j<m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 1) {
                row1[i]++; col1[j]++;
            }
            else {
                row0[i]++; col0[j]++;
            }
            ans++;
        }
    }
    for (long long i=0; i<n; i++) {
        if (row1[i] > 1) ans += pow2(row1[i]) - row1[i] - 1;
        if (row0[i] > 1) ans += pow2(row0[i]) - row0[i] - 1;
    }
    for (long long i=0; i<m; i++) {
        if (col1[i] > 1) ans += pow2(col1[i]) - col1[i] - 1;
        if (col0[i] > 1) ans += pow2(col0[i]) - col0[i] - 1;
    }
    cout << ans;
	return 0;
}
