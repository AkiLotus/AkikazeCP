#include <iostream>
using namespace std;

int main() {
	char board[10][10];
	for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) cin >> board[i][j];
	}
	bool valid = false;
	while (true) {
        for (int i=0; i<10; i++) {
            for (int j=0; j<6; j++) {
                int friendly = 0;
                bool space = false;
                for (int k=0; k<5; k++) {
                    if (board[i][j+k] == 'X') friendly++;
                    else if (board[i][j+k] == '.') space = true;
                }
                if (friendly == 4 && space) {
                    valid = true;
                    break;
                }
            }
            if (valid) break;
        }
        if (valid) break;
        for (int i=0; i<10; i++) {
            for (int j=0; j<6; j++) {
                int friendly = 0;
                bool space = false;
                for (int k=0; k<5; k++) {
                    if (board[j+k][i] == 'X') friendly++;
                    else if (board[j+k][i] == '.') space = true;
                }
                if (friendly == 4 && space) {
                    valid = true;
                    break;
                }
            }
            if (valid) break;
        }
        if (valid) break;
        for (int i=0; i<6; i++) {
            for (int j=0; j<6; j++) {
                int friendly = 0;
                bool space = false;
                for (int k=0; k<5; k++) {
                    if (board[i+k][j+k] == 'X') friendly++;
                    else if (board[i+k][j+k] == '.') space = true;
                }
                if (friendly == 4 && space) {
                    valid = true;
                    break;
                }
            }
            if (valid) break;
        }
        if (valid) break;
        for (int i=0; i<6; i++) {
            for (int j=4; j<10; j++) {
                int friendly = 0;
                bool space = false;
                for (int k=0; k<5; k++) {
                    if (board[i+k][j-k] == 'X') friendly++;
                    else if (board[i+k][j-k] == '.') space = true;
                }
                if (friendly == 4 && space) {
                    valid = true;
                    break;
                }
            }
            if (valid) break;
        }
        break;
	}
	if (valid) cout << "YES"; else cout << "NO";
	return 0;
}
