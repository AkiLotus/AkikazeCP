#include <iostream>
using namespace std;
// incompleted
int main() {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    long long b2[n];
    long long b5[n];
    long long tmp2[n];
    long long tmp5[n];
    long long round[n];
    long long dp[n];
    for (int i=0; i<n; i++) {
        cin >> a[i]; b2[i] = 0; b5[i] = 0;
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            b2[i]++;
        }
        while (a[i] % 5 == 0) {
            a[i] /= 2;
            b5[i]++;
        }
        tmp2[i] = b2[i]; tmp5[i] = b5[i];
        round[i] = min(tmp2[i], tmp5[i]);
        dp[i] = 1;
    }
    for (int i=0; i<n; i++) {
        if (dp[i] == k) continue;
        for (int j=0; j<i; j++) {
            if (dp[j] == k) continue;
            if ()
        }
    }
    return 0;
}
