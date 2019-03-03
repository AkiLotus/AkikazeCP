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
	ll n, k; cin >> n >> k;
	vector<ll> a(n);
	ll ans = MOD;
	for (ll i=0; i<n; i++) {
		cin >> a[i];
		if (k % a[i] == 0) ans = min(ans,k / a[i]);
	}
	cout << ans;
	return 0;
}

