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
	ll n, a, b; string s; cin >> n >> a >> b >> s;
	ll ans = 0, tmp = 0;
	for (ll i=0; i<=n; i++) {
		if (i == n || (i != n && s[i] == '*')) {
			ll q = tmp / 2, r = tmp % 2;
			if (max(a, b) < q || (max(a, b) == q && r == 0)) {
				ans += a; ans += b; a = 0; b = 0;
			}
			else {
				if (a > b) {
					int x = min(q+r, a), y = min(q, b);
					ans += (x + y);
					a -= x; b -= y;
				}
				else {
					int x = min(q+r, b), y = min(q, a);
					ans += (x + y);
					b -= x; a -= y;
				}
			}
			tmp = 0;
		}
		else tmp++;
	}
	cout << ans;
	return 0;
}
