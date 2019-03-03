// Code written by JadeMasochist

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
	ll w, l; cin >> w >> l; vector<ll> a(w);
	for (ll i=1; i<w; i++) cin >> a[i];
	ll ans = 1e18, slideWin = 0;
	for (ll i=1; i<=l; i++) slideWin += a[i];
	for (ll i=1; i<=w-l; i++) {
		ans = min(ans, slideWin);
		if (i == w-l) continue;
		slideWin -= a[i]; slideWin += a[i+l];
	}
	cout << ans;
	return 0;
}