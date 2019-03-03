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
	ll n; cin >> n;
	vector<ll> a(n), b(n), c(n), d(n), e(n);
	vector<ll> ans;
	for (ll i=0; i<n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
	}
	for (ll i=0; i<n; i++) {
		bool valid = true;
		for (ll j=0; j<n; j++) {
			if (!valid) break;
			if (i == j) continue;
			ll xa = a[j] - a[i], xb = b[j] - b[i], xc = c[j] - c[i], xd = d[j] - d[i], xe = e[j] - e[i];
			for (ll k=0; k<n; k++) {
				if (!valid) break;
				if (i == k || j == k) continue;
				ll ya = a[k] - a[i], yb = b[k] - b[i], yc = c[k] - c[i], yd = d[k] - d[i], ye = e[k] - e[i];
				if (xa*ya + xb*yb + xc*yc + xd*yd + xe*ye > 0) {
					valid = false; break;
				}
			}
		}
		if (valid) ans.push_back(i+1);
	}
	cout << ans.size() << endl;
	for (ll i=0; i<ans.size(); i++) cout << ans[i] << endl;
	return 0;
}

