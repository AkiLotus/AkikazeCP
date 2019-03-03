#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, l, r; vector<int> cnt(3, 0);
const int Mod = 1000000007;

void Input() {
	cin >> n >> l >> r;
}

void Solve() {
	for (int i=0; i<3; i++) {
        int Min = ((l / 3) - 1) * 3 + i;
        while (Min < l) Min += 3;
        int Max = ((r / 3) + 1) * 3 + i;
        while (r < Max) Max -= 3;
        cnt[i] = (Max - Min) / 3 + 1;
    }
    vector<vector<long long>> dp(n, vector<long long>(3, 0));
    dp[0][0] = cnt[0]; dp[0][1] = cnt[1]; dp[0][2] = cnt[2];
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<3; j++) {
            for (int x=0; x<3; x++) {
                dp[i+1][(j+x) % 3] += dp[i][j] * cnt[x];
                dp[i+1][(j+x) % 3] %= Mod;
            }
        }
    }
    cout << dp[n-1][0] << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/