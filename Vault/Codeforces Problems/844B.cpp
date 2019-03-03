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

vector<ll> pow2(55, 1);

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	for (ll i=1; i<55; i++) pow2[i] = pow2[i-1] * 2;
	ll n, m; cin >> n >> m;
	vector<vector<ll>> a(n, vector<ll>(m));
	vector<ll> r(n), c(m);
	ll ans = 0;
	for (ll i=0; i<n; i++) {
		for (ll j=0; j<m; j++) {
			cin >> a[i][j];
			r[i] += a[i][j];
			c[j] += a[i][j];
		}
	}
	for (ll i=0; i<n; i++) {
		ans += pow2[r[i]] - 1;
		ans += pow2[m - r[i]]- 1;
	}
	for (ll i=0; i<m; i++) {
		ans += pow2[c[i]] - 1;
		ans += pow2[n - c[i]]- 1;
	}
	cout << ans - m * n;
	return 0;
}

