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
	ll n, pos, l, r; cin >> n >> pos >> l >> r;
	if (l != 1 && r != n) {
		if (l <= pos && pos <= r) cout << min(r-l+pos-l, r-l+r-pos) + 2;
		else if (pos < l) cout << (r - pos) + 2;
		else cout << (pos - l) + 2;
	}
	else if (l == 1 && r != n) {
		cout << abs(pos - r) + 1;
	}
	else if (l != 1 && r == n) {
		cout << abs(pos - l) + 1;
	}
	else if (l == 1 && r == n) cout << 0;
	return 0;
}

