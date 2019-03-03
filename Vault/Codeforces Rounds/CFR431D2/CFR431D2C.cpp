#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int dp[448]; dp[0] = 0;
	int cc[26];
	for (int i=1; i<448; i++) dp[i] = i * (i - 1) / 2;
	for (int i=0; i<26; i++) cc[i] = 0;
	int k;
	cin >> k;
	if (k == 0) cout << "a";
	else {
        int working = 0;
        while (k > 0) {
            int tmp = upper_bound(dp, dp+448, k) - dp - 1;
            cc[working] = tmp;
            k -= dp[tmp];
            working++;
        }
        string ans = "";
        for (int i=0; i<26; i++) {
            for (int j=0; j<cc[i]; j++) ans += ('a' + i);
        }
        cout << ans;
	}
	return 0;
}
