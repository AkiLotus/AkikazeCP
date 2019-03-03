#include <iostream>
using namespace std;

int N;
int dp[32][32];
int a[32];
int answer;

int calculate(int ite, int sum) {
    if (ite == N-1) return sum+1;
    int res = 0;
    for (int i=0; i<=sum; i++) {
        res += calculate(ite+1, sum-i);
    }
    for (int i=a[ite]+1; i<=sum; i++) {
        res -= calculate(ite+1, sum-i);
        res += calculate(ite+1, sum-i-1);
    }
    return res;
}

int main() {
	int cas = 0;
	cin >> N;
	while (N != 0) {
        cas++;
        for (int i=0; i<32; i++) {
            for (int j=0; j<32; j++) dp[i][j] = -1;
        }
        int sum = 0;
        answer = 0;
        for (int i=0; i<N; i++) {
                cin >> a[i];
                sum += a[i];
        }
        answer = calculate(0, sum);
        cout << "Case " << cas << ": " << answer << endl;
        cin >> N;
	}
	return 0;
}
