#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int s[n];
	int dp[2][n];
	for (int i=0; i<n; i++) {
        dp[0][i] = 0; dp[1][i] = 0;
	}
	for (int i=0; i<n; i++) {
        cin >> s[i];
        if (s[i] == 1) {
            for (int j=i; j>=0; j--) dp[1][j]++;
        }
        else {
            for (int j =i; j<n; j++) dp[0][j]++;
        }
	}
	int answer = dp[0][0] + dp[1][0];
	for (int i=0; i<n; i++) {
        answer = max(answer, dp[0][i]+dp[1][i]);
	}
	cout << answer;
	return 0;
}
