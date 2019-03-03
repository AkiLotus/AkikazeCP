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
	int x, h, m; cin >> x >> h >> m;
	for (ll i=0; i<3600; i++) {
		if (h % 10 == 7 || m % 10 == 7) {
			cout << i; return 0;
		}
		m -= x;
		if (m < 0) {
			m += 60; h--;
			if (h < 0) h += 24;
		}
	}
	return 0;
}

