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
	ll l = -1, r = -1;
	vector<ll> a(n+1), s(n+1, 0);
	for (ll i=1; i<=n; i++) {
		cin >> a[i]; s[i] = s[i-1] + a[i];
	}
	map<ll, ll> M;
	for (ll i=1; i<=n; i++) {
		if (s[i] == 0) {
			if (i > r - l) {
				l = 1; r = i;
			}
			continue;
		}
		if (M[s[i]] != 0) {
			if ((r - l < i - M[s[i]] - 1) || (r == -1 && l == -1)) {
				l = M[s[i]] + 1; r = i;
			}
		}
		else M[s[i]] = i;
	}
	cout << l << " " << r;
	return 0;
}

