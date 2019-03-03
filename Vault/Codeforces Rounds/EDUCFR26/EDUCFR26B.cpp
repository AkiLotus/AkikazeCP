#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char a[n][m];
    int b[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'R') b[i][j] = 0;
            else if (a[i][j] == 'G') b[i][j] = 1;
            else if (a[i][j] == 'B') b[i][j] = 2;
        }
    }
    if (n % 3 != 0 && m % 3 != 0) {
        cout << "NO";
    }
    else {
        int col[4] = {-1, -1, -1, 0};
        if (n % 3 == 0) {
            for (int i=0; i<3; i++) {
                for (int j=0; j<n/3; j++) {
                    for (int k=0; k<m; k++) {
                        if (col[i] == -1) {
                            col[i] = b[i*n/3+j][k];
                        }
                        else if (col[i] != b[i*n/3+j][k]) {
                            for (int q=0; q<4; q++) col[q] = -1;
                            break;
                        }
                    }
                    if (col[3] == -1) break;
                }
                if (col[3] == -1) break;
            }
        }
        else col[3] = -1;
        if (col[3] == 0 && col[0] != col[1] && col[1] != col[2] && col[2] != col[0]) {
            cout << "YES";
        }
        else {
            col[3] = 0;
            if (m % 3 == 0) {
                for (int i=0; i<3; i++) {
                    for (int j=0; j<n; j++) {
                        for (int k=0; k<m/3; k++) {
                            if (col[i] == -1) {
                                col[i] = b[j][i*m/3+k];
                            }
                            else if (col[i] != b[j][i*m/3+k]) {
                                for (int q=0; q<4; q++) col[q] = -1;
                                break;
                            }
                        }
                        if (col[3] == -1) break;
                    }
                    if (col[3] == -1) break;
                }
            }
            else col[3] = -1;
            if (col[3] == 0 && col[0] != col[1] && col[1] != col[2] && col[2] != col[0]) cout << "YES";
            else cout << "NO";
        }
    }
    return 0;
}
