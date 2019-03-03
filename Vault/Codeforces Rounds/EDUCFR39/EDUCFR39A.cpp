/**************************************************
* Code written by Thuy-Trang Tran (thuytrang12a2) *
**************************************************/

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
	ll n; cin >> n; vector<ll> a(n, 0);
	for (ll i=0; i<n; i++) cin >> a[i];
	ll ans = 0;
	for (ll i=0; i<n; i++) ans += abs(a[i]);
	cout << ans;
	return 0;
}
