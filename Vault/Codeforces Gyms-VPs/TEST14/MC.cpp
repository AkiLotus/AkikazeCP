#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define MOD 1000000007
using namespace std;
const int N = 1e6 +5;

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	ll n; cin >> n;
	vector<string> a(n);
	vector<pii> cc(10);
	vector<ll> val(10, -1);
	vector<bool> lead(10, false);
	for (ll i=0; i<10; i++) {
		cc[i].se = i;
	}
	for (ll i=0; i<n; i++) {
		cin >> a[i];
		lead[a[i][0]-'a'] = true;
		ll pow10 = 1;
		for (ll j = a[i].size()-1; j>=0; j--) {
			cc[a[i][j]-'a'].fi += pow10;
			pow10 *= 10;
		}
	}
	sort(cc.begin(), cc.end(), greater<pii>());
	for (ll i=0; i<10; i++) {
		if (lead[cc[i].se]) continue;
		val[cc[i].se] = 0; break;
	}
	ll working = 1, res = 0;
	for (ll i=0; i<10; i++) {
		if (val[cc[i].se] >= 0) continue;
		val[cc[i].se] = working;
		res += working * cc[i].fi;
		working++;
	}
	cout << res;
	return 0;
}

