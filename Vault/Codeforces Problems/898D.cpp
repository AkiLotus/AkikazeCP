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

ll k, n, m, res = 0;
vector<ll> mnt(1000007, 0);

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m >> k;
	for (ll i=0; i<n; i++) {
		ll a; cin >> a; mnt[a]++;
	}
	ll curr = 0;
	for (ll i=0; i<1000007; i++) {
		curr += mnt[i];
		if (i >= m) curr -= mnt[i-m];
		if (curr >= k) {
			curr--; mnt[i]--;  res++;
		}
	}
	cout << res;
	return 0;
}

