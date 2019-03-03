#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define MOD 1000000007
using namespace std;

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	ll N, S;
	while (cin >> N) {
		cin >> S;
		vector<ll> a(N);
		for (ll i=0; i<N; i++) cin >> a[i];
		ll ans = N, tmp = 1, pos = 0, sum = a[0];
		for (ll i=1; i<N; i++) {
			sum += a[i]; tmp++;
			if (sum >= S) ans = min(ans, tmp);
			while (pos < i && sum >= S) {
				tmp--; sum -= a[pos]; pos++;
				if (sum >= S) ans = min(ans, tmp);
			}
		}
		if (sum >= S) ans = min(ans, tmp);
		cout << ans << endl;
	}
	return 0;
}

