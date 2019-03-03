/**************************************************
* Code written by Thuy-Trang Tran (thuytrang12a2) *
**************************************************/

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
	ll n, x, y; cin >> n >> x >> y;
	vector<ii> cc(1000007);
	for (ll i=0; i<1000007; i++) cc[i].se = i;
	vector<ll> a(n);
	for (ll i=0; i<n; i++) {
		cin >> a[i]; ll tmp = a[i];
		for (ll i=2; i<=sqrt(tmp); i++) {
			if (tmp % i == 0) {
				cc[i].fi++;
				while (tmp % i == 0) tmp /= i;
			}
		}
		if (tmp != 1) cc[tmp].fi++;
	}
	sort(cc.begin(), cc.end(), greater<ii>());
	ll ans = 1e18;
	for (ll i=0; i<cc.size(); i++) {
		if ((n - cc[i].fi) * min(x, y) >= ans) break;
		ll tmp = 0;
		for (ll j=0; j<n; j++) {
			if (a[j] % cc[i].se == 0) continue;
			tmp += min(x, y*(cc[i].se - a[j] % cc[i].se));
		}
		ans = min(ans, tmp);
	}
	cout << ans;
	return 0;
}

