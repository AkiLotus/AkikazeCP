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
	ll n; cin >> n; vector<ll> a(n);
	ll sqr = 0, notsqr = 0, zero = 0;
	vector<ll> nonsqr;
	for (ll i=0; i<n; i++) {
		cin >> a[i];
		ll tmp = sqrt(a[i]);
		if (tmp * tmp == a[i]) {
			sqr++; if (tmp == 0) zero++;
		}
		else {
			notsqr++;
			nonsqr.push_back(min((tmp+1)*(tmp+1) - a[i], a[i] - tmp*tmp));
		}
	}
	if (sqr == notsqr) cout << 0;
	else if (sqr > notsqr) {
		if (sqr - zero > (sqr - notsqr) / 2) cout << (sqr - notsqr) / 2;
		else cout << (sqr - zero) + 2 * ((sqr - notsqr) / 2 - (sqr - zero));
	}
	else {
		sort(nonsqr.begin(), nonsqr.end());
		ll ans = 0;
		for (ll i=0; i<(notsqr - sqr) / 2; i++) {
			ans += nonsqr[i];
		}
		cout << ans;
	}
	return 0;
}

