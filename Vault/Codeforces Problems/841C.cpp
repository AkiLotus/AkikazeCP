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
	ll m; cin >> m;
	vector<ii> a(m), b(m);
	vector<ll> ans(m);
	for (ll i=0; i<m; i++) {
		cin >> a[i].fi; a[i].se = i;
	}
	for (ll i=0; i<m; i++) {
		cin >> b[i].fi; b[i].se = i;
	}
	sort (a.begin(), a.end());
	sort (b.begin(), b.end());
	for (ll i=0; i<m; i++) {
		ans[b[i].se] = a[m-1-i].fi;
	}
	for (ll i=0; i<m; i++) cout << ans[i] << " ";
	return 0;
}

