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
	map<ii, bool> M;
	vector<bool> isPrime(100009, true); isPrime[0] = false; isPrime[1] = false;
	for (ll i=2; i<100009; i++) {
		if (isPrime[i]) {
			for (ll j=2; j<=100008/i; j++) isPrime[i*j] = false;
		}
	}
	ll n, m; cin >> n >> m;
	for (ll i=1; i<n; i++) M[mp(i, i+1)] = true;
	ll ans = n-1;
	while (!isPrime[ans]) ans++;
	cout << ans << " " << ans << endl;
	for (ll i=1; i<n-1; i++) cout << i << " " << i+1 << " " << 1 << endl;
	cout << n-1 << " " << n << " " << ans-n+2 << endl;
	ll cc = 0;
	for (ll x=1; x<n; x++) {
		for (ll y=x+1; y<=n; y++) {
			if (cc == m-n+1) return 0;
			if (M[mp(x,y)]) continue;
			cout << x << " " << y << " " << 100000000LL << endl; cc++;
			if (cc == m-n+1) return 0;
		}
	}
	return 0;
}

