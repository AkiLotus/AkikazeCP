#include <iostream>
#include <stack>
using namespace std;

int main() {
	int M, N;
	cin >> M >> N;
	int matrix[M][N];
	int layer[M][N];
	for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            cin >> matrix[i][j];
            if (i == 0) layer[i][j] = matrix[i][j];
            else {
                if (matrix[i][j] == 0) layer[i][j] = 0;
                else layer[i][j] = layer[i-1][j] + 1;
            }
        }
	}
	int ans = 0;
	for (int i=0; i<M; i++) {
        int left[N], right[N];
        stack<int> S;
        for (int j=0; j<N; j++) {
            while (!S.empty() && layer[i][S.top()] >= layer[i][j]) S.pop();
            if (S.empty()) left[j] = -1;
            else left[j] = S.top();
            S.push(j);
        }
        while (!S.empty()) S.pop();
        for (int j=N-1; j>=0; j--) {
            while (!S.empty() && layer[i][S.top()] >= layer[i][j]) S.pop();
            if (S.empty()) right[j] = N;
            else right[j] = S.top();
            S.push(j);
        }
        for (int j=0; j<N; j++) {
            ans = max(ans, (right[j]-left[j]-1)*layer[i][j]);
        }
	}
	cout << ans;
	return 0;
}
