#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	freopen("english-dict-nonalpha", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll n, ans = 0, mx = 0, cnt = 0; string s;
	while (cin >> s) {
	    ans += s.size(); cnt++;
	    mx = max(mx, (long long)s.size());
	}
	cout << "Total characters: " << ans << endl;
	cout << "Word counts: " << cnt << endl;
	cout << "Maximum characters: " << mx << endl;
}