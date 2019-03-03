#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000001
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
		int N; cin >> N; vector<int> a(N);
		for (int i=0; i<N; i++) cin >> a[i];
		sort(a.begin(), a.end());
		int tmp = 1, ans = 1e9;
		if (N == 0) ans = 0;
		for (int i=1; i<N; i++) {
			if (a[i] - a[i-1] == 1) tmp++;
			else {
				ans = min(ans, tmp);
				tmp = 1;
			}
		}
		ans = min(ans, tmp);
		cout << ans << endl;
    }
    return 0;
}
