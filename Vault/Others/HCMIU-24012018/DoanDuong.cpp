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
	ll n, sum = 0; cin >> n; vector<ll> a(n);
	for (ll i=0; i<n; i++) {
		cin >> a[i]; sum += a[i];
	}
	ll l = 0, r = n-1;
	while (sum < 0) {
		if (a[l] < a[r]) {
			sum -= a[l]; l++;
		}
		else {
			sum -= a[r]; r--;
		}
	}
	cout << l+1 << " " << r+1;
	return 0;
}

