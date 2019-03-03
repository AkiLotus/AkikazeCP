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
	ll a, b, ans = 0; cin >> a >> b;
	while (a > 0 && b > 0) {
		if (a >= 2 * b) {
			ans += a / (2 * b);
			a %= (2 * b);
		}
		else if (b >= 2 * a) {
			ans += b / (2 * a);
			b %= (2 * a);
		}
		else break;
	}
	cout << a << " " << b;
	return 0;
}

